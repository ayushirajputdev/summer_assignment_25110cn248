#include <stdio.h>
int isperfect(int n){
     int i,ans=0;
    int sum=0;
    for(i=1;i<n;i++){
        if(n%i==0){
            sum=sum+i;
        }
    }
    if(sum==n){
        ans=1;
    }
    return ans;
    
}
int main(){
    int num,answer;
    printf("Enter the number to check whether it is a perfect number or not ");
    scanf("%d",&num);
    answer=isperfect(num);
    if(answer==1){
        printf("THE ENTERED NUMBER IS A PERFECT NUMBER");
    }
    else{
        printf("THE ENTERED NUMBER IS NOT A PERFECT NUMBER");
}
return 0;

}
