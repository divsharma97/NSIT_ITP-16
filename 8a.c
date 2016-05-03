                       //Ques8. Write a program to count the frequencies of individual words in a file of text. 


#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

#ifndef IN
#define IN 0
#endif
#ifndef OUT
#define OUT 1
#endif

char words_ar[50][15];

void grapher(char ar[][15], int n);
void sort(char ar[][15], int n);

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./8a (filename.  )\n");
		return -1;
	}

	char words_ar[50][15];

	//char (*words_ar)[15]; 

	FILE* file;

	file = fopen(argv[1], "r");

	int c;
	int count = 0;
	int len = 0;
	int state;

	while((c = fgetc(file)) != EOF){

		if(isspace(c) || (c == '\n') || (c == '\t' ) || !(isalpha(c)) || isdigit(c)){

			if (state == IN)
			{
				count++;
				len = 0;
			}	

			state = OUT;		
		}

		else{

			words_ar[count][len] = tolower(c);
			len++;	
			state = IN;
		}
	}

	sort(words_ar, count);

	grapher(words_ar, count);

	fclose(file); 

	return 0;
}


void sort(char ar[][15], int n){

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
	    {
			int x = strcmp(ar[j], ar[j+1]);
			if (x >= 0)
			{
				char temp[15];
				strcpy(temp, ar[j]);
				strcpy(ar[j], ar[j+1]);
				strcpy(ar[j+1], temp);
			}
	    }
	}
}

void grapher(char ar[][15], int n){

	int k;

	for (int i = 0; i <= n; i+=k)
	{
		printf("%s", ar[i]);
		
		for (int u = (15 - strlen(ar[i])); u >= 0; --u)
		{
			printf(" ");
		}

		k = 0;

		for (int j = i; j <= n; ++j)
		{
			
			if (strcmp(ar[i], ar[j]) == 0)
			{
				printf(" | ");
				k++;
			}

			else{

				break;
			}
		}

		printf("\n");
	}
}