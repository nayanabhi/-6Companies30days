class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<int>p;
        int start = 0,end = -1;
        int cur_sum = 0;
        for(int i = 0;i < n;i++){
            if(cur_sum+arr[i]>s){
                cur_sum-=arr[start];
                start++;
                i--;
            }else if(cur_sum+arr[i]<s){
                cur_sum+=arr[i];
                end++;
            }else{
                p.push_back(start+1);
                p.push_back(i+1);
                return p;
            }
            
        }
        p.push_back(-1);
        return p;
    }
};
