class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int s = 0;
        for(int i = 0;i < N;i++){
            s+=arr[i];
        }
        if(s&1){
            return 0;
        }else{
           vector<vector<int>>dp(N,vector<int>(s+1,1));
           for(int i = 0;i < N;i++){
               for(int j = 1;j <= s;j++){
                   if(arr[i]==j){
                       dp[i][j] = 1;
                   }else if(i && dp[i-1][j]){
                       dp[i][j] = 1;
                   }else if(i && j>arr[i]){
                       if(dp[i-1][j-arr[i]]){
                           dp[i][j] = 1;
                       }else{
                           dp[i][j] = 0;
                       }
                   }else{
                       dp[i][j] = 0;
                   }
                   if(j==s/2){
                       if(dp[i][j]){
                           return 1;
                       }
                   }
               }
           }
           return 0;
        }
        
    }
};
