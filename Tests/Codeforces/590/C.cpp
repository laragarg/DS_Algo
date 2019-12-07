#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
       // cout<<a<<" "<<b<<endl;
        /*if(a[0] != '1' && a[0] != '2')
        {
            cout<<"NO"<<endl;
            //cout<<"bwah"<<endl;
            continue;
        }*/
        int x = 0;
        int y = 1;
        int flag = 0;
        while(x < n){
            //cout<<x<<" ";
            if(y == 1){
                if(a[x] == '1' || a[x] == '2'){
                    x = x + 1;
                }
                else{
                    if(b[x] == '1' || b[x] == '2'){
                        cout<<"NO"<<endl;
                        flag = 1;
                        break;
                    }
                    else{
                        y = y + 1;
                        x=x + 1;
                    }
                }
            }
            else{
                if(b[x] == '1' || b[x] == '2'){
                    x = x + 1;
                }
                else{
                    if(a[x] == '1' || a[x] == '2'){
                        cout<<"NO"<<endl;
                        flag = 1;
                        break;
                    }
                    else{
                        y = y-1;
                        x = x+1;
                    }
                }
            }
            
        }
        //cout<<endl;
        if(flag == 0 )
        {
            if(y == 2)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}


