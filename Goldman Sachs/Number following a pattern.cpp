class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here
        int m = 1;
        int p = 0;
        string s1 = "1";
        int n = S.size();
        for(int i = 0;i < n;i++){
            if(S[i]=='I'){
                s1+=to_string(++m);
                int r = s1.size();
                p = r-1;
            }else{
                int k = s1.size();
                s1 = s1.substr(0,p)+to_string(++m)+s1.substr(p,k+1);
                
            }
        }
        return s1;
    }
};
