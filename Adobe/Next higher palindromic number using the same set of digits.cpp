class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        vector<int>vec(10);
        int n = N.size();
        for(int i = 0;i < n/2;i++){
            vec[N[i]-'0'] = i+1;
        }
        int flag = 0;
        for(int i = n/2-2;i>=0;i--){
            int t = N[i]-'0';
            for(int j = 0;j < 10;j++){
                if(t<j && vec[j] > i+1){
                    char d = N[i];
                    char c = '0'+j;
                    N[i] = c;
                    N[vec[j]-1] = d;
                    flag = i+1;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            return "-1";
        }
        sort(N.begin()+flag,N.begin()+n/2);
        string s = N.substr(0,n/2);
        string r = s;
        reverse(r.begin(),r.end());
        if(n&1){
            s+=N[n/2];
        }
        return s+r;
        
    }
};
