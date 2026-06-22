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
    int array[100][100];
     for(i=0;i<rows1;i++){
            for(j=0;j<columns1;j++){
                array[i][j]=array1[j][i];
            }



    } 
    printf("THE TRANSPOSE OF THE MATRICE IS ");
     for(i=0;i<rows1;i++){
        printf("\n");
            for(j=0;j<columns1;j++){
                printf("%d ",array1[j][i]);
            }
}
return 0;
}