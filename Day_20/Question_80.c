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
    int sumrow[columns1],num;
    


    for(i=0;i<columns1;i++){
        num=0;
        for(j=0;j<rows1;j++){
          num+=array1[j][i];
          
          
        }
        sumrow[i]=num;
        
    }
    printf("THE SUM OF COLUMNS IS \n");
    for(i=0;i<columns1;i++){
        
            printf(" %d ",sumrow[i]);
        }
    return 0;


}