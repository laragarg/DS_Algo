#include<bits/stdc++.h>
using namespace std;
int main(){
	int k, n;
	cin>>k;
	// vector<int> arr(n);
	vector<pair<int, int> >A(n);
	for(int i=0; i<n; i++){
		// cin>>arr[i];
		cin>>A[i].first;
	}
	// vector<int> dep(n);
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		// dep[i] = a + arr[i];
		A[i].second = a + A[i].first;
	}
	vector<int> ser(k+1, false);
	sort(A.begin(), A.end());

	return 0;
}


#include <bits/stdc++.h>
using namespace std;
int main(){
    int servers;
    cin>>servers;
    int n;
    cin>>n;
    vector <pair <int,int> > input(n);
    vector <int> arr(n), load(n);
    for(int i=0;i<n;i++){
        cin>>input[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>input[i].second;
    }
    sort(input.begin(),input.end());
    for(int i=0;i<n;i++){
        arr[i] = input[i].first;
        load[i] = input[i].second;
    }
    priority_queue<pair<int, int>, vector <pair <int,int> > , greater <pair <int,int>> > pq;
    for(int i=0; i<servers;i++){
        pq.push({0,0});
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(arr[i] < pq.top().first){
        	continue;
        } 
        pair <int,int> temp = pq.top();
        pq.pop();
        pq.push({temp.first + arr[i]-1, temp.second+1});
        ans = max(ans,temp.second);
    }
    cout<<ans<<endl;
    return 0;
}