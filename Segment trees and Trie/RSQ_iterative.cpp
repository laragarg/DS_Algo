class NumArray {
public:
    vector<int> A;
    int n;
    vector<int> tree;
    NumArray(vector<int>& nums) {
        A = nums;
        n = A.size();
        build();
    }
    void build(){
        tree.resize(2*n);
        for(int i=n, j=0; i<2*n; i++, j++){
            tree[i] = A[j];//store the leaves
        }
        for(int i=n-1; i>0; i--){
            tree[i] = tree[i*2] + tree[i*2 + 1];//build the parent nodes from bottom nodes(leaves)
        }
    }
    void update(int i, int val) {
        i += n;//leaf node index(first n indices in tree are parents)
        tree[i] = val;//update the leaf node first of all
        while(i > 0){//update the parent nodes of the leaf node
            int left = i;
            int right = i;
            if(i % 2 == 0){
                right = i + 1;
            }
            else{
                left = i - 1;
            }
            tree[i/2] = tree[left] + tree[right];//i/2 is the immediate parent of i
            i = i/2;
        }
    }
    
    int sumRange(int i, int j) {
        i += n;
        j += n;
        int ans = 0;
        while(i <= j){
            if(i%2 == 1){
                ans += tree[i];
                i++;
            }
            if(j%2 == 0){
                ans += tree[j];
                j--;
            }
            i = i/2;
            j = j/2;
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */