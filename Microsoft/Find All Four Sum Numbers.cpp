class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>>vec;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i = 0;i< n;i++){
            if(i){
                if(arr[i]==arr[i-1]){
                    continue;
                }
            }
            for(int j = i+1;j< n;j++){
                if(j!=(i+1)){
                    if(arr[j]==arr[j-1]){
                        continue;
                    }
                }
                
                int s = arr[i]+arr[j];
                int start = j+1;
                int end = n-1;
                while(start<end){
                    if((arr[start]+arr[end]+s)==k){
                        int p = vec.size();
                        if(p){
                            if(vec[p-1][0]!=arr[i] || vec[p-1][1]!=arr[j] || vec[p-1][2]!=arr[start] || vec[p-1][3]!=arr[end]){
                                vec.push_back({arr[i],arr[j],arr[start],arr[end]});
                            }
                        }else{
                            vec.push_back({arr[i],arr[j],arr[start],arr[end]});
                        }
                        start++;
                    }else if((arr[start]+arr[end]+s)<k){
                        start++;
                    }else{
                        end--;
                    }
                }
            }
        }
        return vec;
    }
};
