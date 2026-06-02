#include <stdio.h>
int main(){
    int num,count=0,n,num1;
    printf("Enter a number to find the set bits in it");
    scanf("%d",&num);
    n=num;
    while(n>0){
        num1=n%2;
        if(num1==1){
            count++;
            
        }
        n=n/2;
    
    }
    printf("The number of set bits in %d is %d",num,count);
    return 0;

}