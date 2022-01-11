class Solution
{
    public:
    //Function to connect nodes at same level.
    
    void connect(Node *root)
    {
       // Your Code Here
       Node* temp = root;
       temp->nextRight = NULL;
       unordered_map<Node*,int>ch;
       ch[temp] = 1;
       vector<Node*>lev_ord;
       queue<Node*>q;
       q.push(temp);
       lev_ord.push_back(temp);
       while(!q.empty()){
           Node*t = q.front();
           q.pop();
           if(t->left){
               ch[t->left] = ch[t]+1;
               lev_ord.push_back(t->left);
               q.push(t->left);
           }
           if(t->right){
               ch[t->right] = ch[t]+1;
               lev_ord.push_back(t->right);
               q.push(t->right);
           }
       }
       int y = lev_ord.size();
       for(int i = 1;i < y-1;i++){
           if(ch[lev_ord[i]] == ch[lev_ord[i+1]]){
               lev_ord[i]->nextRight = lev_ord[i+1];
           }else{
               lev_ord[i]->nextRight = NULL;
           }
       }
    }    
      
};
