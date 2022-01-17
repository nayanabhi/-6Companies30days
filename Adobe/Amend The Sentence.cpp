class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string s1;
        int n = s.size();
        for(int i = 0;i < n;i++){
            if(isupper(s[i]) && i){
                s[i] = s[i]+32;
                s1+=" ";
                s1+=s[i];
            }else{
                if(i){
                    s1+=s[i];
                }else{
                    if(isupper(s[i])){
                        s[i] = s[i]+32;
                        s1+=s[i];
                    }else{
                        s1+=s[i];
                    }
                    
                }
                
            }
        }
        return s1;
    }
};
