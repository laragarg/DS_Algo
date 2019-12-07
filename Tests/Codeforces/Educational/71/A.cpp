#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll buns, beef, chickenCutlets;
		cin>>buns>>beef>>chickenCutlets;
		ll pham, pchic;
		cin>>pham>>pchic;
		ll p = 0;
		if(buns<2){
			cout<<0<<endl;
			continue;
		}
		if(pham>=pchic){
			if(buns>=2*beef){
				p += beef*pham;	
				buns = buns - 2*beef;
				if(buns>=2*chickenCutlets){
					p += chickenCutlets*pchic;
				}
				else{
					if(buns>=2){
						p += (buns/2)*pchic;
					}
				}
			}
			else{
				p += (buns/2)*pham;
			}
			
		}
		else{
			if(buns>=2*chickenCutlets){
				p += chickenCutlets*pchic;
				buns = buns - 2*chickenCutlets;
				if(buns>=2*beef){
					p += beef*pham;
				}
				else{
					if(buns>=2){
						p += (buns/2)*pham;
					}
				}
			}
			else{
				p += (buns/2)*pchic;
			}
			
		}
		cout<<p<<endl;
	}
	return 0;
}