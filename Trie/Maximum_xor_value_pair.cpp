#include<bits/stdc++.h>
using namespace std;
#define INT_SIZE 32
struct Node{
	int data;
	vector<Node*> child;
	// map<char, Node*>hash;
	Node(){
		data = 0;
		child.clear();
		child.resize(2, NULL);
		// child[0] = NULL;
		// child[1] = NULL;
	}
};
void insert(Node* &root, int value){
	Node* temp = root;
	for(int i=INT_SIZE-1; i>=0; i--){
		bool curr_bit = value & (1 << i);
		if(!temp->child[curr_bit]){
			temp->child[curr_bit] = new Node();
		}
		temp = temp->child[curr_bit];
	}
	temp->data = value;
}
int func(Node* root, int value){
	Node* temp = root;
	for(int i=INT_SIZE-1; i>=0; i--){
		bool curr_bit = value & (1 << i);
		if(temp->child[1 - curr_bit]){
			temp = temp->child[1 - curr_bit];
		}
		else if(temp->child[curr_bit]){
			temp = temp->child[curr_bit];
		}
	}
	return value ^ temp->data;
}
int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	// A.clear();
	// A.resize(n);
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	int ans = INT_MAX;
	Node* root = new Node();
	insert(root, A[0]);
	for(int i=1; i<n; i++){
		ans = max(ans, func(root, A[i]));
		insert(root, A[i]);
	}
	cout<<"ans = "<<ans<<endl;
	return 0;
}