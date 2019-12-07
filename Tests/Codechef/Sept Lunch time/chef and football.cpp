#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int f = 0;
		int op = 0;
		int x = 0;
		bool pknown = false;
		for(int i=0; i<n; i++){
			int a, b, c;
			cin>>a>>b>>c;
			if(a == 1){
				x = 1;
				cout<<"YES"<<endl;
				pknown = true;
			}
			else{
				if(b == c){
					x = 1;
					cout<<"YES"<<endl;
					pknown = true;
				}
				else if(x == 0){
					pknown = false;
					cout<<"NO"<<endl;
				}
				else{
					if(!pknown){
						cout<<"NO"<<endl;
						pknown = false;
					}
					else{
						int temp = max(f, op);
						if(b >= temp && c >= temp){
							cout<<"NO"<<endl;
							pknown = false;
						}
						else{
							cout<<"YES"<<endl;
							pknown = true;
						}
					}
				}
			}
			f = b;
			op = c;
		}
	}
	return 0;
}