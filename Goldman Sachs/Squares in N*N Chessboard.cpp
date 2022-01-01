class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        // code here
        long long ans = N;
        ans*=(N+1);
        ans*=(2*N+1);
        ans/=6;
        return ans;
    }
};
