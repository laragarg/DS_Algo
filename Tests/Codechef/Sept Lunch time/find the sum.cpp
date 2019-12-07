#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;
		vector <int> odd(n+1),even(n+1);
		odd[1]=0;even[1]=0;

		vector<int> B(n);
		for(int i=1; i<n; i++){
			cin>>B[i];
		}
		for(int i=2;i<=n;i++)
		{
			if(i%2 == 0)
			{
				odd[i] = odd[i-1]+B[i-1];
				even[i]= even[i-1];
			}
			else
			{
				even[i] = even[i-1]+B[i-1];
				odd[i] = odd[i-1];
			}
		}
		while(q--){
			int p, q;
			cin>>p>>q;
			if(abs(p - q) % 2 == 0){
				cout<<"UNKNOWN"<<endl;
			}
			else{
				int sum = 0;
				if(p > q){
					q = q ^ p;
					p = p ^ q;
					q = q ^ p;
				}

				if(p%2 == 0)
				{
					sum = even[q]-even[p]-(odd[q]-odd[p]);
				}
				else
					sum = odd[q]-odd[p]-(even[q]-even[p]);
				cout<<sum<<endl;
			}
		}
	}
	return 0;
}