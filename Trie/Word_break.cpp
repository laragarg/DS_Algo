//KP
//Word Break
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
    bool isleaf;
    map<char, Node*> hash;
    Node(){
        isleaf = false;
    }
};
void insert(Node* &head, string word){
    Node* temp = head;
    for(int i=0; i<word.size(); i++){
        char x = word[i];
        if(temp->hash.find(x) == temp->hash.end()){
            temp->hash[x] = new Node();
        }
        temp = temp->hash[x];
    }
    temp->isleaf = true;
    return;
}
bool search(Node* head, string word){
    Node* temp = head;
    for(int i=0; i<word.size(); i++){
        char x = word[i];
        if(temp->hash.find(x) == temp->hash.end()){
            return false;
        }
        temp = temp->hash[x];
    }
    return temp->isleaf == true ? true : false;
}
// int n;
bool check(Node* head, vector<string> &A, string s){
    int n = s.size();
    if(n == 0){
        // cout<<"here"<<endl;
        return true;
    }
    // cout<<"s = "<<s<<endl;
    for(int i=1; i<=n; i++){
        string pre = s.substr(0, i);
        string suff = s.substr(i, n-i);
        if(search(head, pre) && check(head, A, suff)){
            return true;
        }
    }
    return false;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> A(n);
        Node* head = new Node();
        for(int i=0; i<n; i++){
            cin>>A[i];
            insert(head, A[i]);
        }
        string s;
        cin>>s;
        if(n == 0){
            cout<<0<<endl;
            continue;
        }
        if(check(head, A, s)){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}

/*
1
10
a aa aaa aaaa aaaaa aaaaaa aaaaaaa aaaaaaaa aaaaaaaaa aaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaab //TLE on adding one more a in the string
*/