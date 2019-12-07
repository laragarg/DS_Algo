vector<vector<int> >A;
int n, m;
int histo(int i){
    int ans = 0;
    int j=0;
    while(j < m){
        if(s.empty() || A[i][j] >= A[i][s.top()]){
            s.push(j);
            j++;
        }
        else{
            int width = s.top();
            s.pop();
            int ht = A[i][width];
            int area = 0;
            if(s.empty()){
                area = ht*width;
            }
            else{
                area = ht*(width - s.top() - 1);
            }
            ans = max(ans, area);
        }
    }
    while(!s.empty()){
        int width = s.top();
        s.pop();
        int ht = A[i][width];
        int area = 0;
        if(s.empty()){
            area = ht*width;
        }
        else{
            area = ht*(width - s.top() -1);
        }
        ans = max(ans, area);
    }
    return ans;
}
int main(){
    cin>>n>>m;
    A.clear();
    A.resize(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>A[i][j];
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0){
                break;
            }
            else{
                if(A[i][j] == 1){
                    A[i][j] += A[i-1][j];
                }
            }
        }
        ans = max(ans, histo(i));
    }
    return ans;
}