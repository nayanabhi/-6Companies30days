class Solution{
public:
    int minSteps(int D){
        // code here
        int ans = ceil((sqrt(1+8*D)-1)/2);
        int p = ans*(ans+1)/2 - D;
        while(p&1){
            ans++;
            p = ans*(ans+1)/2 - D;
            
        }
        return ans;
        
    }
};
