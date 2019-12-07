//Brute Force
class Solution {
public:
    int minm(TreeNode* root){
        if(!root){
            return INT_MAX;
        }
        if(!root->left && !root->right){
            return root->val;
        }
        return min(root->val, min(minm(root->left), minm(root->right) ) );
    }
    int maxm(TreeNode* root){
        if(!root){
            return INT_MIN;
        }
        if(!root->left && !root->right){
            return root->val;
        }
        return max(root->val, max(maxm(root->left), maxm(root->right) ) );
    }
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        if(!root->left && !root->right){
            return true;
        }
        // int a = maxm(root->left);
        // int b = minm(root->right);
        // cout<<"a = "<<a<<"root->val = "<<root->val<<" b = "<<b<<endl;

        //extra OR for the edge case when one of the child is missing and root->val itself is INT_MIN or INT_MAX
        if( (root->val > maxm(root->left) && root->val < minm(root->right) ) || (!root->left && root->val < minm(root->right )) || (!root->right && root->val > maxm(root->left)) ){
            // cout<<"here";
            return isValidBST(root->left) && isValidBST(root->right);
        }
        return false;
    }
};

//Modified
class Solution {
public:
    bool func(TreeNode* root, TreeNode* l, TreeNode* r){
        if(!root){
            return true;
        }
        if(l){
            if(root->val <= l->val){
                return false;
            }
        }
        if(r){
            if(root->val >= r->val){
                return false;
            }
        }
        return func(root->left, l, root) && func(root->right, root, r);
    }
    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left && !root->right)){
            return true;
        }
        return func(root, NULL, NULL);//current root, lower bound and upper bound values
    }
};