class Solution{
public:
    void swap(char &a,char &b){
        char temp = a;
        a = b;
        b = temp;
    }

    int partition(char arr[],int low,int high,char c){
        int j = low;
        int p;
        for(int i = low;i <high;i++){
            if(arr[i]<c){
                swap(arr[i],arr[j++]);
            }else if(arr[i]==c){
                swap(arr[i],arr[high]);
                i--;
            }
        }
        swap(arr[j],arr[high]);
        return j;
    }
    
    
    void quick_sort(char nuts[],char bolts[],int low,int high){
        if(low<high){
            int pivot = partition(nuts,low,high,bolts[high]);
            partition(bolts,low,high,nuts[pivot]);
            quick_sort(nuts,bolts,low,pivot-1);
            quick_sort(nuts,bolts,pivot+1,high);
            
        }
    }

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    quick_sort(nuts,bolts,0,n-1);
	}

};
