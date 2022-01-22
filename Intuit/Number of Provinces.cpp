class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        vector<vector<int>>al(n);
        vector<bool>vis(n,false);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(isConnected[i][j] && i!=j){
                    al[i].push_back(j);
                }
            }
        }
        for(int i = 0;i < n;i++){
            if(!vis[i]){
                queue<int>q;
                q.push(i);
                vis[i] = true;
                cnt++;
                while(!q.empty()){
                    int t = q.front();
                    q.pop();
                    int k = al[t].size();
                    for(int j = 0;j < k;j++){
                        if(!vis[al[t][j]]){
                            q.push(al[t][j]);
                            vis[al[t][j]] = true;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
