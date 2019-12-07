#include<bits/stdc++.h>
using namespace std;
void calculate(string &s, vector<int>&lps){
	int l = 0;
	int r = 1;
	int n = s.size();
	lps[0] = 0;
	while(l < n && r < n){
		if(s[l] == s[r]){
			lps[r] = l + 1;
			l++;
			r++;
		}
		else{
			if(l != 0){
				l = lps[l-1];
			}
			else{
				r++;
			}
		}
	}
	return;
}
int kmp(vector<int> &lps, string &s){
	string t = "ABC";
	int ans = 0;
	int i = 0;
	int j = 0;
	int n = s.size();
	int m = t.size();
	while(i < n){
		if(s[i] == t[j]){
			i++;
			j++;
		}
		else if(j == m){
			ans++;
			j = lps[j-1];
			s[i-3] = 'B';
			s[i-2] = 'C';
			s[i-1] = 'A';
		}
		else{
			if(j != 0){
				j = lps[j-1];
			}
			else{
				i++;
			}
		}
	}
	return ans;
}
int main() {
	string s;
	cin>>s;
	int n = s.size();
	if(n <= 2){
		cout<<0;
		return 0;
	}
	vector<int> lps(n);
	calculate(s, lps);
	// string t = "ABC";
	int ans = 0;
	while(true){
		int temp = kmp(lps, s);
		ans += temp;
		if(temp == 0){
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}