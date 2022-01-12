class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int>vec(n,1);
       stack<int>st;
       st.push(0);
       for(int i = 1;i < n;i++){
           if(price[i]<price[st.top()]){
               st.push(i);
           }else{
               while(!st.empty() && price[i]>=price[st.top()]){
                   vec[i]+=vec[st.top()];
                   st.pop();
               }
               st.push(i);
           }
       }
       return vec;
    }
};
