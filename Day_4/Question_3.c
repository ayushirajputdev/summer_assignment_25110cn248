#include <stdio.h>
int pow(int base ,int exp){
    int i,result=1;
    for(i=0;i<exp;i++){
        result=result*base;
    }
    return result;
}
int main(){
    int n,i,r=0,s=0,a=0,sum=0,num=0;
    printf("Enter the number uptill which you want to find the total armstrong numbers ");
    scanf("%d",&n);
    printf("THE TOTAL ARMSTRONG NUMBERS UPTO %d ARE \n",n);
    if(n<0){
        printf("INVALID RANGE");
    }
    else{
    for(i=0;i<=n;i++){
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