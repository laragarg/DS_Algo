#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string r;
		cin>>r;
		map <char,int> hashmap;
		for(int i=0;i<r.length();i++)
		{
			hashmap[r]++;
		}
		string temp;
		for(int i=0;i<s.length();i++)
		{
			if(hashmap.find(s[i]) != hashmap.end())
			{
				hashmap[s[i]]--;
				if(hashmap[s[i]] == 0)
				{
					hashmap.erase(s[i]);
				}
			}
			else
			{
				temp.push_back(s[i]);
			}
		}
		s = temp;
		int n = s.length();
		string result = "";
		for(int i=0;i<=n;i++)
		{
			string bef = s.substr(0,i);
			string aft = s.substr(i,n-i);
			cout<<bef<<" "<<aft<<endl;
			string ans = bef+temp+aft;
			if(result == ""||ans < result) 
			{
				result = ans;
			}
		}
		cout<<result<<endl;
	}
	return 0;
}