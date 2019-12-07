#include <bits/stdc++.h> 
using namespace std; 
  
const int ALPHABET_SIZE = 26; 
  
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE];
    int wt[ALPHABET_SIZE];
    bool isEndOfWord; 
    int wt_end;
}; 

struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
    pNode->isEndOfWord = false; 
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = NULL; 
        pNode->wt[i] = 0;
    }
    return pNode; 
} 

void insert(struct TrieNode *root, string key, int weight) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
        pCrawl->wt[index] = max(weight, pCrawl->wt[index]);
        pCrawl = pCrawl->children[index];
    } 
  
    pCrawl->isEndOfWord = true; 
    pCrawl->wt_end = weight;
} 

int search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return -1; 
  
        pCrawl = pCrawl->children[index]; 
    }
    int m = 0; 
    while(true) 
    { 
        m=0;
        for(int i =0; i<26; i++) {
            m = max(pCrawl->wt[i], m);
        }
        if(m<=pCrawl->wt_end) {
            return pCrawl->wt_end;
        }
        for(int i =0; i<26; i++) {
            if(m==pCrawl->wt[i]) {
                pCrawl = pCrawl->children[i]; 
                break;
            }
        }
        
    }
    return -1; 
} 

int main() 
{ 
    int n,q;
    cin>>n>>q;
    struct TrieNode *root = getNode(); 
    for(int i=0;i<n;i++){
        string key;
        int weight;
        cin>>key>>weight;
        insert(root, key, weight); 
    }
    for (int i = 0; i < q; i++) 
    {
        string query;
        cin>>query;
        cout<<search(root, query)<<"\n";
    }
    return 0; 
} 

  