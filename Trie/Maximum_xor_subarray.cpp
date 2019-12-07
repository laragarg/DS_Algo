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
void insert(Node* &root, int prefix_xor){
	Node* temp = root;
	for(int i=INT_SIZE-1; i>=0; i--){
		bool curr_bit = prefix_xor & (1 << i);
		if(!temp->child[curr_bit]){
			temp->child[curr_bit] = new Node();
		}
		temp = temp->child[curr_bit];
	}
	temp->data = prefix_xor;
}
int func(Node* root, int prefix_xor){
	Node* temp = root;
	for(int i=INT_SIZE-1; i>=0; i--){
		bool curr_bit = prefix_xor & (1 << i);
		if(temp->child[1 - curr_bit]){ //check for opposite bit first
			temp = temp->child[1 - curr_bit];
		}
		else if(temp->child[curr_bit]){
			temp = temp->child[curr_bit];
		}
	}
	return prefix_xor ^ temp->data;
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
	int ans = INT_MIN;
	Node* root = new Node();
	insert(root, 0);
	int prefix_xor = 0;
	for(int i=0; i<n; i++){
		// ans = min(ans, func(root, A[i]));
		// insert(root, A[i]);
		prefix_xor = prefix_xor ^ A[i];
		insert(root, prefix_xor);
		ans = max(ans, func(root, prefix_xor));
	}
	cout<<"ans = "<<ans<<endl;
	return 0;
}