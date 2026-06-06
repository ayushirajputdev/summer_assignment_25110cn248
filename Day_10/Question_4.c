#include <stdio.h>
int main(){
    int i,k,j,l;
    char ch[]={'A','B','C','D','E'};
    for(i=1;i<=5;i++){
        printf("\n");
        for(j=1;j<=5-i;j++){
            printf(" ");

        }
        for(k=1;k<i;k++){
            printf("%c",ch[k-1]);

        }
        for(l=i;l>=1;l--){
            printf("%c",ch[l-1]);
        }
    }
    return 0;
}