#include<bits/stdc++.h>
using namespace std;
struct Node{
	map<char, Node*> hash;
	bool isleaf;
	Node(){
		isleaf = false;
	}
};
void insert(Node* &head, string word, string matlab){
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
void dfs(Node* head, int &count){
	for(auto it = head->hash.begin(); it != head->hash.end(); it++){
		count++;
		dfs(head->hash[it->first], count);
	}
	return;
}
int main(){
	string s;
	cin>>s;
	Node* head = new Node();
	int n = s.size();
	for(int i=n-1; i>=0; i--){
		string word = s.substr(i, n-i);
		insert(head, word);
	}
	int count = 0;
	dfs(head, count);
	count++;
	cout<<count<<endl;
	return 0;
}