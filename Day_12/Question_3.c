#include <stdio.h>
int fibo(int n){
    int i=0,a=0,b,next;
    for(i=0;i<n;i++){
        if(i==0){
            printf("%d",i); 
        }
        else if(i==1){
            printf("%d ",i);
            b=i;
            printf("%d ",b);
            a=i;

        }
        else{
            next=a+b;
            a=b;
            b=next;
            printf("%d ",next);

        }
    
    }
}
int main(){
    int n;
    printf("Enter the number of terms in the fibonacci series");
    scanf("%d",&n);
    printf("THIS IS THE FIBONACCI SERIES\n");
    fibo(n);
    return 0;
}