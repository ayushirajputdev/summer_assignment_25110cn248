#include <stdio.h>
int main(){
    int n,multiplication,i;
    printf("Enter the number to write its multiplication table");
    scanf("%d",&n);
    printf("enter the number of multiplication terms you want");
    scanf("%d",&multiplication);
    for(i=1;i<=multiplication;i++){
        printf(" %d x %d =%d \n ",n,i,n*i);
    }
    return 0;
}