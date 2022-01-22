class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vec;
        int n = numCourses;
        vector<vector<int>>al(n);
        vector<int>idg(n,0);
        vector<int>vis(n,false);
        int r = prerequisites.size();
        for(int i = 0;i < r;i++){
            al[prerequisites[i][1]].push_back(prerequisites[i][0]);
            idg[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i = 0;i < n;i++){
            if(!idg[i]){
                q.push(i);
                vis[i] = true;
            }
        }
        while(!q.empty()){
            int t = q.front();
            vec.push_back(t);
            q.pop();
            int k = al[t].size();
            for(int j = 0;j < k;j++){
                if(!vis[al[t][j]]){
                    idg[al[t][j]]--;
                    if(!idg[al[t][j]]){
                        q.push(al[t][j]);
                        vis[al[t][j]] = true;
                    }
                }
            }
            
        }
        int c = vec.size();
        if(c^n){
            return {};
        }else{
            return vec;
        }
        
        
    }
};
