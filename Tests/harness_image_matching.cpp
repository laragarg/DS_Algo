#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >A;
vector<vector<int> >B;
vector<vector<bool> >visA;
vector<vector<bool> >visB;
int n, m;
bool dfs(int a, int b){
	// cout<<"a = "<<a<<" b = "<<b<<" ";
	// cout<<"val1 = "<<A[a][b]<<" val2 = "<<B[a][b];
	if(A[a][b] != B[a][b] || (visA[a][b] != visB[a][b])){
		visA[a][b] = true;
		visB[a][b] = true;	
		// cout<<"here1"<<endl;
		return false;
	}
	if(A[a][b] == B[a][b] && A[a][b] == 0){
		visA[a][b] = true;
		visB[a][b] = true;
		// cout<<"here2"<<endl;
		return true;
	}
	if(A[a][b] == B[a][b] && A[a][b] == 1 && visA[a][b] == visB[a][b] && visA[a][b] == true){
		// cout<<"here3"<<endl;
		return true;
	}
	cout<<endl;
	// cout<<"out"<<endl;
	bool res = true;
	visA[a][b] = true;
	visB[a][b] = true;
	for(int i=-1; i<=1; i++){
		int di = a + i;
		// int	diB = c + i;
		if(di < 0 || di >= n){
			continue;
		}
		for(int j=-1; j<=1; j++){
			int dj = b + j;
			// int djB = d + j;
			if(dj < 0 || dj >= m){
				continue;
			}
			if(abs(i) == abs(j))
				continue;
			res = dfs(di, dj);
			if(!res){
				// cout<<"here false";
				return false;
			}
		}
	}
	return res;
}
void change1(int a, int b){
	// cout<<"gere"<<a<<" "<<b<<endl;
	visA[a][b] = true;
	for(int i=-1; i<=1; i++){
		int di = a + i;
		if(di < 0 || di >= n){
			continue;
		}
		for(int j=-1; j<=1; j++){
			int dj = b + j;
			if(dj < 0 || dj >= m){
				continue;
			}
			if(abs(i) == abs(j))
				continue;
			if(A[di][dj] == 1&&!visA[di][dj]){
				change1(di, dj);
			}
		}
	}
	return;
}
void change2(int a, int b){
	visB[a][b] = true;
	for(int i=-1; i<=1; i++){
		int di = a + i;
		if(di < 0 || di >= n){
			continue;
		}
		for(int j=-1; j<=1; j++){
			int dj = b + j;
			if(dj < 0 || dj >= m){
				continue;
			}
			if(abs(i) == abs(j))
				continue;
			if(B[di][dj] == 1&&!visB[di][dj]){
				change2(di, dj);
			}
		}
	}
	return;
}
int main(){
	cin>>n>>m;
	A.clear();
	visA.clear();
	B.clear();
	visB.clear();
	A.resize(n, vector<int>(m));
	visA.resize(n, vector<bool>(m, false));
	B.resize(n, vector<int>(m));
	visB.resize(n, vector<bool>(m, false));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>A[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>B[i][j];
		}
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!visA[i][j] && !visB[i][j] && A[i][j] == 1 && B[i][j] == 1){
				if(dfs(i, j)){
					// cout<<"here"<<endl;
					ans++;
				}
			}
			else if(A[i][j] == 1 && B[i][j] == 1){
				// cout<<"i1 = "<<i<<" j1 = "<<j<<" ";
				change1(i, j);
				// cout<<"i1 = "<<i<<" j1 = "<<j<<endl;
				change2(i, j);
				// visA[i][j] = true;
				// visB[i][j] = true;
		  	}
		}
	}
	cout<<ans;
	return 0;
}
/*

4 4
1 0 0 0
1 1 0 0
1 0 0 1
1 0 0 1

1 0 0 0
1 1 0 0
1 0 0 1
1 0 1 1

*/