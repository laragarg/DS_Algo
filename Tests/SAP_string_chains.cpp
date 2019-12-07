//SAP Labs string chains
#include<bits/stdc++.h>
using namespace std;
bool comp(string s1, string s2){
	return s1.size() >= s2.size();
}
map<string, int> dp;
// int n;
// vector<string> A;
unordered_map<string, int> dict;
vector<string> sub(string s){
	vector<string>ans;
	for(int i=0; i<s.size(); i++){
		string temp = s;
		s.erase(i, 1);
		if(dict.find(s) != dict.end()){
			ans.push_back(s);
		}
		s = temp;
	}
	return ans;
}
int func(string s){
	// int res = 0;
	if(dp.find(s) != dp.end()){
		return dp[s];
	}
	vector<string>child = sub(s);
	int res = 1;
	for(int i=0; i<child.size(); i++){

		res = max(res, func(child[i]));
	}
	return dp[s] = res;
}
int main(){
	int n;
	cin>>n;
	vector<string>A(n);
	for(int i=0; i<n; i++){
		cin>>A[i];
		dict[A[i]] = 1;
	}
	sort(A.begin(), A.end(), comp);
	int ans = 1;
	for(int i=0; i<n; i++){
		if(dp.find(A[i]) == dp.end()){
			dp[A[i]] = 1;
			vector<string> child = sub(A[i]);
			int res = 0;
			for(int j=0; j<child.size(); j++){
				res = max(res, func(child[i]));
			}
			dp[A[i]] += res;
		}
		ans = max(ans, dp[A[i]]);
	}
	cout<<"ans = "<<ans<<endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector <string> func(string s)
{
    vector <string> res;
    for(int i=0;i<s.length();i++)
    {
        string temp = s;
        temp.erase(i,1);
        res.push_back(temp);
    }
    return res;
}
bool myfunc(string s1,string s2)
{
    return s1.length()>=s2.length();
}
int main()
{
    int n;cin>>n;
    vector <string> input(n);
    map <string,int> dict;
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
        dict[input[i]]++;
    }
    map <string,int> hashmap;
    sort(input.begin(),input.end(),myfunc);
    for(int i=0;i<input.size();i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
    vector <int> dp(n,0);
    int max_len = input[0].length();
    for(int start = 0; start < n;start++)
    {
        if(input[start].length() == max_len)
        {
            hashmap[input[start]] = 1;
        }
        else
            break;
    }
    //if(start == n) cout<<1<<endl;
    for(int i=0;i<n;i++)
    {
        vector <string> rstring = func(input[i]);
        if(hashmap.find(input[i]) == hashmap.end())
        {
            hashmap[input[i]] = 1;
        }
        cout<<input[i]<<endl;
        for(int j=0;j<rstring.size();j++)
        {
            cout<<rstring[j]<<" ";
        }
        cout<<endl;
        for(int j=0;j<rstring.size();j++)
        {
            if(dict.find(rstring[j]) != dict.end())
            {
                if(hashmap.find(rstring[j]) != hashmap.end())
                {
                    hashmap[rstring[j]] = max(hashmap[rstring[j]],1+hashmap[input[i]]);
                }
                else
                {
                    hashmap[rstring[j]] = 1+hashmap[input[i]];
                }
            }
        }
    }
    int ans = 1;
    for(auto it = hashmap.begin();it!=hashmap.end();it++)
    {
        ans = max(ans,it->second);
    }
    cout<<ans<<endl;
    return 0;
}a