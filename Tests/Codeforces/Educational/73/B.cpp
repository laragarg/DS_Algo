#include<bits/stdc++.h>
using namespace std;
vector<vector<char> > A;
char x;
void dfs(int i, int j){
	int n = A.size();
	if(i < 0 ||i >= n || j < 0 || j >= n){
		return;
	}
	if(A[i][j] != '0'){
		return;
	}
	if(i == 0 && j == 0){
		A[i][j] = 'W';
		x = 'W';
	}
	else if(x == 'W'){
		A[i][j] = 'B';
		x = 'B';
	}
	else if(x == 'B'){
		A[i][j] = 'W';
		x = 'W';
	}
	dfs(i+2, j+1);
	dfs(i+2, j-1);
	dfs(i-2, j+1);
	dfs(i-2, j-1);
	dfs(i+1, j+2);
	dfs(i+1, j-2);
	dfs(i-1, j+2);
	dfs(i-1, j-2);
	return;
}
int main(){
	int n;
	cin>>n;
	A.clear();
	A.resize(n, vector<char>(n, '0'));
	dfs(0, 0);
	// vector<vector<char> > A(n, vector<char>(n, '0'));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(A[i][j] == '0'){
				A[i][j] = 'B';
			}
			cout<<A[i][j];
		}
		cout<<endl;
	}
	return 0;
}