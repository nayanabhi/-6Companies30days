int count(Node* root,int &cnt,int X){
    if(root==NULL){
        return 0;
    }else{
        int l = count(root->left,cnt,X);
        int r = count(root->right,cnt,X);
        if((l+r+root->data)==X){
            cnt++;
        }
        return l+r+root->data;
    }
}
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int cnt = 0;
	count(root,cnt,X);
	return cnt;
}
