class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int su(Node *node){
        if(!node){
            return 0;
        }else{
            int l = su(node->left);
            int r = su(node->right);
            int m = node->data;
            node->data = (l+r);
            return m+node->data;
        }
    }
    void toSumTree(Node *node)
    {
        // Your code here
        su(node);
    }
};
