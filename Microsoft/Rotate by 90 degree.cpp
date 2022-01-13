 void swap(int &a,int &b){
     int temp = a;
     a = b;
     b = temp;
 }
void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int N = matrix.size();
    for(int i = 0;i < N/2;i++){
        for(int j = 0;j < N-2*i-1;j++){
            swap(matrix[i][i+j],matrix[i+j][N-1-i]);
            swap(matrix[i+j][N-1-i],matrix[N-i-1][N-i-1-j]);
            swap(matrix[N-i-1][N-i-1-j],matrix[N-i-1-j][i]);
        }
    }
    
}
