class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    vector<ull>vec(n,1);
	    int two = 0;
	    int three = 0;
	    int five = 0;
	    for(int i = 1;i < n;i++){
	        vec[i]= min(2*vec[two],min(3*vec[three],5*vec[five]));
	        if(vec[i]==(2*vec[two])){
	            two++;
	        }
	        if(vec[i]==(3*vec[three])){
	            three++;
	        }
	        if(vec[i]==(5*vec[five])){
	            five++;
	        }
	    }
	    return vec[n-1];
	        
	    
	}
};
