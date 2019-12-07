#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int maxi = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '1'){
            maxi++;
        }
    }
    vector <vector <bool > > check(n,vector <bool> (1000, false));
    for(int i=0;i<s.length();i++)
    {
        bool start = false;
        if(s[i] == '1'){
            start = true;
        }
        int a,b;cin>>a>>b;
        for(int j=0;j<1000;j++)
        {
            if(j < b)
            {
                check[i][j] = start;
                continue;
            }
            if((j-b)%a == 0)
            {
                start = !start;
                check[i][j] =start;
            }
            else
            {
                check[i][j] = start;
            }
        }
    }
    for(int i=0;i<1000;i++)
    {
        int temp = 0;
        for(int j=0;j<n;j++)
        {
            if(check[j][i] == true)
            {
                temp++;
            }
        }
        maxi = max(temp,maxi);
    }
    cout<<maxi<<endl;
    return 0;
}