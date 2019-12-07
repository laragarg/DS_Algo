#include<bits/stdc++.h>
using namespace std;
vector<int> seg;
vector<int> A;
void build(int start, int end, int rootp){
    if(start == end){
        seg[rootp] = A[start];
        return;
    }
    int mid = start + (end - start)/2;
    build(start, mid, 2*rootp+1);
    build(mid+1, end, 2*rootp+2);
    seg[rootp] = min(seg[2*rootp + 1], seg[2*rootp + 2]);
    return;
}
void update(int start, int end, int index, int val, int rootp){
    if(start == end){
        seg[rootp] = val;
        return;
    }
    int mid = start + (end - start)/2;
    if(index <= mid){
        update(start, mid, index, val, 2*rootp+1);
    }
    else{
        update(mid+1, end, index, val, 2*rootp+2);
    }
    seg[rootp] = min(seg[2*rootp+1], seg[2*rootp+2]);
    return;
}
int query(int start, int end, int l, int r, int rootp){
    if((l == start && r == end) || start == end){
        return seg[rootp];
    }
    int mid = start + (end - start)/2;
    int temp = INT_MAX;
    if(l <= mid && r <= mid){
        temp = min(temp, query(start, mid, l, r, 2*rootp+1));
    }
    if(l > mid && r > mid){
        temp = min(temp, query(mid + 1, end, l, r, 2*rootp+2));
    }
    if(l <= mid && r >mid){
        temp = min(temp, query(start, mid, l, r, 2*rootp+1));
        temp = min(temp, query(mid + 1, end, l, r, 2*rootp+2));
    }
    return temp;
}
int main(){
    int n, q;
    cin>>n>>q;
    A.resize(n, 0);
    for(int i=0; i<n; i++){
        cin>>A[i];
    }   
    seg.resize(2*n);
    build(0, n-1, 0);
    // for(int i=0; i<seg.size(); i++){
    //     cout<<seg[i]<<" ";
    // }
    // cout<<endl;
    while(q--){
        char c;
        int x, y;
        cin>>c>>x>>y;
        // cin>>s;
        if(c == 'q'){
            x--;
            y--;
            cout<<query(0, n-1, x, y, 0)<<endl;
        }
        else{
            x--;
            update(0, n-1, x, y, 0);
        }
    }
    return 0;
}

//By reference
#include<bits/stdc++.h>
using namespace std;
void build(vector<int> &A, vector<int> &seg, int start, int end, int rootp){
    if(start == end){
        seg[rootp] = A[start];
        return;
    }
    int mid = start + (end - start)/2;
    build(A, seg, start, mid, 2*rootp+1);
    build(A, seg, mid+1, end, 2*rootp+2);
    seg[rootp] = min(seg[2*rootp + 1], seg[2*rootp + 2]);
    return;
}
void update(vector<int> &A, vector<int> &seg, int start, int end, int index, int val, int rootp){
    if(start == end){
        seg[rootp] = val;
        return;
    }
    int mid = start + (end - start)/2;
    if(index <= mid){
        update(A, seg, start, mid, index, val, 2*rootp+1);
    }
    else{
        update(A, seg, mid+1, end, index, val, 2*rootp+2);
    }
    seg[rootp] = min(seg[2*rootp+1], seg[2*rootp+2]);
    return;
}
int query(vector<int> &A, vector<int> &seg, int start, int end, int l, int r, int rootp){
    if((l == start && r == end) || start == end){
        return seg[rootp];
    }
    int mid = start + (end - start)/2;
    int temp = INT_MAX;
    if(l <= mid && r <= mid){
        temp = min(temp, query(A, seg, start, mid, l, r, 2*rootp+1));
    }
    if(l > mid && r > mid){
        temp = min(temp, query(A, seg, mid + 1, end, l, r, 2*rootp+2));
    }
    if(l <= mid && r >mid){
        temp = min(temp, query(A, seg, start, mid, l, r, 2*rootp+1));
        temp = min(temp, query(A, seg, mid + 1, end, l, r, 2*rootp+2));
    }
    return temp;
}
int main(){
    int n, q;
    cin>>n>>q;
    vector<int> seg(2*n);
    vector<int> A(n);
    // A.resize(n, 0);
    for(int i=0; i<n; i++){
        cin>>A[i];
    }   
    // seg.resize(2*n);
    build(A, seg, 0, n-1, 0);
    // for(int i=0; i<seg.size(); i++){
    //     cout<<seg[i]<<" ";
    // }
    // cout<<endl;
    while(q--){
        char c;
        int x, y;
        cin>>c>>x>>y;
        // cin>>s;
        if(c == 'q'){
            // x--;
            // y--;
            cout<<query(A, seg, 0, n-1, --x, --y, 0)<<endl;
        }
        else{
            //x--;
            update(A, seg, 0, n-1, --x, y, 0);
        }
    }
    return 0;
}