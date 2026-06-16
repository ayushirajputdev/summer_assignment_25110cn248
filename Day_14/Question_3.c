#include <stdio.h>
int main(){
     int array[100],i,n,lar,seclar;
    printf("ENTER THE NUMBER OF TERMS TO ENTER THE ARRAY");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    
    }
    lar=array[0];
    
    for(i=0;i<n;i++){
        if(array[i]>lar){
            seclar=lar;
            lar=array[i];
        }
        else if(array[i]>seclar && array[i] !=lar){
            seclar=array[i];
        }

    }
    printf("THE SECOND LARGEST ELEMENT OF THE ARRAY IS %d",seclar);
    return 0;
}