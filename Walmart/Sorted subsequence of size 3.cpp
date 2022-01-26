class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        vector<int>pre(N,arr[0]);
        vector<int>post(N,arr[N-1]);
        for(int i = 1;i < N;i++){
            pre[i] = min(pre[i-1],arr[i]);
        }
        for(int j = N-2;j>=0;j--){
            post[j] = max(post[j+1],arr[j]);
        }
        vector<int>vec;
        for(int i = 0;i < N;i++){
            if(pre[i]<arr[i] && post[i] > arr[i]){
                vec.push_back(pre[i]);
                vec.push_back(arr[i]);
                vec.push_back(post[i]);
                break;
                
            }
        }
        return vec;
    }
};
