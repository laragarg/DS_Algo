//Required number of nodes to store n strings

#include <bits/stdc++.h>
using namespace std;

struct Trie{
    bool isleaf;
    map <char, Trie*> hashmap;
};
Trie* getnew(){
    Trie* node = new Trie();
    node->isleaf = true;
    return node;
}
void insert(Trie* &head,string key,int &count){
    if(head == NULL){
        head = getnew();
    }
    Trie* temp = head;
    for(int i=0;i<key.length();i++){
        if(temp->hashmap[key[i]] == NULL){
            temp->hashmap[key[i]] = getnew();
            count++;
        }
        temp = temp->hashmap[key[i]];
    }
    temp->isleaf = true;
}
int main(){
    Trie* head = nullptr;
    int n;
    cin>>n;
    int count = 0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        insert(head,s,count);
    }
    cout<<count+1<<endl;
}