class Solution {
public:
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
        vector<vector<int>>vec(n,vector<int>(n));
        for(int i = 0;i < n;i++){
            vec[i][i] = A[i];
        }
        for(int i = 1;i < n;i++){
            for(int j = 0;j < n;j++){
                int row = j;
                int col = j+i;
                if(row>=n || col>=n){
                    break;
                }
                vec[row][col] = max(A[j]-vec[row+1][col],A[j+i]-vec[row][col-1]);
            }
        }
        int s = 0;
        for(int i = 0;i < n;i++){
            s+=A[i];
        }
        return (s+vec[0][n-1])/2;
    }
};
