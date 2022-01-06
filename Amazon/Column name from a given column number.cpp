class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string s;
        while(n){
            int m = n%26;
            if(m==0){
                m = 26;
            }
            s+=('A'+(m-1));
            if(n%26){
                n/=26;
            }else{
                n/=26;
                n-=1;
            }
            
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
