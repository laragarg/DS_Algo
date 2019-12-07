#include<bits/stdc++.h>
using namespace std;
int main(){
	int maxm = 1;
	vector<int> arr = {-1,8,6,0,7,3,8,9,-1,6,1};
	int n = arr.size();
	map<int, int>vis;
	stack<int>st;
	for(int i=0; i<n; i++){
		int a = i;
		int count = 1;
		while(a > -1){
		    if(vis.find(a) != vis.end()){
		        count = vis[a]+1;
		        break;
		    }
			st.push(a);
			a = arr[a];
		}
		while(!st.empty()){
			a = st.top();
			cout<<a<<" "<<count<<endl;
			vis[a] = count;
			maxm = max(maxm, count);
			count++;
			st.pop();
		}
		cout<<endl;
	}
    cout<<maxm<<endl;
	return 0;
}