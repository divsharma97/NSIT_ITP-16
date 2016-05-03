                            //Ques6. Using pointers write a program to perform multiplication of matrices.

# include <stdio.h> 
# include <stdlib.h>

typedef struct 
{
	int row;
	int column;
} m_size;

void multiply(int* matA[], m_size sizeA, int* matB[], m_size sizeB);

void getInput(int* mat[], m_size size, char name);
void print(int* mat[], m_size size);

int main(int argc, char const *argv[])
{
	m_size a, b;

	printf("What is the size of matrix A    __ x __\n");
	scanf("%d %d", &a.row, &a.column);

	printf("What is the size of matrix B    __ x __\n");
	scanf("%d %d", &b.row, &b.column);

	if (a.column != b.row)
	{
		printf("Cannot be multiplied\n");
		return -1;
	}

	else{

		int* matA[a.row];
		getInput(matA, a, 'A');
	
		printf("\n\n");

		int* matB[b.row];
		getInput(matB, b, 'B');

		
		multiply(matA, a, matB, b);
	}

	return 0;
}

void getInput(int* mat[], m_size size, char name){

	int rows = size.row;
	int columns = size.column;

	for (int i = 0; i < rows; ++i)
	{
		mat[i] = (int*)malloc(columns*sizeof(int));
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			printf("%c(%d, %d) = ", name, i+1, j+1);
			scanf("%d", (*(mat+ i) + j));
			printf("\t");
		}

		printf("\n");
	}
}

void print(int* mat[], m_size size){

	int rows = size.row;
	int columns = size.column;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			printf("%d\t", (*(*(mat+ i) + j)));		    
		}

		printf("\n");
	}
}

void multiply(int* matA[], m_size sizeA, int* matB[], m_size sizeB){

	m_size ans_size;
	ans_size.row = sizeA.row;
	ans_size.column = sizeB.column;

	int* mat_ans[ans_size.row];

	for (int i = 0; i < ans_size.row; ++i)
	{
		mat_ans[i] = (int*)malloc((ans_size.column)*sizeof(int));
	}

	printf("\033[2J");

	printf("Matrix A is\n");
	print(matA, sizeA);
	printf("\n");
	printf("Matrix B is\n");
	print(matB, sizeB);

	
	int n = sizeA.column;  // = sizeB.row

	for (int i = 0; i < ans_size.row; ++i)
	{
		for (int j = 0; j < ans_size.column; ++j)
		{
			int ans = 0;

			for (int k = 0; k < n; ++k)
			{
				ans = ans + (matA[i][k]*matB[k][j]); 
			}
			
			mat_ans[i][j] = ans;
		}
	}

	printf("\n");

	printf("The answer is \n");

	print(mat_ans, ans_size);
}