#include <stdio.h>
int main(){
    int n,i,array[100];
    printf("ENTER THE NUMBER OF TERMS TO ENTER IN THE ARRAY");
    scanf("%d",&n);
    printf("ENTER THE NUMBER OF TERMS OF THE ARRAY");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);


    }
    printf("THE ENTERED ARRAY IS\n [");
    for(i=0;i<n;i++){
        printf("%d,",array[i]);
    


    }
    printf("]");
    return 0;
    
}
