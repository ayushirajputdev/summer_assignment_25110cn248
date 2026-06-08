#include <stdio.h>
int pow(int base,int exp){
    int i,power=1;
    for(i=1;i<=exp;i++){
        power=power*base;

    }
    return power;
    
}
int isarmstrong(int n){
    int i, num,s=0,sum=0,d,f,ans=0;
    num=n;
    f=n;

    if(n==0){
        s=1;
    }
    else{
    while(num!=0){
        
        num=num/10;
        s++;
    }}
    while(n!=0){
        d=n%10;
        sum=sum+pow(d,s);
        n=n/10;

    }
    if(sum==f){
        ans=1;
    }
    return ans;
}
int main(){
    int num1,answer;
    printf("ENTER THE NUMBER TO CHECK WHETHER IT IS AN ARMSTRONG NUMBER OR NOT");
    scanf("%d",&num1);
    if(num1<1){
        printf("INVALID INPUT");

    }else{
    answer=isarmstrong(num1);
    if(answer==1){
        printf("THE NUMBER IS AN ARMSTRONG NUMBER");

    }
    else if(answer==0){
        printf("THE NUMBER IS NOT AN ARMSTRONG NUMBER");

    }}
    return 0;

}