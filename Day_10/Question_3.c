#include <stdio.h>
int main(){
    int i,k,j,l;
    for(i=1;i<=5;i++){
        printf("\n");
        for(j=1;j<=5-i;j++){
            printf(" ");

        }
        for(k=1;k<i;k++){
            printf("%d",k);

        }
        for(l=i;l>=1;l--){
            printf("%d",l);
        }
    }
    return 0;
}