#include <stdio.h>
int main(){
    int n,i;
    printf("Enter the number to check whether it is a perfect number or not ");
    scanf("%d",&n);
    int sum=0;
    for(i=1;i<n;i++){
        if(n%i==0){
            sum=sum+i;
        }
    }
    if(sum==n){
        printf("THE ENTERED NUMBER IS A PERFECT NUMBER ");

    }
    else{
        printf("THE ENTERED NUMBER IS NOT A PERFECT NUMBER ");
    }
    return 0;
}