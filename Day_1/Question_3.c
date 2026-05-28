#include <stdio.h>
int main(){
    int n , factorial=1,i;
    printf("Enter the number to find its factorial");
scanf("%d",&n);
for(i=1;i<=n;i++){
    factorial*=i;

}
printf("The factorial of the given number is %d",factorial);
return 0;
}