class Solution{
public:
    string repeat(string s, int n){
        string s1 = s;
        for (int i=1; i<n;i++)
            s += s1;
        return s;
    }
    int digit(string s){
        if(s=="0" || s=="1" || s=="2" || s=="3" || s=="4" || s=="5" || s=="6" || s=="7" || s=="8" || s=="9"){
            return 1;
        }else{
            return 0;
        }
    }
    string decodedString(string s){
        // code here
        string s1 = "";
        int n = s.size();
        string s2 = "";
        string s3 = "";
        stack<string>st;
        for(int i = 0;i < n;i++){
            if(s[i]==']'){
                while(st.top()!="["){
                    s3 = st.top();
                    s2 = s3+s2;
                    st.pop();
                }
                st.pop();
                string s4 = st.top();
                st.pop();
                while(!st.empty() && digit(st.top())){
                    s4 = st.top()+s4;
                    st.pop();
                }
                if(!st.empty()){
                    if(st.top()!="["){
                        st.top()+=repeat(s2,stoi(s4));
                    }else{
                        st.push(repeat(s2,stoi(s4)));
                    }
                }else{
                    st.push(repeat(s2,stoi(s4)));
                }
            }else{
                char s6 = s[i];
                string s7 = "";
                s7+=s6;
                st.push(s7);
            }
            s3 = "";
            s2 = "";
        }
        return st.top();
    }
    
};
