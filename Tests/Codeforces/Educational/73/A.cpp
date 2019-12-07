#include<bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		//vector<int> A(n);
		//map<int, int> m;
		//m.clear();
		map<int, int> m;
		// int f = 0;
		// int f1 = 0;
		for(int i=0; i<n; i++){
			int a;
			cin>>a;
			// if(m.find(a) != m.end()){
			// 	f = 1;
			// }
			// if(a == 2048){
			// 	f1 = 1;
			// }
			m[a]++;
		}
		for(int i=1; i<2048; i*=2){
			m[i*2] += m[i]/2;
		}
		if(m[2048] != 0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		continue;
	}
	return 0;
}