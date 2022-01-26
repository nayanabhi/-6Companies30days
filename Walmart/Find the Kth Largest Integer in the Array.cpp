class Solution {
public:
    static bool comp(string a,string b){
        if(a.size()==b.size()){
            return a<b;
        }else{
            return a.size()<b.size();
        }
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),comp);
        int n = nums.size();
        return nums[n-k];
    }
};
