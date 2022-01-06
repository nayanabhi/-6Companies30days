class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int>pre_inc(n,1);
        vector<int>suf_dec(n,1);
        for(int i = 1;i < n;i++){
            if(arr[i]>arr[i-1]){
                pre_inc[i] = 1+pre_inc[i-1];
            }
        }
        for(int i = n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                suf_dec[i] = 1+suf_dec[i+1];
            }
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(pre_inc[i]!=1 && suf_dec[i]!=1){
                ans = max(ans,pre_inc[i]+suf_dec[i]-1);
            }
            
        }
        return ans>=3?ans:0;
        
    }
};
