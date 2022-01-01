class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here
        if(L1[0]<=L2[0] && L1[1]>=L2[1] && R1[0]>=R2[0] && R1[1]<=R2[1]){
            return 1;   // L2R2 rectangle is inside L1R1 rectangle
        }else if(L2[0]<=L1[0] && L2[1]>=L1[1] && R2[0]>=R1[0] && R2[1]<=R1[1]){
            return 1;   // L1R1 rectangle is inside L2R2 rectangle
        }else if((L1[0]-L2[0])*(R1[0]-L2[0])<=0 && (L1[1]-L2[1])*(R1[1]-L2[1])<=0){
            return 1;  // L2 is inside L1R1 rectangle
        }else if((L1[0]-R2[0])*(R1[0]-R2[0])<=0 && (L1[1]-R2[1])*(R1[1]-R2[1])<=0){
            return 1;  // R2 is inside L1R1 rectangle
        }else if((L1[0]-L2[0])*(R1[0]-L2[0])<=0 && (L1[1]-R2[1])*(R1[1]-R2[1])<=0){
            return 1; // Third vertex of L2R2 is inside L1R1
        }else if((L1[0]-R2[0])*(R1[0]-R2[0])<=0 && (L1[1]-L2[1])*(R1[1]-L2[1])<=0){
            return 1; // Fourth vertex of L2R2 is inside L1R1
        }else if((L2[0]-L1[0])*(R2[0]-L1[0])<=0 && (L2[1]-L1[1])*(R2[1]-L1[1])<=0){
            return 1;  // L1 is inside L2R2 rectangle
        }else if((L2[0]-R1[0])*(R2[0]-R1[0])<=0 && (L2[1]-R1[1])*(R2[1]-R1[1])<=0){
            return 1;  // R1 is inside L2R2 rectangle
        }else if((L2[0]-L1[0])*(R2[0]-L1[0])<=0 && (L2[1]-R1[1])*(R2[1]-R1[1])<=0){
            return 1; // Third vertex of L1R1 is inside L2R2
        }else if((L2[0]-R1[0])*(R2[0]-R1[0])<=0 && (L2[1]-L1[1])*(R2[1]-L1[1])<=0){
            return 1; // Fourth vertex of L1R1 is inside L2R2
        }else if(L2[0]>=L1[0] && L2[0]<=R1[0] && R2[1]<=L1[1] && L2[1]>=L1[1]){
            return 1;  // L1R1 and L2R2 shares a common portion but no vertex
        }else if(L1[0]>=L2[0] && L1[0]<=R2[0] && R1[1]<=L2[1] && L1[1]>=L2[1]){
            return 1; // L1R1 and L2R2 shares a common portion but no vertex
        }else{
            return 0;
        }
    }
};
