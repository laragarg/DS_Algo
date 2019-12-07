#include <bits/stdc++.h>
using namespace std;

//whenever we reach a node either for update or a query, first thing we check is 
//whether all the past updates have been applied or not, to do that we look into
//lazy tree
void update(vector <int> &seg,vector <int> &lazy,int qlow,int qhigh,int delta,int low,int high,int pos){
	if(low > high){
		return ;	
	} 
	if(lazy[pos] != 0){//if the value is non zero this means that there are 
					//updates from last operations which have not been applied
					//so we apply that first
		seg[pos] += lazy[pos];//apply the previous update
		if(low != high){
			lazy[2*pos+1] += lazy[pos];
			lazy[2*pos+2] += lazy[pos];
		}
		lazy[pos] = 0;
	}

	//if lazy[pos] == 0, this means that value at pos is up to date from previous operations 
	if(qlow > high || qhigh < low){//no overlap
		return;
	}

	if(qlow <= low && qhigh >= high){//total overlap
		seg[pos] += delta;//update
		if(low != high){//now rahter than going down in segment tree and updating the values, 
					//just update the left and right children in lazy tree
			lazy[2*pos + 1] += delta;
			lazy[2*pos + 2] += delta;	
		}
		return;
	}
	//partial overlap
	int mid = low + (high - low)/2;
	update(seg, lazy, qlow, qhigh, delta, low, mid, 2*pos+1);
	update(seg, lazy, qlow, qhigh, delta, mid+1, high, 2*pos+2);
	seg[pos] = seg[2*pos+1] + seg[2*pos+2];
}
int sumst(vector <int> &seg,vector <int> &lazy,int qlow,int qhigh,int low,int high,int pos){
	if(low > high){
		return 0;
	}
	if(lazy[pos] != 0){//if the value is non zero this means that there are 
					//updates from last operations which have not been applied
					//so we apply that first
		seg[pos] += lazy[pos];
		if(low != high){
			lazy[2*pos + 1] += lazy[pos];
			lazy[2*pos + 2] += lazy[pos];
		}
		lazy[pos] = 0;
	}

	//if lazy[pos] == 0; 
	if(qlow <= low && qhigh >= high){//total overlap
		return seg[pos];
	}
	if(qlow > high  || qhigh < low)//no overlap
		return 0;
	//partial overlap
	int mid = low + (high - low)/2;//partial overlap
	return sumst(seg, lazy, qlow, qhigh, low, mid, 2*pos+1) + sumst(seg, lazy, qlow, qhigh, mid+1, high, 2*pos+2);
}
void build(vector<int> &A, vector<int> &seg, int lo, int hi, int rootp){
	if(lo == hi){
		seg[rootp] = A[lo];
	}
	int mid = lo + (hi - lo)/2;
	build(A, seg, lo, mid, 2*rootp + 1);//construct left child (2*rootp + 1 is the root of left subtree of rootp)
	build(A, seg, mid + 1, hi, 2*rootp + 2);//construct right child(2*rootp + 2 is the root of right subtree of rootp)
	seg[rootp] = min(seg[2*rootp + 1], seg[2*rootp + 2]);//this value depends on the type of query of the question
}
int main(){
	int n;cin>>n;
	vector <int> A(n);
	for(int i=0; i<n; i++){
		cin>>A[i];
	}

	int temp = log2(n);
	int size = (n&(n-1)) == 0 ? 2*n-1 : pow(2, temp+1);
	vector <int> seg(size);
	build(A, seg, 0, n-1, 0);
	
	vector <int> lazy(size,0);
	cout<<sumst(seg, lazy, 1, 3, 0, 3, 0)<<endl;
	update(seg,lazy, 0, 2, 2, 0, 3, 0);
	cout<<sumst(seg, lazy, 1, 3, 0, 3, 0)<<endl;
}