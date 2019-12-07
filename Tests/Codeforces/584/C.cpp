#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int flag = 0;
        for(int x = 9; x>=0; x--){
            vector <int> aux;
            vector <int> A(n, 0);
            int r = n-1;
            while(r >=0 && s[r] - '0' != x){
                r--;
            }
            if(r == -1){
                continue;
            }
            for(int i=r; i>=0; i--){
                if(s[i] <= s[r]){
                    r = i;
                    A[i] = 1;
                    aux.push_back(s[i]-'0');
                }
            }
            reverse(aux.begin(),aux.end());
            for(int i=0; i<n; i++){
                if(A[i] == 0){
                    A[i] = 2;
                    aux.push_back(s[i]-'0');
                }
            }
            vector <int> b = aux;
            sort(b.begin(),b.end());
            if(aux == b){
                for(int i=0; i<n; i++){
                    cout<<A[i];
                }
                cout<<endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout<<"-"<<endl;
        }
    }
    return 0;
}