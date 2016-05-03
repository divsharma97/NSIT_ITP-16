                                    //Ques 9. Write a program to implement tic- tac toe game



#include <stdio.h>  
#include <stdlib.h> 
#include <ctype.h>
#include <stdbool.h>

#define KBLU  "\x1B[34m"
#define KGRN  "\x1B[32m"
#define KRED  "\x1B[31m"
#define RESET "\033[0m"

void createboard(int n, int* ar[]);
void printboard(int* ar[], int n);
void place(int* ar[], int n, int num, char c);

bool win_check(int* ar[], int n, int p);
bool hori(int* ar[], int n, int p);
bool vert(int* ar[], int n, int p);
bool diag_LtoR(int* ar[], int n, int p);
bool diag_RtoL(int* ar[], int n, int p);
bool draw_check(int* ar[], int n);

int main(int argc, char const *argv[]){
	if (argc != 2)
	{
		printf("Usage: ./9a (board size)\n");
		return 1;
	}

	int size = atoi(argv[1]);

	int* board[size];

	createboard(size, board);

	while(!win_check(board, size, 0)){

		int tile;
		
		printf("On which tile do you want to place'X'\n");
		scanf("%d", &tile);
		place(board, size, tile, 'x');
		printboard(board, size);
	

		if(!win_check(board, size, -1)){
			printf("On which tile do you want to place'O'\n");
			scanf("%d", &tile);
			place(board, size, tile, 'o');
			printboard(board, size);
		}
		else{
			break;
		}
	}

	printf("GAME OVER\n");

	return 0;
}

void createboard(int n, int* ar[]){

	for (int i = 0; i < n; ++i){

		ar[i] = (int*)malloc(n*sizeof(int));
	}

	int k= 1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			ar[i][j] = k;
			printf(KGRN "%2d\t" RESET, ar[i][j]);
			k++;
		}
		printf("\n");
	}
}

void printboard(int* ar[], int n){

	printf("\033[2J");

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (ar[i][j] == 0)
			{
				printf(KRED "O\t" RESET);
			}
			else if (ar[i][j] == -1)
			{
				printf(KBLU "X\t" RESET);
			}
			else{
				printf(KGRN "%2d\t" RESET, ar[i][j]);
			}
		}
		printf("\n");
	}
}

void place(int* ar[], int n, int num, char c){

	int a, b;

	for (int i = 0; i < n; ++i)
    {
	    for (int j = 0; j < n; ++j)
	{
			if (ar[i][j] == num)
			{
				a = i;
				b = j; 
				break; 
			}
	    }
    }

	if (c == 'x')
	{
		ar[a][b] = -1;
	}
	else if (c == 'o')
	{
		ar[a][b] = 0;
	}
}

bool win_check(int* ar[], int n, int p){

	if (hori(ar, n, p)){
		if (p == 0)
		{
			printf("O won !!!!\n");
			return true;
		}
		else{
			printf("X won !!!!\n");
			return true;
		}
	}
	else if (vert(ar, n, p)){
		if (p == 0)
		{
			printf("O won !!!!\n");
			return true;
		}
		else{
			printf("X won !!!!\n");
			return true;
		}
	}
	else if (diag_LtoR(ar, n, p)){
		if (p == 0)
		{
			printf("O won !!!!\n");
			return true;
		}
		else{
			printf("X won !!!!\n");
			return true;
		}
	}
	else if (diag_RtoL(ar, n, p)){
		if (p == 0)
		{
			printf("O won !!!!\n");
			return true;
		}
		else{
			printf("X won !!!!\n");
			return true;
		}
	}
	else if (draw_check(ar, n))
	{
		printf("Match Draw.\n");
		return true;
	}

	return false;
}

bool hori(int* ar[], int n, int p){

	int check;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (ar[i][j] != p)
			{				
				check = 1;
				break;
			}
			else
			{
				check = 0;
			}
		}
		if (check == 0){
		    return true;
	}
	}

	if (check == 0){
		return true;
	}

	return false;
}

bool vert(int* ar[], int n, int p){

	int check;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (ar[j][i] != p)
			{				
				check = 1;
				break;
			}
			else
			{
				check = 0;
			}
		}
		if (check == 0){
		    return true;
	}
	}

	if (check == 0){
		return true;
	}

	return false;
}

bool diag_LtoR(int* ar[], int n, int p){

	int i =0, j= 0;
	int check = 1; 

	while (i < n){ 
		if (p != ar[i][j]){
				check = 1;
				break;
			}		
		else{
				check = 0;
				i++;
				j++;
			}	
	}

	if (check == 0)
	{
		return true;
	}

	return false;
}

bool diag_RtoL(int* ar[], int n, int p){

	int i =0, j= n-1;
	int check = 1; 

	while (i < n){ 
		if (p != ar[i][j]){
				check = 1;
				break;
			}		
		else{
				check = 0;
				i++;
				j--;
			}	
	}

	if (check == 0)
	{
		return true;
	}

	return false;
}

bool draw_check(int* ar[], int n){

	int p1 = -1;
	int p2 = 0;

	int check;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((ar[i][j] == p1) || (ar[i][j] == p2))
			{
				check = 0;
			}
			else{
				check = 1;
				break;
			}
		}

		if (check == 1)
		{
			break;
		}
	}

	if (check == 0)
	{
		return true;
	}

	return false;
}
