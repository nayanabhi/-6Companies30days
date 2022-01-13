class Solution{
  public:
	int minDifference(int arr[], int n)  { 
	    int su = 0;
	    for(int i = 0;i < n;i++){
	        su+=arr[i];
	    }
	    vector<vector<int>>vec(n,vector<int>(su+1,0));
	    for(int j = 0;j < n;j++){
	        for(int k = 1;k < su;k++){
	            if(j==0){
	                if(k==arr[j]){
	                    vec[j][k] = 1;
	                }
	            }else{
	                if(k<arr[j]){
	                    vec[j][k] = vec[j-1][k];
	                }else{
	                    if(vec[j-1][k]==1){
	                        vec[j][k] = 1;
	                    }else{
	                        vec[j][k] = vec[j-1][k-arr[j]];
	                    }
	                }
	            }
	        }
	    }
	    int t = su;
	    for(int r = 0;r<su+1;r++){
	        if(vec[n-1][r]){
	            t = min(t,abs(su-2*r));
	        }
	    }
	    return t;
	}
};
