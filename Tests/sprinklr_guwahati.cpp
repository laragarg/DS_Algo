#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		string s;
		cin>>s;
		char pre = s[0];
		stack<pair<char, int> >st;
		s.push(s[0]);
		for(int i=1; i<n; i++){
			char x = s[i];
			if(x == s.top().first){
				int temp = s.top().second + 1;
				s.push({x, temp});
			}
			else{
				s.push({x, 1});
			}
			if(s.top().second == k){
				int temp = k;
				// char t = s.top().first;
				while(!s.empty() && temp){
					s.pop();
					temp--;
				}
			}
		}
	}

	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		vector<int>A(n);
		vector<int>d;
		for(int i=0; i<n; i++){
			cin>>A[i];
			if(i > 0){
				d.push_back(A[i] - A[i-1]);
			}
		}
// 		cout<<endl;
		deque<int> dq;
		int win = n - k - 1;
// 		cout<<"win = "<<win;
		for(int i=0; i<win; i++){
			int a = d[i];
			while(!dq.empty() && a > d[dq.back()]){
				dq.pop_back();
			}
			dq.push_back(i);
		}
// 		vector<int> temp;
        int ans = INT_MAX;
		for(int i=win; i<n-1; i++){
			int a = d[i];
			ans = min(ans, d[dq.front()]);
			while(!dq.empty() && a > d[dq.back()]){
				dq.pop_back();
			}
			while(!dq.empty() && i - dq.front() >= win){
				dq.pop_front();
			}
			dq.push_back(i);

		}
		ans = min(ans, d[dq.front()]);
		cout<<"ans = "<<ans<<endl;
	}
	return 0;
}
/*
150 marks wala:
Given n nodes and m edges,
score of a node is defined as number of nodes
(except that node itself), reachable by it.
Score of graph is sum of all the nodes.
After removing exactly any 3 edges, 
find the maximum possible score of graph. 
n 10^5, m 10^6
*/