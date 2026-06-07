#include <stdio.h>
int fac(int n){
    int i,factorial=1;
    for(i=1;i<=n;i++){
        factorial=factorial*i;
    }
    return factorial;
}
int main(){
    int num;
    printf("ENTER THE NUMBER TO FIND ITS FACTORIAL");
    scanf("%d",&num);
    printf(" THE FACTORIALOF%d IS %d",num,fac(num));
    return 0;

}