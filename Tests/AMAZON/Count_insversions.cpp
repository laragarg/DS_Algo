#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>A;
vector<int> temp;
int n;
int mergeSort(int l, int mid, int r){
    int i = l;
    int j = mid+1;
    int k = l;
    int count = 0;
    while(i <= mid && j <= r){
        if(A[i] <= A[j]){
            temp[k] = A[i];
            k++;
            i++;
        }
        else{
            temp[k] = A[j];
            k++;
            j++;
            count += mid - i + 1;
        }
    }

    //Fill the leftovers
    while(i <= mid){
        temp[k++] = A[i++];
    }
    while(j <= r){
        temp[k++] = A[j++];
    }

    //change the original array
    for(int i=l; i<=r; i++){
        A[i] = temp[i];
    }
    return count;
}
int merge(int l, int r){
    int ans = 0;
    if(l < r){
        int mid = l + (r - l)/2;
        ans += merge(l, mid);
        ans += merge(mid+1, r);
        ans += mergeSort(l, mid, r);
    }
    return ans;
}
signed main(){
    int d;
    cin>>d;
    while(d--){
        // int n;
        cin>>n;
        A.clear();
        A.resize(n);
        temp.clear();
        temp.resize(n);
        // vector<int> A(n);
        // cout<<"here"<<endl;
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        int ans = merge(0, n-1);
        cout<<ans<<endl;
    }
    return 0;
}
