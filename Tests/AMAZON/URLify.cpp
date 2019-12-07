#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    while(t--){
        cin.ignore();
        string s;
        int n;
        getline(cin, s);
        cin>>n;
        // cout<<s<<endl;
        int i = 0;
        while(i < n && s[i] == ' '){
            s.erase(s.begin());
        }
        i = s.size() - 1;
        while(i >= 0 && s[i] == ' '){
            s.pop_back();
        }
        i = 0;
        while(i < s.size()){
            if(s[i] == ' '){
                // cout<<"i = "<<i<<endl;
                s.insert(s.begin() + i, '0');
                s.insert(s.begin() + i, '2');
                s.insert(s.begin() + i, '%');
                i += 3;
                while(i < s.size() && s[i] == ' '){
                    // cout<<"here"<<endl;
                    s.erase(s.begin()+i);
                }
            }
            else{
                i++;
            }
            // cout<<"size = "<<s.size()<<endl;
            // cout<<"i = "<<i<<endl;
        }
        // cout<<"here"<<endl;
        cout<<s<<endl;
    }
	return 0;
}