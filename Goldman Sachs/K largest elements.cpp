class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        priority_queue<int, vector<int>, greater<int> >q;
        for(int i = 0;i < k;i++){
            q.push(arr[i]);
        }
        vector<int>vec(k);
        for(int i = k;i < n;i++){
            if(arr[i]>q.top()){
                q.pop();
                q.push(arr[i]);
            }
        }
        for(int i = k-1;i >=0;i--){
            int p = q.top();
            vec[i] = p;
            q.pop();
        }
        return vec;
    }
};
