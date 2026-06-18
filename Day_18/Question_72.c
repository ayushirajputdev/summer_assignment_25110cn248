#include <stdio.h>
int main(){
    //bubble sort
    int array[100],i,j,num,c;
    printf("ENTER THE NUMBER OF TERMS OR THE ARRAY");
    scanf("%d",&num);
    if(num<=0){
        printf("INVALID NUMBER OF TERMS ENTERED");
        return  0;
    }
    else{
    printf("ENTER THE TERMS OF THE ARRAY");
    for(i=0;i<num;i++){
        scanf("%d",&array[i]);
    }
    for(i=0;i<num;i++){
        for(j=0;j<num-i-1;j++){
            if(array[j]<array[j+1]){
                c=array[j];
                array[j]=array[j+1];
                array[j+1]=c;
            }
        }
    }
    printf("THE SORTED ARRAY IS \n");
    for(i=0;i<num;i++){
        printf("%d ",array[i]);
    }}
    return 0;

}