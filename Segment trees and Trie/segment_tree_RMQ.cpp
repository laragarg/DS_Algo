#include<bits.stdc++.h>
using namespace std;
vector<int> seg;		
int rmq(int qleft, int qright, int lo, int hi, int rootp){//range minimum query
	if(qleft <= lo && qright >= hi){//total overlap
		return seg[rootp];
	}
	if(qleft > high || qright < lo){//no overlap
		return INT_MAX;
	}
	else{//partial overlap
		int mid = lo + (hi - lo)/2;//mid is the upper index for left range
								//and mid + 1 is the lower index for right range
		int left = rmq(qleft, qright, lo, mid, 2*rootp + 1);
		int right = rmq(qleft, qright, mid + 1, 2*rootp + 2);
		seg[rootp] = min(left, right);
	}
}
void build(vector<int> &A, int lo, int hi, int rootp){
	if(lo == hi){//leaf node
		seg[rootp] = A[lo];
		return;
	}
	int mid = lo + (hi - lo)/2;
	build(A, lo, mid, 2*rootp + 1);//construct left child (2*rootp + 1 is the root of left subtree of rootp)
	build(A, mid + 1, hi, 2*rootp + 2);//construct right child(2*rootp + 2 is the root of right subtree of rootp)
	seg[rootp] = min(seg[2*rootp + 1], seg[2*rootp + 2]);//this value depends on the type of query of the question
}
int main(){
	vector<int> A;
	int n = A.size();
	int temp = log2(n);
	int x = (n&(n-1)) == 0 ? 2*n-1 : pow(2, temp+1);
	seg.resize(x);
	//if n is power of 2 then x = 2*n - 1;
	//else x = 2*m - 1 where m is the next power of 2
	return 0;
}