/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

    }class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here
        struct Node  *temp = head;
        int m = N;
        int n = M-1;
        while(temp){
            while(temp && n--){
                temp = temp->next;
            }
            int flag = 1;
            while(temp && temp->next && m--){
                temp->next = temp->next->next;
                if(m==0){
                    temp = temp->next;
                    flag = 0;
                }
            }
            if(flag){
                break;
            }
            m = N;
            n = M-1;
        }
        
};
