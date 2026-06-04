#include <stdio.h>
int main(){
    int i,n;
    for(i=1;i<=5;i++){
        printf("\n");
        n=i;
        while(n!=0){
            printf("*");
            n--;
        }
        
    }
    return 0;
}