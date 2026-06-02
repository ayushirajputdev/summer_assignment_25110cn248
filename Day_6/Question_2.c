#include <stdio.h>
int pow(int base ,int exp){
    int result=1,i=0;
    for(i=0;i<exp;i++){
        result=result*base;
    }
    return result;
}
int main(){
    int n,i,sum=0,num=0;
    printf("Enter the binary number to convert it into decimal");
    scanf("%d",&n);
    for(i=0;n>0;i++){
        num=n%10;
        sum=sum+num*pow(2,i);
        n=n/10;
    }
    printf("THE DECIMAL EQUIVALENT OF THE GIVEN BINARY NUMBER IS %d",sum);
    return 0;
}