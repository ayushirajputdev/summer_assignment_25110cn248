#include <stdio.h>
int main(){
    int array1[100][100],i,j,rows1,columns1;
    printf("ENTER THE NUMBER OF ROWS AND COLUMNS OF THE MATRICE\n");
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
    printf("THE DIAGONAL IS \n ");
    for(i=0;i<rows1;i++){
            printf("\n");
            for(j=0;j<columns1;j++){
                if(i==j){
                    printf("%d ",array1[i][i]);
                }
            }
        }
            return 0;

}