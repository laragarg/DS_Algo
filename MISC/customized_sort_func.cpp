// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int, int> m;
        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            m[a]++;
        }
        vector<pair<int, int> >A;
        for(auto it=m.begin(); it!= m.end(); it++){
            int num = it->first;
            int freq = it->second;
            A.push_back({num, freq});
        }
        sort(A.begin(), A.end(), comp);//sorts in decreasing order of second value and if second values are equal then in sorts in increasing order
        // reverse(A.begin(), A.end(), comp);
        for(int i=0; i<A.size(); i++){
            int a = A[i].first;
            int freq = A[i].second;
            while(freq--){
                cout<<a<<" ";
            }
        }
        cout<<endl;
    }
	return 0;
}