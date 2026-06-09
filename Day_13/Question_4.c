#include <stdio.h>
int main(){
     int n,i,array[100],array2[100],array3[100];
    printf("ENTER THE NUMBER OF TERMS TO ENTER IN THE ARRAY");
    scanf("%d",&n);
    printf("ENTER THE TERMS OF THE ARRAY");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);


    }
    int j=0;
    printf("THE EVEN TERMS ARE ");
    for(i=0;i<n;i++){
        if(array[i]%2==0){
            printf("%d ",array[i]);
        }
        
    }
    printf("\nTHE ODD TERMS ARE ");
    for(i=0;i<n;i++){
        if((array[i]%2)!=0){
            printf("%d ",array[i]);
        }}
       
    
    return 0;
}