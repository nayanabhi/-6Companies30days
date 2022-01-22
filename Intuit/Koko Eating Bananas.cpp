class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int end = 1e9;
        while(start<end){
            int mid = start+(end-start)/2;
            int cnt = 0;
            for(int i = 0;i < n;i++){
                if(piles[i]%mid){
                    cnt+=(piles[i]/mid+1);
                }else{
                    cnt+=(piles[i]/mid);
                }
            }
            if(cnt<=h){
                end = mid;
            }else{
                start = mid+1;
            }
        }
        return end;
    }
};
