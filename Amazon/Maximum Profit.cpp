class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<pair<int,int>>vec;
        vec.push_back({A[0],A[0]});
        int k = 0;
        for(int i = 1;i < N;i++){
            if(A[i]>A[i-1]){
                vec[k].second = A[i];
            }else{
                vec.push_back({A[i],A[i]});
                k++;
            }
        }
        //for(int i = 0;i <= k;i++){
        //    cout<<vec[i].first<<" "<<vec[i].second<<endl;
        //}
        while(k+1>K){
            int ind = 0;
            int mini = INT_MAX;
            for(int i = 0;i <k;i++){
                int maxi = max(vec[i].second-vec[i].first,max(vec[i+1].second-vec[i+1].first,vec[i+1].second-vec[i].first));
                if(maxi==(vec[i].second-vec[i].first)){
                    if(mini>(vec[i+1].second-vec[i+1].first)){
                        mini = (vec[i+1].second-vec[i+1].first);
                        ind = i;
                    }
                }else if(maxi==(vec[i+1].second-vec[i+1].first)){
                    if(mini>(vec[i].second-vec[i].first)){
                        mini = (vec[i].second-vec[i].first);
                        ind = i;
                    }
                }else{
                    if(mini>((vec[i].second-vec[i].first+vec[i+1].second-vec[i+1].first)-(vec[i+1].second-vec[i].first))){
                        mini = ((vec[i].second-vec[i].first+vec[i+1].second-vec[i+1].first)-(vec[i+1].second-vec[i].first));
                        ind = i;
                    }
                }

            }
            int maxi1 = max(vec[ind].second-vec[ind].first,max(vec[ind+1].second-vec[ind+1].first,vec[ind+1].second-vec[ind].first));
            if(maxi1==(vec[ind].second-vec[ind].first)){
                vec.erase(vec.begin()+(ind+1));
                k--;
            }else if(maxi1==(vec[ind+1].second-vec[ind+1].first)){
                vec.erase(vec.begin()+(ind));
                k--;
            }else{
                vec[ind].second = vec[ind+1].second;
                vec.erase(vec.begin()+(ind+1));
                k--;
            }
            
            
        }
        // for(int i = 0;i <= k;i++){
        //     cout<<vec[i].first<<" "<<vec[i].second<<endl;
        // }
        int ans = 0;
        for(int i = 0;i <= k;i++){
            ans+=(vec[i].second-vec[i].first);
            //cout<<vec[i].first<<" "<<vec[i].second<<endl;
        }
        return ans;
    }
    
};
