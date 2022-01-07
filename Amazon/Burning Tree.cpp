class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        Node* my_target;
        unordered_map<Node*,vector<Node*>>ch;
        stack<Node*>st;
        st.push(root);
        while(!st.empty()){
            Node *temp = st.top();
            if(temp->data==target){
                my_target = temp;
            }
            st.pop();
            if(temp->left){
                ch[temp].push_back(temp->left);
                ch[temp->left].push_back(temp);
                st.push(temp->left);
            }
            if(temp->right){
                ch[temp].push_back(temp->right);
                ch[temp->right].push_back(temp);
                st.push(temp->right);
            }
        }
        int ans = 0;
        unordered_map<Node*,int>vis;
        unordered_map<Node*,int>level;
        queue<Node*>q;
        q.push(my_target);
        level[my_target]++;
        vis[my_target] = 1;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            ans = max(ans,level[temp]);
            for(int i = 0;i < ch[temp].size();i++){
                if(vis[ch[temp][i]]==0){
                    level[ch[temp][i]] = level[temp]+1;
                    vis[ch[temp][i]]++;
                    q.push(ch[temp][i]);
                }
            }
        }
        return ans-1;
        
    }
};
