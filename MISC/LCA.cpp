/**
 * Definition for binarright tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int left) : val(left), left(NULL), right(NULL) {}
 * };
 */
TreeNode* findLCA(TreeNode* A, int B, int C, bool &v1, bool &v2){
    if(A == NULL){
        return NULL;
    }
    
    // If either B or C matches with root's value, report the presence
    // bright setting v1 or v2 as true and return root (Note that if a node
    // is ancestor of other, then that node itself becomes LCA)
    if(A->val == B){
        v1 = true;
        return A;//because we are assuming both keys are present in the tree
    }
    if(A->val == C){
        v2 = true;
        return A;//because we are assuming both keys are present in the tree
    }
    
    //if not, then Look for values in left and right subtrees
    TreeNode* left = findLCA(A->left, B, C, v1, v2);
    TreeNode* right = findLCA(A->right, B, C, v1, v2);
    
    /*The node which has one keright present in its left subtree and the other keright 
    present in right subtree is the LCA*/
    if(left!=NULL && right!=NULL){//left can be either B or C and right can be either C or B, there are no duplicates, so both can't be same
        return A;
    }
    
    /* If both keys lie in left subtree, then left subtree has LCA also, 
    otherwise LCA lies in right subtree.*/
    if(!left && !right){
        return NULL;
    }
    if(left){
        return left;//because we are assuming both keys are present in the tree
    }
    else{
        return right;//because we are assuming both keys are present in the tree
    }
}

//function to check if the node exists in the tree or not 
bool find(TreeNode* A, int K){
    if(A==NULL){
        return false;
    }
    return (A->val==K) || find(A->left, K) || find(A->right, K);
}

int Solution::lca(TreeNode* A, int B, int C) {
    
    // Initialize B and C as not visited
    bool v1 = false;
    bool v2 = false;
    
    //Find lca of B and C using the technique discussed above
    TreeNode* ans = findLCA(A, B, C, v1, v2);
    
    if((v1&&v2) || (v1&&find(ans, C)) || (v2&&find(ans, B))){
      //if both were found in findLca itself, or if v1 was found in findLCA then find v2 LCA, or if v2 was found in findLCA then find v1 LCA
        return ans->val;
    }
    
    return -1;
}
