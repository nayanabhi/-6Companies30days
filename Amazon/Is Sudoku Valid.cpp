class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        int flag = 1;
        for(int i = 0;i < 9;i++){
            int vis[10]  {0};
            for(int j = 0;j < 9;j++){
                if(vis[mat[i][j]]){
                    flag = 0;
                    break;
                }else if(mat[i][j]){
                    vis[mat[i][j]] = 1;
                }
            }
        }
        for(int i = 0;i < 9;i++){
            int vis[10] = {0};
            for(int j = 0;j < 9;j++){
                if(vis[mat[j][i]]){
                    flag = 0;
                    break;
                }else if(mat[j][i]){
                    vis[mat[j][i]]++;
                }
            }
        }
        if(flag==0){
            return 0;
        }
        int x = 0,y = 0;
        while(x<=6 && y<=6){
            int vis[10] = {0};
            for(int i = x;i<x+3;i++){
                for(int j = y;j<y+3;j++){
                    if(vis[mat[i][j]]){
                        return 0;
                    }else if(mat[i][j]){
                         vis[mat[i][j]]++;
                    }
                }
            }
            if(x<6){
                x+=3;
            }else{
                x = 0;
                y+=3;
            }
        }
        return 1;
    }
};
