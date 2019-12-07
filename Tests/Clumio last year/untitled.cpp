#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<pair<int, int> >A(n);
	unordered_map<int, set<int> >mx;
	unordered_map<int, set<int> >my;
	for(int i=0; i<n; i++){
		// cin>>A[i].frist;
		// cin>>A[i].second;
		int x, y;
		cin>>x>>y;
		A[i].first = x;
		A[i].second = y;
		mx[x].insert(y);
		my[y].insert(x);
	}
	int q;
	cin>>q;
	while(q--){
		int in;
		cin>>in;
		int x = A[in].first;
		int y = A[in].second;
		set<int> temp1 = mx[x];
		set<int> temp2 = my[y];
		int ans1, ans2;
		if(temp1.size() == 1){
		    ans1 = INT_MAX;
		}
		else{
    		auto it1 = temp1.lower_bound(y);
    		auto it2 = temp1.upper_bound(y);
    		int sutta1;
    		if(it1 == temp1.begin()){
    			sutta1 = INT_MAX;
    		}
    		else{
    			it1 = prev(it1);
    			sutta1 = abs(y - *it1);
    		}
    		// while(sutta1 == 0){
    		//     it1 = prev(it1);
      //           cout<<"it1 = "<<*it1<<endl;
    		// 	sutta1 = abs(y - *it1);
    		// }
    		int sutta2;
    		if(it2 == temp1.end()){
    			sutta2 = INT_MAX;	
    		}
    		else{
    			sutta2 = abs(y - *it2);
    		}
    		ans1 = min(sutta1, sutta2);
    // 		cout<<"ans1 = "<<ans1<<endl;
		}
		if(temp2.size() == 1){
		    ans2 = INT_MAX;
		}
		else{
    		auto it1 = temp2.lower_bound(y);
    		auto it2 = temp2.upper_bound(y);
    		int sutta1;
    		if(it1 == temp2.begin()){
    			sutta1 = INT_MAX;
    		}
    		else{
    			it1 = prev(it1);
    			sutta1 = abs(x - *it1);
    			cout<<"x = "<<x<<" ";
    			cout<<"it = "<<*it1<<" ";
    		}
    		// while(sutta1 == 0){
    		//     it1 = prev(it1);
      //           cout<<"it1 = "<<*it1<<endl;
    		// 	sutta1 = abs(y - *it1);
    		// }
    		int sutta2;
    		if(it2 == temp2.end()){
    			sutta2 = INT_MAX;	
    		}
    		else{
    			sutta2 = abs(x - *it2);
    		}
    		cout<<"sutta1 = "<<sutta1<<" sutta2 = "<<sutta2<<endl;
    		ans2 = min(sutta1, sutta2);
		}
// 		cout<<"here"<<endl;
        // cout<<"ans1 = "<<ans1<<" ans2 = "<<ans2<<endl;
		int ans = min(ans1, ans2);
	    cout<<ans<<endl;
	}
	return 0;
}