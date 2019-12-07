#include<bits/stdc++.h>
using namespace std;
struct node{
	bool isleaf;
	map<char, node*> hash;
};
void insert(node* &head, string word){
	node* temp = head;
	for(int i=0; i<word.size(); i++){
		char x = word[i];
		if(temp->hash.find(x) == temp->hash.end()){
			node* temp1 = new node();
			temp1->isleaf = false;
			temp->hash[x] = temp1;
		}
		temp = temp->hash[x];
	}
	temp->isleaf = true;
}
vector<string> ans;
void dfs(node *head, string curr){
	if(head->isleaf){
	    ans.push_back(curr);
// 		cout<<endl;
// 		return;
	}
	map<char, node*> m = head->hash;
	for(auto it=m.begin(); it!=m.end(); it++){
		curr.push_back(it->first);
		dfs(it->second, curr);
		curr.pop_back();
	}
	return;
}
int main(){
	// int n;
	// cin>>n;
	node* head = new node();
	vector<string> A = { "the", "a", "there", "answer", 
                       "any", "by", "bye", "their" };
	for(int i=0; i<A.size(); i++){
		// cin>>A[i];
		cout<<"i = "<<i<<endl;
		insert(head, A[i]);
	}
	ans.clear();
	string curr = "";
	dfs(head, curr);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
	return 0;
}