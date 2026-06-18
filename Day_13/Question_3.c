#include <stdio.h>
int main(){
    int n,i,lar,small,array[100];
    printf("ENTER THE NUMBER OF TERMS TO ENTER IN THE ARRAY");
    scanf("%d",&n);
   
    if(n<=0){
        printf("INVALID NUMBER OF TERMS ENTERED");
        return  0;
    }
    else{
    printf("ENTER THE TERMS OF THE ARRAY");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);


    }
    lar=array[0];
    small=array[0];
    for(i=0;i<(n-1);i++){
        if(array[i]>array[i+1]){
            lar=array[i];
        }
        else{
            lar=array[i+1];
        }
    }
    printf("THE LARGEST TERM OF THE ENTERED  ARRAY IS %d\n ",lar);
    for(i=0;i<(n-1);i++){
        if(array[i]<array[i+1]){
            small=array[i];
        }
        else{
            small=array[i+1];
        }
    }}
    printf("THE SMALLEST TERM OF THE ENTERED  ARRAY IS %d ",small);
    return 0;
}