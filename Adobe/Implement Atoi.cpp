class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int n = str.size();
        long long ans = 0;
        int flag = 0;
        if(str[0]=='-'){
            flag = 1;
        }
        for(int i = flag;i < n;i++){
            if(str[i]<'0' || str[i]>'9'){
                return -1;
            }
            ans*=10;
            ans+=(str[i]-'0');
        }
        if(flag){
            return -ans;
        }
        return ans;
    }
};
