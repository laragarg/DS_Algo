#include <bits/stdc++.h>
using namespace std;
int sz;
void func(int snode,int par,int maxi,vector <vector <int> > &input,vector <int> &val)
{
    sz++;
    for(int i=0;i<input[snode].size();i++)
    {
        if(input[snode][i] != par && val[input[snode][i]] == maxi)
        {
            func(input[snode][i],snode,maxi,input,val);
        }
    } 
    return;  
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector <vector <int> > input(n);
    vector <int> val(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        input[a].push_back(b);
        input[b].push_back(a);
    }
    int maxi = 0;
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
        maxi=max(maxi,val[i]);
    }
    vector <int> mnodes;
    for(int i=0;i<n;i++)
    {
        if(maxi == val[i])
        {
            mnodes.push_back(i);
        }
    }
    sz = 0;
    func(mnodes[0],-1,maxi,input,val);
    if(sz != mnodes.size())
    {
        cout<<0<<endl;
        return 0;
    }
    queue <pair <int,int> > q;
    int flag= 0;
    q.push({mnodes[0],-1});
    while(!q.empty())
    {
        int csz = q.size();
        for(int i=0;i<csz;i++)
        {
            pair <int,int> temp = q.front();
            //cout<<temp<<endl;
            int tnode = temp.first;
            int tpar  = temp.second;
            q.pop();
            for(int j=0;j<input[temp].size();j++)
            {
                int child = input[tnode][j];
                if(child == tpar) continue;
                if(val[child] > val[tnode])
                {
                    flag = 1;
                    break;
                }
                q.push(child);
            }
            if(flag) break;
        }
        if(flag)
        {
            break;
        }    
    }
    if(flag == 0)
    {
        cout<<sz<<endl;
    }
    else
        cout<<0<<endl;
    return 0;
}