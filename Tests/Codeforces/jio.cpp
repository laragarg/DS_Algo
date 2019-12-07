/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *a[])
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n,0);
        int m = INT_MIN;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            m = max(m,v[i]);
            if(v[i]<0)
                v[i]=0;
        }
        if(m<0){
            cout<<m<<endl;
            continue;
        }
        vector<int> incl(n,0);
        vector<int> excl(n,0);
        excl[0] = 0;
        incl[0] = v[0];
        for(int i=1;i<n;i++){
            incl[i] = excl[i-1] + v[i];
            excl[i] = max(incl[i-1], excl[i-1]);
        }
        vector<int> flag(n,0);
        int maxm = max(excl[n-1],incl[n-1]);
        for(int i=n-1;i>=0;i--){
            if(excl[i]==maxm){
                flag[i]=0;
            } else {
                flag[i]=1;
                maxm=maxm-v[i];
            }
        }
        for(int i=n-1;i>=0;i--) {
            if(flag[i]==1) {
                cout<<v[i];
            }
        }
        cout<<endl;
    }
    return 0;
}
