class Solution{
  public:
	int minDifference(int arr[], int n)  { 
	    if(n==1){
	        return arr[0];
	    }
	    if(n==2){
	        return abs(arr[1]-arr[0]);
	    }
	    // Your code goes here
	    int ans = INT_MAX;
	    int s = 0;
	    for(int i = 0;i < n;i++){
	        s+=arr[i];
	    }
	    sort(arr,arr+n);
	    vector<vector<int>>dp(n,vector<int>(s+1,-1));
	    for(int i = 0;i < n;i++){
	        for(int j = 0;j < s;j++){
	            if(i){
	                if(j>arr[i] && (dp[i-1][j-arr[i]]==1)){
	                    dp[i][j] = 1;
	                    ans = min(ans,abs(j-(s-j)));
	                    continue;
	                }
	                if((dp[i-1][j]==1)){
	                    dp[i][j] = 1;
	                    ans = min(ans,abs(j-(s-j)));
	                    continue;
	                }
	                if(j==arr[i]){
	                    dp[i][j] = 1;
	                    ans = min(ans,abs(j-(s-j)));
	                    continue;
	                }
	            }else{
	                if(j==arr[i]){
	                    dp[i][j] = 1;
	                    ans = min(ans,abs(j-(s-j)));
	                }
	            }
	        }
	    }
	    return ans;
	}
};
