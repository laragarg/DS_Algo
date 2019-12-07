//Check if a given array can represent Preorder Traversal of Binary Search Tree

//CORE LOGIC -> for any value in the array if there is a smaller value
//after next greater element in the array then it can't represent the preorder traversal
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0; i<n; i++){
		cin>>A[i];
	}

	//find next greater element for every element in the array
	stack<int> st;
	vector<int> ng(n);
	ng[n-1] = -1;
	st.push(A[n-1]);

	vector<int> minm(n);//to store the minimum from right till the ith index
	minm[n-1] = A[n-1];

	for(int i=n-2; i>=0; i--){
		int a = A[i];
		while(!st.empty() && a > A[st.top()]){
			st.pop();
		}
		if(st.empty()){
			ng[i] = -1;
		}
		else{
			ng[i] = st.top();
		}
		st.push(i);

		minm[i] = min(minm[i+1], A[i]);
	}
	for(int i=0; i<n-1; i++){
		int ngi = ng[i];
		if(i != -1 && minm[ngi] < A[i]){
			cout<<"False"<<endl;
			return 0;
		}
	}
	cout<<"True"<<endl;
	return 0;
}

//GFG
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	stack<int> st;
	int root = INT_MIN;
	for(int i=0; i<n; i++){
		int a = A[i];
		if(a < root){
			return false;
		}
		while(!st.empty() && a > st.top()){
			root = st.top();
			st.pop();
		}
		st.push(a);
	}
	return true;
}