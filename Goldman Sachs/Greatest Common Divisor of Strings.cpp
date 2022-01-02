class Solution {
public:
    string repeat(string s,int t){
        string s1 = "";
        while(t--){
            s1+=s;
        }
        return s1;
    }
    string gcdOfStrings(string str1, string str2) {
        unordered_map<string,int>ch;
        string ans1 = "";
        int n = str1.size();
        int m = str2.size();
        string str11 = "";
        string str21 = "";
        for(int i = 0;i <n;i++){
            str11+=str1[i];
            if(n%(i+1)==0){
                if(repeat(str11,n/(i+1))==str1){
                    ch[str11]++;
                }
            }
        }
        for(int i = 0;i <m;i++){
            str21+=str2[i];
            if(m%(i+1)==0){
                if(repeat(str21,m/(i+1))==str2){
                    if(ch[str21]){
                        ans1 = str21;
                    }
                }
            }
        }
        return ans1;
    }
};
