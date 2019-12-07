#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;//number of rows and columns
	cin>>n>>m;
	
	vector<vector<int> > v(n, vector<int>(m, 0));
	for(int i=0; i<n; i++){
		//vector<int> temp(m, 0);
		for(int j=0; j<m; j++){
			cin>>v[i][j];
		}	
		//v[i].push_back(temp);
	}
	
	int exor=v[0][0];
	
	for(int i=1; i<n; i++){
		exor=exor^v[i][0];
	}

	vector<int> ind(n, 1);

	if(exor<=0){
		//find an element in rows which is not equal to first element
		int f=0;//element not found yet
		for(int i=0; i<n; i++){
			int temp=v[i][0];
			for(int j=1; j<m; j++){
				if(v[i][j]!=temp){
					f=1;
					ind[i]=j+1;
					break;
				}
			}
		}
		if(f==0){
			cout<<"NIE"<<endl;
		}
		else{
			cout<<"TAK"<<endl;
			for(int i=0; i<n; i++){
				cout<<ind[i]<<" ";
			}	
		}

	}

	else{
		cout<<"TAK"<<endl;
		for(int i=0; i<n; i++){
			cout<<ind[i]<<" ";
		}
	}
	return 0;
}