class Solution{
public:
    void swap(int &a,int &b){
        int t = a;
        a = b;
        b = t;
    }
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2];
        long long sum = 0;
        long long sum1 = n;
        sum1*=(n+1);
        sum1/=2;
        long long x = 0;
        for(int i = 0;i < n;i++){
            int k = arr[i];
            if(arr[k-1]!=k){
                swap(arr[i],arr[k-1]);
                i--;
            }
        }
        for(int i = 0;i < n;i++){
            if(arr[i]!=(i+1)){
                ans[0] = arr[i];
                ans[1] = i+1;
                break;
            }
        }
        return ans;
    }
};
