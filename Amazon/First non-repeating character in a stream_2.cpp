class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string s;
		    int n = A.size();
		    vector<int>vec(26,0);
		    queue<char>q;
		    for(int i = 0;i < n;i++){
		        if(vec[A[i]]!=-1){
		            if(!q.empty()){
    		            if(A[i]==q.front()){
    		                vec[A[i]-'a'] = -1;
    		                q.pop();
    		            }else{
    		                if(vec[A[i]-'a']==0){
        		                q.push(A[i]);
        		                vec[A[i]-'a'] = 1;
        		            }else{
        		                vec[A[i]-'a'] = -1;
        		            }
    		            }
    		        }else{
    		            if(vec[A[i]-'a']==0){
    		                q.push(A[i]);
    		                vec[A[i]-'a'] = 1;
    		            }else{
    		                vec[A[i]-'a'] = -1;
    		            }
    		            
    		        }
		        }
		        while(!q.empty() && vec[q.front()-'a']==-1){
		            q.pop();
		        }
		        if(!q.empty()){
		            s+=(q.front());
		        }else{
		            s+='#';
		        }
		        
		    }
		    return s;
		    
		}

};
