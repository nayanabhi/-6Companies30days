void bin(int n,string &s){
    if(n==0){
        s+="0";
    }else if(n==1){
        s+="1";
    }else{
        bin((n>>1),s);
        if(n&1){
            s+="1";
        }else{
            s+="0";
        }
    }
}
vector<string> generate(int N)
{
	// Your code here
	vector<string>vec(N);
	vec[0] = "1";
	for(int i = 1;i < N;i++){
	    bin(i+1,vec[i]);
	}
	return vec;
}
