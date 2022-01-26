class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
       //Your code here
       int MOD = 1000000007;
       if(!R){
           return 1;
       }else if(R==1){
           return N%MOD;
       }
       else{
           if(R&1){
               long long x = N%MOD;
               x*=x;
               x%=MOD;
               return ((power(x,R/2)%MOD)*(N%MOD))%MOD;
           }else{
               long long x = N%MOD;
               x*=x;
               x%=MOD;
               return power(x,R/2)%MOD;
           }
       }
       
        
    }

};
