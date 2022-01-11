class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    int cnt = 1;
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        if(r>0){
                            if(grid[r-1][c]){
                                grid[r-1][c] = 0;
                                q.push({r-1,c});
                                cnt++;
                            }
                        }
                        if(r>0 && c>0){
                            if(grid[r-1][c-1]){
                                grid[r-1][c-1] = 0;
                                q.push({r-1,c-1});
                                cnt++;
                            }
                        }
                        if(r>0 && c<m-1){
                            if(grid[r-1][c+1]){
                                grid[r-1][c+1] = 0;
                                q.push({r-1,c+1});
                                cnt++;
                            }
                        }
                        if(r<n-1){
                            if(grid[r+1][c]){
                                grid[r+1][c] = 0;
                                q.push({r+1,c});
                                cnt++;
                            }
                        }
                        if(r<n-1 && c>0){
                            if(grid[r+1][c-1]){
                                grid[r+1][c-1] = 0;
                                q.push({r+1,c-1});
                                cnt++;
                            }
                        }
                        if(r<n-1 && c<m-1){
                            if(grid[r+1][c+1]){
                                grid[r+1][c+1] = 0;
                                q.push({r+1,c+1});
                                cnt++;
                            }
                        }
                        if(c>0){
                            if(grid[r][c-1]){
                                grid[r][c-1] = 0;
                                q.push({r,c-1});
                                cnt++;
                            }
                        }
                        if(c<m-1){
                            if(grid[r][c+1]){
                                grid[r][c+1] = 0;
                                q.push({r,c+1});
                                cnt++;
                            }
                        }
                        
                    }
                    count = max(cnt,count);
                }
            }
        }
        return count;
    }
};
