#include <stdio.h>
int main(){
    int array1[100][100],i,j,rows1,columns1;
    printf("ENTER THE NUMBER OF ROWS AND COLUMNS OF THE MATRICE1\n");
    scanf("%d%d",&rows1,&columns1);
    if(rows1<=0||columns1<=0){
        printf("INVALID ENTRY");
        return 0;

    }
    else{
        printf("ENTER THE TERMNS OF THE MATRICE1\n");
       
        for(i=0;i<rows1;i++){
            printf("\n");
            for(j=0;j<columns1;j++){
                scanf("%d",&array1[i][j]);

            }
            
        }

    }
    int array2[100][100],rows2,columns2;
    printf("ENTER THE NUMBER OF ROWS2 AND COLUMNS2 OF THE MATRICE2\n");
    scanf("%d%d",&rows2,&columns2);
    if(rows2<=0||columns2<=0){
        
        printf("INVALID ENTRY");
        return 0;

    }
    else{
        if(rows1==rows2&&columns1==columns2){
             printf("ENTER THE TERMNS OF THE MATRICE2\n");
             
        for(i=0;i<rows2;i++){
            printf("\n");
            for(j=0;j<columns2;j++){
                scanf("%d",&array2[i][j]);

            }
        }
        
    int arraysub[100][100];
    for(i=0;i<rows1;i++){
        for(j=0;j<columns1;j++){
            arraysub[i][j]= array1[i][j]-array2[i][j];
                }
    }
    printf("THE SUBTRACTION OF BOTH THE MATRICES IS \n");
    printf("[");
    for(i=0;i<rows1;i++){
       
        for(j=0;j<columns1;j++){
            printf(" %d ",arraysub[i][j]);
                }
                 printf("\n");

    }
    printf("]");
    
    }

        else{
            printf("SUBTRACTION NOT POSSIBLE FOR DIFFERENT NUMBER OF ROWS AND COLUMNS");
            return 0;}
        }
        return 0;

}
