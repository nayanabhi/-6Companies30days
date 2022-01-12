class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        unordered_map<int,vector<char>>ch;
        char c = 'a';
        int cnt = 0;
        vector<string>v;
        for(int i = 2;i<=9;i++){
            if(i==9 || i==7){
                for(int j = 0;j < 4;j++){
                    ch[i].push_back(c+cnt);
                    cnt++;
                }
            }else{
                for(int j = 0;j < 3;j++){
                    ch[i].push_back(c+cnt);
                    cnt++;
                }
            }
        }
        if(N==1){
            for(int i = 0;i < ch[a[0]].size();i++){
                char c1 = ch[a[0]][i];
                string s1 = "";
                s1+=c1;
                v.push_back(s1);
            }
            return v;
        }else{
            vector<string>vec = possibleWords(a+1,N-1);
            for(int i = 0;i < ch[a[0]].size();i++){
                for(int j = 0;j < vec.size();j++){
                    char c1 = ch[a[0]][i];
                    string s1= "";
                    s1+=c1;
                    v.push_back(s1+vec[j]);
                }
            }
            return v;
        }
        
    }
};
