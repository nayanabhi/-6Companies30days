class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>>ans;
        vector<string> str = string_list;
        int n = string_list.size();
        for(int i = 0;i < n;i++){
            sort(str[i].begin(),str[i].end());
        }
        unordered_map<string,int>ch;
        int k = 1;
        for(int i = 0;i < n;i++){
            if(ch[str[i]]){
                ans[ch[str[i]]-1].push_back(string_list[i]);
            }else{
                ans.push_back({string_list[i]});
                ch[str[i]] = k++;
            }
        }
        return ans;
    }
};
