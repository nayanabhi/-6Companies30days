class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>vec(n,vector<int>(n));
        for(int i = 0;i < n;i++){
            vec[i][i] = piles[i];
        }
        for(int i = 1;i < n;i++){
            for(int j = 0;j < n;j++){
                int row = j;
                int col = j+i;
                if(row>=n || col>=n){
                    break;
                }
                vec[row][col] = max(piles[j]-vec[row+1][col],piles[j+i]-vec[row][col-1]);
            }
        }
        if(vec[0][n-1]>0){
            return true;
        }else{
            return false;
        }
    }
};
