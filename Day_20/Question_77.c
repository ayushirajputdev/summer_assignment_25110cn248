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
        if(columns1!=rows2){
             printf("MULTIOPLICATION NOT POSSIBLE");
             return 0;}
        else{
            printf("ENTER THE TERMS OF MATRICE2 \n");
        
             
        for(i=0;i<rows2;i++){
            printf("\n");
            for(j=0;j<columns2;j++){
                scanf("%d",&array2[i][j]);

            }
        }
        }
    }
    int arraymulti[100][100],k;
    for(i=0;i<rows1;i++){
            for(j=0;j<columns2;j++){
                arraymulti[i][j]=0;
                for(k=0;k<columns1;k++){
                arraymulti[i][j]+=array1[i][k]*array2[k][j];
            }

            }
        }
            printf("THE MULTIPLICATION OF THE MATRICE IS ");
            for(i=0;i<rows1;i++){
                printf("\n");
            for(j=0;j<columns2;j++){
                printf(" %d ",arraymulti[i][j]);
            }
            

}
return 0;
}