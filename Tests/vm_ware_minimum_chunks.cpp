#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin>>n>>k;
	vector<pair<int, int> > A(k);
	for(int i=0; i<k; i++){
		int a, b;
		cin>>a>>b;
		A[i].first = a;
		A[i].second = b;
	}
	int ans = 0;
	sort(A.begin(), A.end());
	if(k == 0){
	   // cout<<"here"<<endl;
		int sz = n;
		while(sz){
			ans += sz & 1;
			sz = sz >> 1;
		}
	}
// 	else if(k == 1){
// 	    if(A[0].first == 1){
// 	        int r = n;
// 	        int l = A[0].second + 1;
// 	        if(l <= r){
// 	            ans += __builtin_popcount(r - l + 1);
// 	        }
// 	    }
// 	    else{
// 	        int l1 = 1;
// 	        int r1 = A[0].first - 1;
// 	        int l2 = A[0].second + 1;
// 	        int r2 = n;
// 	        ans += __builtin_popcount(r1 - l1 + 1) + __builtin_popcount(r2 - l2 + 1);
//  	    }
// 	}
// 	else{
	    for(int i=0; i<=A.size(); i++){
    		int l = 0, r = 0;
    		if(i == 0){
    		    if(A[0].first != 1){
        			l = 1;
        			r = A[i].first - 1;
    		    }
    		}
    		else if(i == A.size()){
    		    l = A[A.size() - 1].second + 1;
    		    r = n;
    		}
    		else{
    			l = A[i-1].second + 1;
    			r = A[i].first - 1;
    		}
    		if(l <= r && l != 0){
    			ans += __builtin_popcount(r - l + 1);
    		}
    	}
// 	}
    cout<<"ans = "<<ans<<endl;
	return 0;
}