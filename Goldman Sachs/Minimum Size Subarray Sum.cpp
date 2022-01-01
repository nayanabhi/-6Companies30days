class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int s = 0;
        int count = INT_MAX;
        while(r<n){
            s+=nums[r];
            while(s>=target){
                s-=nums[l];
                count = min(count,r-l+1);
                l++;
            }
            r++;
        }
        if(count==INT_MAX){
            return 0;
        }else{
            return count;
        }
    }
};
