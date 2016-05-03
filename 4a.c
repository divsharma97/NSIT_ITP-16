                            //Ques4. Write a program showing the implementation of pointers to functions.

#include <stdlib.h> 
#include <string.h>
#include <stdio.h>

void swap(char* str, int p1, int p2);

int main(int argc, char const *argv[])
{
	char* str;
	
	printf("Enter string:\n");	

	str = (char*)malloc(sizeof(char));

	int j;
	for (j= 0; *(str + j-1) !=  '\n'; j++){
		str = (char*)realloc(str, (j+2)*sizeof(char));
		char c = getchar();
		*(str + j) = c;
	}
	*(str + j - 1) = '\0'; 

	int size = strlen(str); 

	printf("Position    Character   Address Of Pointer\n\n");

	printf("       Original string:\n");

	for (int i = 0; i < size; ++i)
	{
		printf("%2d\t\t\b%c\t%p\n",i+1, *(str+i), (str+i) );
	}

	for (int k = 0; k < size/2; ++k)
	{
		swap(str, k, size - 1 -k);
	}

	printf("       After reversing:\n");


	for (int i = 0; i < size; ++i)
	{
		printf("%2d\t\t\b%c\t%p\n",i+1, *(str+i), (str+i) );
	}

	return 0;
}

void swap(char* str, int p1, int p2){
	char temp = *(str + p1);
	*(str + p1) = *(str + p2);
	*(str + p2) = temp;
}