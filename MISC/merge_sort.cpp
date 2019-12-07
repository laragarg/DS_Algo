//Sorts the given array
//Divide and conquer
#include<bits/stdc++.h>
using namespace std;
vector<int> A;
vector<int> temp;
int n;
void merge(int l, int mid, int r){
	int i = l;
	int j = mid+1;
	int k = l;
	while(i<=mid && j<=r){
		if(A[i] <= A[j]){
			temp[k++] = A[i++];
		}
		else{
			temp[k++] = A[j++];
		}
	}
	while(i<=mid){
		temp[k++] = A[i++];
	}
	while(j<=r){
		temp[k++] = A[j++];
	}
	for(i=l; i<=r; i++){
		A[i] = temp[i];
	}
	return;
}
void mergeSort(int l, int r){
	if(l < r){
		int mid = l + (r - l)/2;
		mergeSort(l, mid);
		mergeSort(mid + 1, r);
		merge(l, mid, r);
	}
	return;
}
int main(){
	cin>>n;
	temp.clear();
	temp.resize(n);
	A.clear();
	A.resize(n);
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	mergeSort(0, n-1);
	for(int i=0; i<n; i++){
	    cout<<A[i]<<" ";
	}
	return 0;
}