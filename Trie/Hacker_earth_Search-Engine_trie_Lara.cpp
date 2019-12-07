#include<bits/stdc++.h>
using namespace std;
struct Node{
    bool isleaf;
    map<char, Node*> hash;
    vector<int> wt;
    int wtend;
    Node(){
        isleaf = false;
        wt.clear();
        wt.resize(26, 0);
    }
};
void insert(Node* &head, string &word, int w){
    Node* temp = head;
    for(int i=0; i<word.size(); i++){
        char x = word[i];
        if(temp->hash.find(x) == temp->hash.end()){
            // Node* temp1 = new Node();
            temp->hash[x] = new Node();
        }
        temp->wt[x - 'a'] = max(w, temp->wt[x - 'a']);
        temp = temp->hash[x];
        // temp->wt = max(temp->wt, w);
    }
    temp->wtend = w;
    temp->isleaf = true;
    return;
}
int func(Node* head, string &t){
    Node* temp = head;
    for(int i=0; i<t.size(); i++){
        char x = t[i];
        if(temp->hash.find(x) == temp->hash.end()){
            return -1;
        }
        temp = temp->hash[x];
    }
    int maxm = 0;
    while(true){
        maxm = 0;
        for(int i=0; i<26; i++){
            maxm = max(temp->wt[i], maxm);
        }
        if(maxm <= temp->wtend){
            return temp->wtend;
        }
    }
    return -1;
}
int main(){
    int n, q;
    cin>>n>>q;
    vector<string> A(n);
    Node* head = new Node();
    for(int i=0; i<n; i++){
        cin>>A[i];
        int wt;
        cin>>wt;
        insert(head, A[i], wt);
    }
    while(q--){
        string t;
        cin>>t;
        int ans = func(head, t);
        cout<<ans<<endl;
    }
    return 0;
}