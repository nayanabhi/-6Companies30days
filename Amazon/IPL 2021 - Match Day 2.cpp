class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        deque<int>dq;
        vector<int>vec;
        for(int i = 0;i < n;i++){
            
            if(dq.empty()){
                dq.push_back(i);
            }else{
                while(!dq.empty() && arr[dq.back()]<=arr[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            if(i>=(k-1)){
                while(dq.front()<=(i-k)){
                    dq.pop_front();
                }
                vec.push_back(arr[dq.front()]);
            }
            
        }
        return vec;
    }
};
