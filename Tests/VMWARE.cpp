//University career fair
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	vector<int> dep(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<n; i++){
		cin>>dep[i];
	}
	
	vector<pair<int, int> >A(n);
	for(int i=0; i<n; i++){
		A[i].first = arr[i] + dep[i];
		A[i].second = arr[i];
	}
	sort(A.begin(), A.end());
	int ans = 1;
	int start = A[0].second;
	int end = A[0].first;
	for(int i=1; i<n; i++){
		if(A[i].second >= end){
			ans++;
			end = A[i].first;
		}
	}
	cout<<"ans = "<<ans<<endl;
	return 0;
}

//Minimum Chunks
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
	else{
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
	}
    cout<<"ans = "<<ans<<endl;
	return 0;
}


//Minimum Swaps
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<pair<int, int> > A(n);
	for(int i=0; i<n; i++){
		cin>>A[i].first;
		A[i].second = i;
	}
	vector<pair<int, int> >B = A;
	sort(B.begin(), B.end());
	int ans = 0;
	vector<bool> vis(n, false);
	for(int i=0; i<n; i++){
		if(A[i].second == B[i].second || vis[i]){
			vis[i] = true;
			continue;
		}
		else{
			int j = B[i].second;
			vis[i] = true;
			int nodes = 1;
			while(!vis[j]){
			 //   cout<<"j = "<<j<<endl;
			 //   cout<<"here"<<endl;
				vis[j] = true;
				j = B[j].second;
				// cout<<"j = "<<j<<endl;
				nodes++;
			}
			ans += nodes - 1;
		}
	}
	cout<<"ans = "<<ans<<endl;
	return 0;
}

//Wendy Bob
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n = s.size();
	int wendy = 0, bob = 0;
	int i = 0;
	while(i < n){
		int j = i;
		int len = 0;
		// if(s[j] == 'w'){
			while(j < n - 1 && s[j] == s[j+1]){
				j++;
			}
			len = j - i + 1;
		// }
		if(s[i] == 'w' && len >= 3){
			wendy += len - 2;
		}
		else if(s[i] == 'b' && len >= 3){
			bob += len - 2;
		}
		i = j + 1;
	}
	if(wendy > bob){
		cout<<"Wendy";
	}
	else{
		cout<<"Bob";
	}
	return 0;
}

//Scatter Palindrome
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n = s.size();
	vector<vector<int> >A(26, vector<int>(n, 0));
	for(int i=0; i<n; i++){
		char x = s[i];
		// int temp = A[x - 'a'][i];
		for(int j=i; j<n; j++){
			A[x - 'a'][j]++;
		}
		// A[x - 'a'][i]++;
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int len = j - i + 1;
			bool f = 0;
			int k = 0;
			for(k; k<26; k++){
				if(i > 0){
					if( (A[k][j] - A[k][i - 1]) % 2 != 0){
						if(len % 2 == 0){
							break;
						}
						else{
							if(f == 1){
								break;
							}
							else{
								f = 1;
							}
						}
					}	
				}
				else{
					if( (A[k][j]) % 2 != 0){
						if(len % 2 == 0){
							break;
						}
						else{
							if(f == 1){
								break;
							}
							else{
								f = 1;
							}
						}
					}
				}
			}
			if(k == 26){
				ans++;
			}
		}
	}
	ans += n;
	cout<<"ans = "<<ans<<endl;
	return 0;
}


