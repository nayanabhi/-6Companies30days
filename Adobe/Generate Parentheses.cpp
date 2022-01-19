class Solution
{
    public:
    
    vector<string> all_possible(int n){
        if(n==1){
            return {"(",")"};
        }else{
            vector<string>vec = all_possible(n-1);
            int m = vec.size();
            vector<string>vec1;
            for(int i = 0;i < m;i++){
                vec1.push_back(vec[i]+'(');
                vec1.push_back(vec[i]+')');
            }
            return vec1;
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string>all_pos = all_possible(2*n);
        int m = all_pos.size();
        vector<string>vec;
        for(int i = 0;i < m;i++){
            string s = all_pos[i];
            int g = s.size();
            stack<char>st;
            int flag = 1;
            for(int j = 0;j < g;j++){
                if(s[j] == '('){
                    st.push(s[j]);
                }else{
                    if(!st.empty()){
                        st.pop();
                    }else{
                        flag = 0;
                        break;
                    }
                }
            }
            if(st.empty() && flag){
                vec.push_back(s);
            }
            
        }
        return vec;
        
    }
};
