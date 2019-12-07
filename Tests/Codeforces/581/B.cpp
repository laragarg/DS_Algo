#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int n, l, r;
	cin>>n>>l>>r;
	vector<long long int> A(n, 1);
	long long int dist = 1;
	long long int i = 1;
	long long int suml = n;
	long long int sumr = n;
	while(dist!=r){
		A[i] = 2*A[i-1];
		if(dist<l){
			suml += A[i] - 1;	
		}
		sumr += A[i] - 1;
		i++;
		dist++;
	}
	sumr += (n-i)*A[i-1] - (n-i);
	cout<<suml<<" "<<sumr<<endl;
	/*A.resize(n, 1);
	i = 1;
	dist = 1;
	while(dist!=r){
		A[i] = 2*A[i-1];
		
		i++;
		dist++;
	}*/
	
	return 0;
}