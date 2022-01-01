class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        vector<int>vec(k);
        int n = nums.size();
        for(int i = 0;i < n;i++){
            vec[nums[i]%k]++;
        }
        int flag = 1;
        for(int i = 0;i < ((k/2)+(k%2));i++){
            if(i==0){
                if(vec[i]&1){
                    flag = 0;
                    break;
                }
            }else{
                if(vec[i]!=vec[k-i]){
                    flag = 0;
                    break;
                }
            }
        }
        return flag;
    }
};
