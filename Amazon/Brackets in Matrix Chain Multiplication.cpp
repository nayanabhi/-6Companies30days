class Solution{
public:
        string matrixChainOrder(int p[], int n){
        // code here
        if(n==2){
            return "A";
        }
        vector<vector<long long>>vec(n-1,vector<long long>(n-1,INT_MAX));
        vector<vector<string>>vec1(n-1,vector<string>(n-1));
        char c = 'A';
        for(int i = 1;i<n-1;i++){
            for(int j = 0;j<n-2;j++){
                if((j+i)>(n-2)){
                    break;
                }
                if(i==1){
                    vec[j][j+i] = p[j]*p[j+1]*p[j+2];
                    vec1[j][j+i]+="(";
                    vec1[j][j+i]+=(c+j);
                    vec1[j][j+i]+=(c+j+i);
                    vec1[j][j+i]+=")";
                }else{
                    int ans;
                    for(int k = j;k < j+i;k++){
                        if(k==j){
                            if(vec[j][j+i]>(vec[k+1][j+i]+p[j]*p[k+1]*p[j+i+1])){
                                ans = k;
                                vec[j][j+i] = (vec[k+1][j+i]+p[j]*p[k+1]*p[j+i+1]);
                                
                                vec1[j][j+i] = "";
                                vec1[j][j+i]+="(";
                                vec1[j][j+i]+=(c+j);
                                vec1[j][j+i]+=vec1[k+1][j+i];
                                vec1[j][j+i]+=")";
                            }
                            //vec[j][j+i] = min(vec[j][j+i],vec[k+1][j+i]+p[j]*p[k+1]*p[j+i+1]);
                        }
                        else if((k+1)==(j+i)){
                            if(vec[j][j+i]>(vec[j][k]+p[j]*p[k+1]*p[j+i+1])){
                                ans = k;
                                vec[j][j+i] = (vec[j][k]+p[j]*p[k+1]*p[j+i+1]);
                                vec1[j][j+i] = "(";
                                vec1[j][j+i]+=vec1[j][k];
                                vec1[j][j+i]+=(c+j+i);
                                vec1[j][j+i]+=")";
                                
                            }
                            //vec[j][j+i] = min(vec[j][j+i],vec[j][k]+p[j]*p[k+1]*p[j+i+1]);
                        }else{
                            if(vec[j][j+i]>(vec[j][k]+vec[k+1][j+i]+p[j]*p[k+1]*p[j+i+1])){
                                
                                ans = k;
                                vec[j][j+i] = (vec[j][k]+vec[k+1][j+i]+p[j]*p[k+1]*p[j+i+1]);
                                vec1[j][j+i] = "";
                                vec1[j][j+i]+="(";
                                vec1[j][j+i]+=vec1[j][k];
                                vec1[j][j+i]+=vec1[k+1][j+i];
                                vec1[j][j+i]+=")";
                            }
                            //vec[j][j+i] = min(vec[j][j+i],vec[j][k]+vec[k+1][j+i]+p[j]*p[k+1]*p[j+i+1]);
                        }
                        
                    }
                }
            }
        }
        
        return vec1[0][n-2];
        
        
    }
};
