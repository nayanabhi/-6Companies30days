class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string,int>ch;
        for(int i = 0;i < n;i++){
            ch[arr[i]]++;
        }
        int maxi = INT_MIN;
        string s = "";
        for(int i = 0;i < n;i++){
            if(ch[arr[i]]>maxi){
                maxi = ch[arr[i]];
                s = arr[i];
            }else if(ch[arr[i]]==maxi){
                if(s>arr[i]){
                    s = arr[i];
                }
            }
        }
        vector<string>v;
        v.push_back(s);
        v.push_back(to_string(maxi));
        return v;
    }
};
