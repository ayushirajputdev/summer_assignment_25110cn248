#include <stdio.h>
int main(){
    int sum=0,i,n,j;
    printf("Enter the number ti check whether the number is a strong number or not ");
    scanf("%d",&n);
    int num=n;
    while(n!=0){
        i=n%10;
        n=n/10;
        int factorial=1;
        for(j=1;j<=i;j++){
            factorial*=j;
        }
        sum+=factorial;
    }
    if(sum==num){
        printf("THE ENTERED NUMBER IS A STRONG NUMBER ");
    }
    else{
        printf("THE ENTERED NUMBER IS NOT A STRONG NUMBER ");
    }
    return 0;
}