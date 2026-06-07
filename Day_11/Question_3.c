#include <stdio.h>
int isprime(int n){
    int i,a=1;
    
    for(i=2;i<n;i++){
        if(n%i==0){
            a=0;
            break;

        }
    }
    return a;

}
int main(){
    int num;
    printf("ENTER THE NUMBER TO CHECK WHETHER IT IS PRIME OR NOT ");
    scanf("%d",&num);
    if(num<2){
        printf("INVALID INPUT");
        return 0;
    }
    else{
    if(isprime(num)==0){
        printf("%d IS NOT A PRIME NUMBER ",num);
    }
    else{
        printf("%d IS A PRIME NUMBER " , num);

    }}
    return 0;
    
}