class Solution
{
    public:
    
    void preorder(Node *root,vector<int>&vec){
        if(root){
            vec.push_back(root->data);
            preorder(root->left,vec);
            preorder(root->right,vec);
            
        }else{
            vec.push_back(0);
        }
        
    }
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>vec;
        preorder(root,vec);
        return vec;
    }
    
    //Function to deserialize a list and construct the tree.
    int i=0;
    Node * deSerialize(vector<int> &A)
    {
        int n = A.size();
        if(n == 0){
            return NULL;
        }
        if(A[i] == 0){
            i++;
            return NULL;
        }
        Node *root = new Node(A[i++]);
        root->left = deSerialize(A);
        root->right = deSerialize(A);
        return root;
    }

};
