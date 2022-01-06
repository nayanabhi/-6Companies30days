class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        return 1+((K-1+(M-1)%N))%(N);
    }
};
