#include<bits/stdc++.h>
using namespace std;
struct Node{
	// char x;
	// char data;
	map<char, Node*> hash;
	bool isLeaf;
	string meaning;
	Node(){
		isLeaf = false;
	}
};

string search(Node* head, string word){
// 	string ans = "";
	Node* temp = head;
	for(int i=0; i<word.size(); i++){
		char x = word[i];
		map<char, Node*> m = temp->hash;
		if(m.find(x) == m.end()){
			return "WordNotFound";
		}
		temp = m[x];
	}
	if(temp->isLeaf){
		return temp->meaning;
	}
	else{
		return "WordNotFound";
	}
}
void insert(Node* &head, string word, string matlab){
	Node* temp = head;
	for(int i=0; i<word.size(); i++){
		char x = word[i];
		map<char, Node*> m = temp->hash;
		if(m.find(x) == m.end()){
			Node* temp1 = new Node();
			m[x] = temp1;
			temp->hash = m;
			// cout<<x<<endl;
		}
		// cout<<m[x]<<endl;
		temp = m[x];
	}
	temp->meaning = matlab;
	temp->isLeaf = true;
}
int main(){
	Node* head = new Node();
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		string word, matlab;
    	cin>>word;
		cin.ignore();
    	getline(cin, matlab);
    	insert(head, word, matlab);
	}
	int q;
	cin>>q;
	for(int i=0; i<q; i++){
    	string word;
    	cin>>word;
    	string ans = search(head, word);
    	cout<<ans<<endl;
	}
	return 0;
}
/* Test Case
5
language
the method of human communication
computer
a machine
map
a diagramatic representation
book
a written or printed work 
science
the intellectual and practical
3
computer
map
knowledge
*/