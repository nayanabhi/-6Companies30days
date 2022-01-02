class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    int n = str.size();
		    if(n==0){
		        return 1;
		    }
		    int u = 1000000007;
		    vector<int>vec(n,1);
		    for(int i = n-2;i >= 0;i--){
		        if(str[i]=='1'){
		            if(str[i+1]=='0'){
		                vec[i] = vec[i+1];
		            }else{
		                if(i==(n-2)){
    		                vec[i] = vec[i+1]+1;
    		            }else{
    		                if(str[i+2]!='0'){
    		                    vec[i] = vec[i+1]+vec[i+2];
    		                }else{
    		                    vec[i] = vec[i+1];
    		                }
    		            }
		            }
		            
		        }else if(str[i]=='2'){
    		            if(str[i+1]>'0' && str[i+1]<='6'){
    		                if(i==(n-2)){
		                        vec[i] = vec[i+1]+1;
        		            }else{
        		                if(str[i+2]!='0'){
        		                    vec[i] = vec[i+1]+vec[i+2];
        		                }else{
        		                    vec[i] = vec[i+1];
        		                }
        		                
        		            }
		                }else{
		                    vec[i] = vec[i+1];
		                }
		        }else{
		            if(str[i+1]=='0'){
		                return 0;
		            }
		            vec[i] = vec[i+1];
		        }
		        vec[i] = vec[i]%u;
		    }
		    if(str[0]=='0'){
		        return 0;
		    }
		    return vec[0];
		}

};
