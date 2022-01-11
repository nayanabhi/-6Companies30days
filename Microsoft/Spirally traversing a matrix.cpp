class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>vec;
        int i, k = 0, l = 0;
        while (k < r && l < c) {
            for (i = l; i < c; ++i) {
                vec.push_back(matrix[k][i]);
            }
            k++;
            for (i = k; i < r; ++i) {
                vec.push_back(matrix[i][c - 1]);
            }
            c--;
            if (k < r) {
                for (i = c - 1; i >= l; --i) {
                    vec.push_back(matrix[r - 1][i]);
                }
                r--;
            }
     
            if (l < c) {
                for (i = r - 1; i >= k; --i) {
                    vec.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return vec;
        }
};
