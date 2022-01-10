// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int top_sort(int N,vector<vector<int>> &adj_list,vector<int> &indegree,queue<int>&q){
        vector<int>vis(N,-1);
        for(int i = 0;i < N;i++){
            if(q.empty()){
                return 0;
            }
            int a = q.front();
            vis[a] = 1;
            q.pop();
            int n = adj_list[a].size();
            for(int i = 0;i < n;i++){
                indegree[adj_list[a][i]]--;
                if(indegree[adj_list[a][i]]==0 && vis[adj_list[a][i]]==-1){
                    q.push(adj_list[a][i]);
                }
            }
        }
        return 1;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    int p = prerequisites.size();
	    vector<vector<int>>adj_list(N);
	    vector<int>indegree(N);
	    for(int i = 0;i < p;i++){
	        adj_list[prerequisites[i].second].push_back(prerequisites[i].first);
	        indegree[prerequisites[i].first]++;
	    }
	    queue<int>q;
	    for(int i = 0;i < N;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    int ans = top_sort(N,adj_list,indegree,q);
	    if(ans){
	        return true;
	    }else{
	        return false;
	    }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
