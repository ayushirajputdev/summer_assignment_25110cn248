#include <stdio.h>
int pow(int base ,int exp){
    int i,result=1;
    for(i=0;i<exp;i++){
        result=result*base;
    }
    return result;
}
int main(){
    int num1,num2,i,r=0,s=0,a=0,sum=0,num=0;
    printf("Enter the range in which you want to print the armstrong numbers");
    scanf("%d%d",&num1,&num2);
    printf("THE TOTAL ARMSTRONG NUMBERS IN THE RANGE %d TO %d ARE \n",num1,num2);
    if(num1<0 || num2<0 || num1>num2){
        printf("INVALID RANGE");
    }
    else{
    for(i=num1;i<=num2;i++){
        sum=0;
        r=0;
    
        a=i;
        if(a==0){
            r=1;
            
        }
        else{
        while(a!=0){
            a=a/10;
            r++;}
            

        }
        num=i;
        if(num==0){
            sum=0;
        }
        else{   
        while(num!=0){
            s=num%10;
            num=num/10;
            sum=sum+pow(s,r);
        }}
    
        if(sum==i){
            printf("%d  ",sum);
        }
        
    }}
    return 0;
}