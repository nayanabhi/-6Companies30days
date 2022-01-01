class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long p = 1;
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r<n){
            p*=a[r];
            while(p>=k){
                p/=a[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
            
        }
        
        return ans;
    }
};
