void top_sort(int K,vector<int>&indgr,vector<vector<int>>&al,vector<int>&vec1){
    queue<int>q;
    for(int i = 0;i < K;i++){
        if(indgr[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int m = q.front();
        int t = al[m].size();
        vec1.push_back(m);
        q.pop();
        for(int i = 0;i < t;i++){
            indgr[al[m][i]]--;
            if(indgr[al[m][i]]==0){
                q.push(al[m][i]);
            }
        }
    }
}

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int>vec1;
        vector<int>arr(26,-1);
        vector<vector<int>>al(K);
        int temp = 0;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < dict[i].size();j++){
                if(arr[dict[i][j]-'a']==-1){
                    arr[dict[i][j]-'a'] = temp++;
                }
            }
        }
        vector<vector<int>>vec(K,vector<int>(K,-1));
        vector<int>indgr(K,0);
        for(int i = 1;i < N;i++){
            for(int j = 0;j < min(dict[i].size(),dict[i-1].size());j++){
                if(dict[i][j]!=dict[i-1][j]){
                    if(vec[arr[dict[i-1][j]-'a']][arr[dict[i][j]-'a']]==-1){
                        vec[arr[dict[i-1][j]-'a']][arr[dict[i][j]-'a']] = 1;
                        indgr[arr[dict[i][j]-'a']]++;
                        break;
                    }else{
                        break;
                    }
                    
                }
            }
        }
        for(int i = 0;i < K;i++){
            for(int j = 0;j < K;j++){
                if(vec[i][j]==1){
                    al[i].push_back(j);
                }
            }
        }
        top_sort(K,indgr,al,vec1);
        string s;
        for(int i = 0;i < vec1.size();i++){
            for(int j = 0;j < 26;j++){
                if(arr[j]==vec1[i]){
                    s+=('a'+j);
                }
            }
        }
        return s;
        
        
    }
};
