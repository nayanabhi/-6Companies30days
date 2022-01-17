class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        unordered_map<int,int>ch;
        for(int i = 0;i < n;i++){
            ch[A[i]] = i+1;
        }
        int ans = 1;
        vector<vector<int>>v(n,vector<int>(n,1));
        for(int j = n-1;j >= 0;j--){
            for(int i = j-1;i >= 0;i--){
                if(j==(n-1)){
                    v[i][j] = 2;
                }else{
                    if(ch[A[j]+A[j]-A[i]]){
                        v[i][j] = 1 + v[j][ch[2*A[j]-A[i]]-1];
                    }else{
                        v[i][j] = 2;
                    }
                }
                ans = max(ans,v[i][j]);
            }
        }
        return ans;
    }
};
