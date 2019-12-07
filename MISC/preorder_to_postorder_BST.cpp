//to find postorder from preorder of BST
#include <bits/stdc++.h> 
using namespace std;
int pi;
void findPostOrderUtil(int pre[], int n, int minval, int maxval) { 
	// If entire preorder array is traversed then 
	if (pi == n) 
		return; 
	// If array element does not lie in current range ,then it is not part of current subtree.
	if (pre[pi] < minval || pre[pi] > maxval) { 
		return; 
	} 
	//store root_value to be printed later coz postorder
	int root_value = pre[pi]; 
	pi++; 

	// traverse left subtree
	findPostOrderUtil(pre, n, minval, root_value); 

	//traverse right	
	findPostOrderUtil(pre, n, root_value, maxval); 

	cout << root_value << " "; 
} 

// Driver code 
int main() { 
	int pre[] = { 40, 30, 35, 80, 100 }; 
	int n = sizeof(pre) / sizeof(pre[0]); 
	pi = 0; 
	findPostOrderUtil(pre, n, INT_MIN, INT_MAX);  
	return 0; 
} 
