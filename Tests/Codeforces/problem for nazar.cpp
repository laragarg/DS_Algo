#include<bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
	ll l,r,sum=0,mod=1000000007,v1,v2;//sum is number of terms
	cin>>l>>r;
	l--;

	ll temp = 2;//number of current set elements and number of total elements before current set
	while(temp <= r) {
		sum += min(r-temp+1, temp);
		temp*=4;
	}
	v1=(((((sum%mod)*(sum%mod)) + sum)%mod) + ((((r-sum)%mod)*((r-sum)%mod))%mod))%mod;//sum upto r(=sum) terms
	
	temp = 2;
	sum=0;
	while(temp <= l) {
		sum += min(l-temp+1, temp);
		temp*=4;
	}
	v2=(((((sum%mod)*(sum%mod)) + sum)%mod) + ((((l-sum)%mod)*((l-sum)%mod))%mod))%mod;//sum upto l(=sum) terms
	
	cout<<(v1-v2+mod)%mod<<"\n";
  	return 0;
}