//Activate fountain / JUMP GAME II
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> locations(n + 1);
	for(int i=1; i<=n; i++){
		cin>>locations[i];
	}
	vector<int> jumps(n + 1);
	for(int i=1; i<=n; i++){
		int a = max(i - locations[i], 1);
		int b = min(i + locations[i], n);
		jumps[a] = max(jumps[a], b - a);
	}
	int steps = 0;
	int cmax = jumps[1];
	int maxm = jumps[1];
	for(int i=1; i<=n; i++){
		cmax = max(cmax, i + jumps[i]);
		if(maxm >= n){
			break;
		}
		if(i == maxm){
			steps++;
			maxm = cmax;
		}
	}
	cout<<steps;
	return 0;
}
