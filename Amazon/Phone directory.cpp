class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        int r = s.size();
        unordered_map<string,int>ch;
        vector<bool>vec1(n,true);
        for(int i = 0;i < n;i++){
            if(ch[contact[i]]){
                vec1[i] = false;
            }else{
                ch[contact[i]]++;
            }
        }
        vector<vector<string>>vec(r);
        for(int j = 0;j < r;j++){
            for(int i = 0;i < n;i++){
                int flag = 1;
                for(int k = 0;k <=j;k++){
                    if(k>=(contact[i].size())){
                        flag = 0;
                        break;
                    }else{
                        if(s[k]!=contact[i][k]){
                            flag = 0;
                            break;
                        }
                    }
                }
                if(flag && vec1[i]){
                    vec[j].push_back(contact[i]);
                }
            }
            int e = vec[j].size();
            if(e==0){
                vec[j].push_back("0");
            }else{
                sort(vec[j].begin(),vec[j].end());
            }
        }
        return vec;
    }
};
