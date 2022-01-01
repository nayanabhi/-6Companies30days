//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

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

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends
