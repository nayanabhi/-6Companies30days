class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>vec(n);
        vec[0] = arr[0];
        for(int i = 1;i < n;i++){
            if(i==1){
                vec[i] = max(arr[i],arr[i-1]);
            }else{
                vec[i] = max(arr[i]+vec[i-2],vec[i-1]);
            }
        }
        return vec[n-1];
    }
};
