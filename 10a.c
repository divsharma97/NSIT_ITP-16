                            //Ques10. Write a program to exhibit use of enumerated data types.


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef enum {true, false} bool;

int main(int argc, char const *argv[])
{
	char old1[32];
	char old2[32];
	char new1[32];
	char new2[32];

	system("stty -echo"); //disable echo in terminal

	printf("Type in your old password\n");
	scanf("%s", old1);
	printf("Retype your old password\n");
	scanf("%s", old2);
	if (strcmp(old1, old2) == true)
	{
		printf("\t\tPasswords match\n");
	}
	else{
		printf("\t\tYou entered different passwords\n");
	}

	printf("Type in your new password\n");
	scanf("%s", new1);
	printf("Retype your new password\n");
	scanf("%s", new2);
	if (strcmp(new1, new2) == true)
	{
		printf("\n\t\tPasswords match\n");
	}
	else{
		printf("\n\t\tYou entered different passwords\n");
	}

	system("stty echo"); //renable echo in terminal

	return 0;
}