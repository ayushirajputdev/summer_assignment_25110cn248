#include <stdio.h>
int main(){
     int n1,n2,i,array1[100],array2[100],array3[100];
     float array4[100];
    printf("ENTER THE NUMBER OF TERMS TO ENTER IN THE FIRST ARRAY");
    scanf("%d",&n1);
    printf("ENTER THE TERMS OF THE ARRAY");
    for(i=0;i<n1;i++){
        scanf("%d",&array1[i]);


    }
    printf("ENTER THE NUMBER OF TERMS TO ENTER IN THE SECOND ARRAY");
    scanf("%d",&n2);
    printf("ENTER THE  TERMS OF THE ARRAY");
    for(i=0;i<n2;i++){
        scanf("%d",&array2[i]);


    }
    //adding both the arrays
    if(n1==n2){
        for(i=0;i<n1;i++){
            array3[i]=array1[i]+array2[i];
            array4[i]=(array3[i]/2);
        }
         printf("THE SUM OF BOTH ARRAY IS\n [");
    for(i=0;i<n1;i++){
        printf("%d,",array3[i]);

    }
    printf("]\n");
    printf("THE AVERAGE OF BOTH ARRAY IS\n [");
    for(i=0;i<n1;i++){
        printf("%f,",array4[i]);

    }
    printf("]");
    }
    else{
        printf("ADDITION NOT POSSIBLE");

    }
   
    return 0;
    

}