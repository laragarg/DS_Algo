#include <bits/stdc++.h>
using namespace std;

//REFER TUSHAR ROY VIDEO FOR VISUALIZATION : 
struct Trie
{
    bool isleaf;
    map <char,Trie*> hashmap;
};


Trie* getNew()
{
    Trie* node=new Trie();
    node->isleaf=false;
    return node;
}


void insert(Trie* &head,string key)
{
    if(head == NULL)
        head=getNew();
    Trie* temp=head;
    for(int i=0;i<key.length();i++)
    {
        if(temp->hashmap[key[i]] == NULL)
        {
            temp->hashmap[key[i]]=getNew();
        }
        temp=temp->hashmap[key[i]];
    }
    temp->isleaf=true;
}

bool search(Trie* &head,string key)
{
    if(head == NULL)
         return false;
    Trie* temp=head;
    for(int i=0;i<key.length();i++)
    {
        temp=temp->hashmap[key[i]];
        if(temp == NULL)
             return false; 
    } 
    return temp->isleaf ; 
}


//LONGEST COMMON PREFIX
string lcp(Trie* &head)
{
    string ans="";  
    Trie* temp=head;
    while(temp && temp->isleaf == false)
    {
        map <char,Trie*> tmap=temp->hashmap;
        if(tmap.size() != 1)
             return ans;
        auto it=temp->hashmap.begin();
        ans+=it->first;
        temp=temp->hashmap[it->first];
    }
    return ans;
}


//WORD BREAK 
bool wordbreak(string str,Trie* &head)
{
    int n = str.length();
    if(n == 0) return true;
    for(int i=0;i<=n;i++)
    {
        if(search(head,str.substr(0,i)) && wordbreak(str.substr(i,n-i),head))
            return true;
    }
    return false;
}


int main()
{
    Trie* head = nullptr;

    insert(head, "hello");
    cout << search(head, "hello") << " ";       // print 1

    insert(head, "helloworld");
    cout << search(head, "helloworld") << " ";  // print 1

    cout << search(head, "helll") << " ";       // print 0 (Not present)

    insert(head, "hell");
    cout << search(head, "hell") << " ";        // print 1

         string dictionary[] = {"mobile","samsung","sam", 
                               "sung","ma\n","mango", 
                               "icecream","and","go","i", 
                               "like","ice","cream"}; 
                           int n = sizeof(dictionary)/sizeof(dictionary[0]); 
     for(int i=0;i<n;i++)
     {
        insert(head,dictionary[i]);
     }                      
     wordbreak("ilikesamsung", head)? cout <<"Yes\n": cout << "No\n"; 
    string ans=lcp(head);
    cout<<ans<<endl;
    return 0;
}