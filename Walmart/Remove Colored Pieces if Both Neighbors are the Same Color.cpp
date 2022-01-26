class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0,b = 0;
        int n = colors.size();
        for(int i = 1;i < n-1;i++){
            if(colors[i]=='A'){
                if(colors[i]==colors[i-1] && colors[i]==colors[i+1]){
                    a++;
                }
            }else{
                if(colors[i]==colors[i-1] && colors[i]==colors[i+1]){
                    b++;
                }
            }
        }
        if(a>b && a){
            return true;
        }else{
            return false;
        }
    }
};
