#include <bits/stdc++.h> 
using namespace std; 

int* tree;
int* A;
void build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = A[start];
    }
    else
    {
    int mid = start + (end - start)/2;
        build(2*node+1, start, mid);
        build(2*node+2, mid+1, end);
        tree[node] = min(tree[2*node+1],tree[2*node+2]);
    }
}

void update(int node, int index, int val, int start, int end)
{
    if(start == end)
    {
        tree[node] = val;
    }
    else
    {
    int mid = start + (end - start)/2;
        if(index<=mid)
            update(2*node+1, index, val, start, mid);
        else
            update(2*node+2,  index, val, mid+1, end);
        tree[node] = min(tree[2*node+1],tree[2*node+2]);
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(start == end)
    {
        return tree[node];
    }
    else
    {
        if(l==start&&r==end) {
            return tree[node];
        }
    int mid = start + (end - start)/2;
        int temp = INT_MAX;
        if(l<=mid && r>mid) {
            temp = min(temp, query(2*node+1, start, mid, l, mid));
            temp = min(temp, query(2*node+2, mid+1, end, mid+1, r));
        }
        if(l<=mid && r<=mid)
            temp = min(temp, query(2*node+1, start, mid, l, r));
        if(l>mid && r>mid)
            temp = min(temp, query(2*node+2, mid +1, end, l, r));
        
        return temp;
    }
}

int main()  {  
    int n,q;
    cin>>n>>q;
    
    A = new int[n];
    for(int i =0; i<n; i++) {
        cin>>A[i];
    }
    tree = new int[2*n];
    build(0,0, n-1);
    
    for(int i=0;i<q;i++) {
        char c; int x,y;
        cin>>c>>x>>y;
        if(c=='q')
            cout<<query(0,0,n-1,--x,--y)<<"\n";
        else
            update(0,--x,y,0,n-1);
    }  
    return 0;  
}  
