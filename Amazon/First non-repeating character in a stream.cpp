class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string s;
		    int n = A.size();
		    vector<int>vec(26,0);
		    for(int i = 0;i < n;i++){
		        if(vec[(A[i]-'a')]){
		            vec[(A[i]-'a')] = -1;
		        }else if(vec[(A[i]-'a')]==0){
		            vec[(A[i]-'a')] = i+1;
		        }
		        int flag = 1;
		        int m = n+1;
		        int ind;
		        for(int j = 0;j < 26;j++){
		            if(vec[j]>0){
		                if(m>vec[j]){
		                    m = vec[j];
		                    ind = j;
		                    flag = 0;
		                }
		                
		            }
		        }
		        if(flag){
		            s+='#';
		        }else{
		            char c = 'a';
		            c+=(ind);
		            s+=c;
		        }
		    }
		    return s;
		    
		}

};
