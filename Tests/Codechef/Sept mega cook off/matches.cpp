#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int a, b;
		cin>>a>>b;
		int sum = a + b;	
		int ans = 0;
		while(sum){
			int x = sum%10;
			if(x == 0){
				ans += 6;
			}
			else if(x == 1){
				ans += 2;
			}
			else if(x == 2){
				ans += 5;
			}
			else if(x == 3){
				ans += 5;
			}
			else if(x == 4){
				ans += 4;
			}
			else if(x == 5){
				ans += 5;
			}
			else if(x == 6){
				ans += 6;
			}
			else if(x == 7){
				ans += 3;
			}
			else if(x == 8){
				ans += 7;
			}
			else if(x == 9){
				ans += 6;
			}
			sum = sum/10;
		}
		cout<<ans<<endl;
	}


	return 0;
}