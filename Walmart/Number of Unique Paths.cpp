class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>>vec(a,vector<int>(b,1));
        for(int i = 1;i < a;i++){
            for(int j = 1;j < b;j++){
                vec[i][j] = vec[i-1][j] + vec[i][j-1];
            }
        }
        return vec[a-1][b-1];
    }
};
