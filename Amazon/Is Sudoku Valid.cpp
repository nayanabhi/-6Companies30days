class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        unordered_set<int>ch;
        int flag = 1;
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(ch.find(mat[i][j])!=ch.end()){
                    flag = 0;
                    break;
                }else if(mat[i][j]){
                    ch.insert(mat[i][j]);
                }
            }
            ch.clear();
        }
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(ch.find(mat[j][i])!=ch.end()){
                    flag = 0;
                    break;
                }else if(mat[j][i]){
                    ch.insert(mat[j][i]);
                }
            }
            ch.clear();
        }
        if(flag==0){
            return 0;
        }
        int x = 0,y = 0;
        while(x<=6 && y<=6){
            for(int i = x;i<x+3;i++){
                for(int j = y;j<y+3;j++){
                    if(ch.find(mat[i][j])!=ch.end()){
                        flag = 0;
                        break;
                    }else if(mat[i][j]){
                         ch.insert(mat[i][j]);
                    }
                }
            }
            ch.clear();
            if(flag==0){
                break;
            }
            if(x<6){
                x+=3;
            }else{
                x = 0;
                y+=3;
            }
        }
        return flag;
    }
};
