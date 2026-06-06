#include <stdio.h>
int main(){
    int i,j,k;
    for(i=5;i>=1;i--){
        printf("\n");
        for(j=1;j<=5-i;j++){
            printf(" ");
        }
        
        for(k=1;k<=2*i-1;k++){
            printf("*");
        }
            
        }
    
        return 0;
    }
