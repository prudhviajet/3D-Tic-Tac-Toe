#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{    	    
        int n=3;
        int magiccube[n][n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                for (int k = 0; k < n ; k++){
                    magiccube[i][j][k]=0;
                }
				
                }
			
        }
        int i=0;
        int j=n/2;
        int k=n-1;
        
	    for(int num=0 ; num<(n*n*n); num++)
		{
            if (magiccube[i][j][k] != 0) {
                j--;
                if (j < 0){
                  j+=n ;
                }
                
                k++;
                if(k >=n ){
                  k-=n;
                }
                
                if (magiccube[i][j][k]!=0){
                    j++;
                    if(j >=n ){
                      j-=n;
                    }
                    i=i+2;
                    if(i >=n ){
                      i-=n;
                    }
                }
           }
           magiccube[i][j][k]=num+1;
           i--;
           if (i < 0){
            i+=n ;
           }
           k--;
           if (k < 0){
            k+=n ;
           }
           
        }

        cout<<"The Magic Cube for "<<n<<" is: "<<endl<<endl;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++){
                for (k = 0; k < n ; k++){
                    cout<<magiccube[i][j][k]<<" ";
                }
				cout <<"\n";
                }
				cout <<"\n";
        }
}