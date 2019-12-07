
//M1
int bfs(vector<vector<int>>& A, int a, int b, int n, int m){
    int ans = INT_MAX;
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, {a, b}});
    vis[a][b] = true;
   
    while(!pq.empty()){
        PII temp = pq.top();
        pq.pop();
        int a1 = temp.second.first;
        int b1 = temp.second.second;
        int temp_val = temp.first; 
        for(int i=-1; i<=1; i++){
            int di = a1 + i;
            if(di<0||di>=n){
                continue;
            }
            for(int j=-1; j<=1; j++){
                if(abs(i)==abs(j)){
                    continue;
                }
                int dj = b1 + j;
                if(dj<0||dj>=m){
                    continue;
                }
                if (!vis[di][dj]){
                    vis[di][dj] = true;
                    if(A[di][dj]==1){
                        ans = min(temp_val, ans);
                    } 
                    else if(A[di][dj]==0){
                        pq.push({temp_val+1, {di, dj}});
                    } 
                    else{
                        pq.push({temp_val, {di, dj}});
                    }
                }
            }
        }
    }
    return ans;
}

//M2

class Solution {
    int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};
public:
    //here 1 represents hurdle
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        queue<pair<int, int> > q;
        q.push({0, 0});//current co ordinates
        grid[0][0] = 1;
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            ans++;
            for(int i = 0; i < sz; ++i) {
                pair<int, int> temp = q.front();
                int a = temp.first, b = temp.second;
                q.pop();
                if(a == n - 1 && b == n - 1)
                    return ans;
                for(int k = 0; k < 8; k++){
                    int a1 = a + di[k], b1 = b + dj[k];
                    //just go the valid paths, don't write the unvalid paths' condition
                    if(a1 >= 0 && a1 < n && b1 >= 0 && b1 < n && grid[a1][b1] == 0) {
                        q.push({a1, b1});
                        grid[a1][b1] = 1;//to mark it as visited
                    }
                }
            }
        }
        return -1;//if no path found
    }
};