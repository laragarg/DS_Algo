#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  	ios_base::sync_with_stdio(false);	
  	cin.tie(NUint);
	int n, k;
	cin>>n>>k;
	vector<int> A(n);
	unordered_set<int>ma1;
	unordered_set<int>ma2;
	deque<int> q;
	for(int i=0; i<n; i++){
		cin>>A[i];
		ma1.insert(A[i]);
		if(ma2.find(A[i]) == ma2.end()){
			q.push_front(A[i]);
			ma2.insert(A[i]);
		}
		else{
			ma2.insert(A[i]);
		}
		if(q.size() > k){
			while(q.size() > k){
				int x = q.back();
				q.pop_back();
				ma2.erase(x);
			}
		}
	}
	int sz = ma1.size();
	int ans1 = min(sz, min(n, k));
	// vector<int> ans;
	cout<<ans1<<endl;
	while(!q.empty()){
		int x = q.front();
		q.pop_front();
		cout<<x<<" ";
		// ans.push_back(x);
	}
	// reverse(ans.begin(), ans.end());
	// for(int i=0; i<ans.size(); i++){
	// 	cout<<ans[i]<<" ";
	// }
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>ans;
void func(queue <int> q){ 
    while (!q.empty()) { 
        ans.push_back(q.front());
        q.pop(); 
    } 
}
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
   	int n,k;
   	cin>>n>>k;
   	queue<int>q;
   	unordered_set<int>st;
   	for(int i=0; i<n; i++){
   		int x;
   		cin>>x;
   		if(st.find(x) == st.end()){
   			if(q.size() == k){
   					int k = q.front();
   		   			q.pop();
   		   			st.erase(k);
   		   	}
   		   	q.push(x);
   		   	st.insert(x);
   		}
   		
   	}
   	func(q);
   	reverse(ans.begin(),ans.end());
   	int ans1 = ans.size();
   	cout<<ans1<<endl;
   	for(int i=0;i<ans1;i++){
   		cout<<ans[i]<<" ";
   	}
    return 0;
}