class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int>vis(V,-1);
        int comp = 0;
        for(int i = 0;i < V;i++){
            if(vis[i]==-1){
                comp++;
                queue<int>q;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){
                    int r = q.front();
                    q.pop();
                    int m = adj[r].size();
                    for(int j = 0;j < m;j++){
                        if(vis[adj[r][j]]==-1){
                            vis[adj[r][j]] = 1;
                            q.push(adj[r][j]);
                        }
                    }
                }
                
            }
        }
        int new_comp = 0;
        vector<int>vis_new(V,-1);
        for(int i = 0;i < V;i++){
            if(vis_new[i]==-1){
                new_comp++;
                queue<int>q;
                q.push(i);
                vis_new[i] = 1;
                while(!q.empty()){
                    int r = q.front();
                    q.pop();
                    int m = adj[r].size();
                    for(int j = 0;j < m;j++){
                        if(vis_new[adj[r][j]]==-1){
                            if((c==r && adj[r][j]==d) || (d==r && adj[r][j]==c)){
                                continue;
                            }
                            vis_new[adj[r][j]] = 1;
                            q.push(adj[r][j]);
                        }
                    }
                }
                
            }
        }
        if(comp==new_comp){
            return 0;
        }
        return 1;
    }
};
