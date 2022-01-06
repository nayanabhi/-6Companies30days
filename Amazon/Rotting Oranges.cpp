class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vec(m,vector<int>(n,-1));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j]==2){
                    vector<vector<bool>>vis(m,vector<bool>(n,false));
                    queue<pair<int,int>>st;
                    vis[i][j] = true;
                    vec[i][j] = 0;
                    st.push({i,j});
                    while(!st.empty()){
                        int r = st.front().first;
                        int c = st.front().second;
                        st.pop();
                        if(c>0 && !vis[r][c-1] && grid[r][c-1]==1){
                            if(vec[r][c-1]==-1){
                                vec[r][c-1] = 1+vec[r][c];
                            }else{
                                vec[r][c-1] = min(1+vec[r][c],vec[r][c-1]);
                            }
                            st.push({r,c-1});
                            vis[r][c-1] = true;
                        }
                        if(r>0 && !vis[r-1][c] && grid[r-1][c]==1){
                            if(vec[r-1][c]==-1){
                                vec[r-1][c] = 1+vec[r][c];
                            }else{
                                vec[r-1][c] = min(1+vec[r][c],vec[r-1][c]);
                            }
                            st.push({r-1,c});
                            vis[r-1][c] = true;
                        }
                        if(c<n-1 && !vis[r][c+1] && grid[r][c+1]==1){
                            if(vec[r][c+1]==-1){
                                vec[r][c+1] = 1+vec[r][c];
                            }else{
                                vec[r][c+1] = min(1+vec[r][c],vec[r][c+1]);
                            }
                            st.push({r,c+1});
                            vis[r][c+1] = true;
                        }
                        if(r<m-1 && !vis[r+1][c] && grid[r+1][c]==1){
                            if(vec[r+1][c]==-1){
                                vec[r+1][c] = 1+vec[r][c];
                            }else{
                                vec[r+1][c] = min(1+vec[r][c],vec[r+1][c]);
                            }
                            st.push({r+1,c});
                            vis[r+1][c] = true;
                        }
                    }
                    
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(vec[i][j]==-1){
                    if(grid[i][j]!=0){
                        return -1;
                    }
                }else{
                    ans = max(ans,vec[i][j]);
                }
            }
        }
        return ans;
    }
};
