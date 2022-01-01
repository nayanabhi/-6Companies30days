string encode(string src)
{     
  //Your code here 
  int n = src.size();
  string s = "";
  int count = 1;
  
  for(int i = 0;i < n-1;i++){
    if(src[i]==src[i+1]){
        count++;
    }else{
        s+=src[i];
        s+=to_string(count);
        count = 1;
    }
  }
  if(n>1){
      if(src[n-1]==src[n-2]){
          s+=src[n-2];
          s+=to_string(count);
      }else{
          s+=src[n-1];
          s+="1";
      }
  }else{
      s+=src[0];
          s+="1";
  }
  return s;
}     
