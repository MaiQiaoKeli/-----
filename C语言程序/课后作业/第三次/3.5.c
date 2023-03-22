#include<stdio.h>

int matrix_matrix(int matrix1[long1][wide1],int matrix2[long2][wide2],int matrix[long1][wide2]){
    int i,j,k;
    for (i=0; i<long1; i++){
		for(j=0; j<long1; j++){
			matrix[i][j]= 0 ;
			for(k=0; k<wide2; k++){
				matrix[i][j]= matrix[i][j] + matrix1[i][k]*matrix2[k][j] ;
			}
		}
	}
}

void PrintMatrix(int matrix[long2][long2]){
	int i,j;
	for(i=0;i<long2;i++){
		for(j=0;j<long2;j++){
			printf("%6d", matrix[i][j]);
		}
		printf("\n");
	}
} 

int wide1,wide2,long1,long2;

int main(){
    
    printf("Enter rows and column for the first matrix: ");
    scanf("%d%d",&long1,&wide1);
    printf("Enter rows and column for the second matrix: ");
    scanf("%d%d",&long2,&wide2);

    if(wide1!=long2){
    printf("error!!!");
    return 0;
    }     //判断是否可以进行计算

    int matrix1[long1][wide1],matrix2[long2][wide2], matrix[long1][wide2];
    for(int i=0;i<long1;i++){
        for(int j=0;j<wide1;j++){
            printf("Enter a%d%d:",i,j);
            scanf("%d",&matrix1[i][j]);
        }
    }    

    for(int i=0;i<long2;i++){
        for(int j=0;j<wide2;j++){
            printf("Enter b%d%d:",i,j);
            scanf("%d",&matrix2[i][j]);
        }
    }     //初始化两个矩阵
    matrix_matrix(matrix1, matrix2, matrix);
    PrintMatrix(matrix);
    
    return 0;
}




    