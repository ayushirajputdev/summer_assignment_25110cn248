#include <stdio.h>
int main(){
    int n,i=0;
    printf("Enter the number to print the factors of a number ");
    scanf("%d",&n);
    printf("THE FACTORIALS OF THE ENTERED NUMBERS ARE \n");
    if(n<0){
        printf("INVALID NUMBER");
    }
    else{
    for(i=1;i<=n;i++){
        if(n%i==0){
            printf("%d ",i);
        }
    }}
    return 0;
}