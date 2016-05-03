/*Ques 5. Using files and structures implement a program for inventory control with the following provisions:
(a) Addition of item
(b) Deletion of item
(c) Find and replace and item
*/

# include <stdio.h>  
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

static int counter = -1;

typedef struct
{
	char name[50];
	char catergory;
	int sku;
	float cp; 
	float mrp;
	float discount;
	bool persishable;
}item_details;

int ask(item_details* list);
void print(item_details* list, int n);
void printItem(item_details* list);
item_details add();
void del(item_details* list, int n);
void append(item_details* list, int n);

int main(int argc, char const *argv[]){

	FILE* bin = fopen("dump.txt", "r+");

	item_details* items = malloc(sizeof(item_details));

	// if (bin != NULL)
	// {
	// 	while (fread(items + counter+ 1, sizeof(item_details), 1, bin) != feof(bin))
	// 	{
	// 		counter++;
	// 		items = (item_details*)realloc(items, (counter+1)*sizeof(item_details));
	// 	}
	// }

	printf("Enter 0 to exit\n");

	while (ask(items) != 0);

	FILE* file = fopen("store.csv", "w");
	fprintf(file, "Serial No.,SKU,Catergory,Name,Cost Price,MRP,Discount,Persishable\n");
	for (int i = 0; i <= counter; ++i)
	{
		fprintf(file, "%d,%d,%c,%s,%f,%f,%f,", i+1, (items+i)->sku, (items+i)->catergory, (items+i)->name, (items+i)->cp, (items+i)->mrp, (items+i)->discount);
		if ((items+i)->persishable)
		{
			fprintf(file, "%s", "yes\n");
		}
		else{
			fprintf(file, "%s", "no\n");
		}
	}

	for (int i = 0; i <=counter ; ++i)
	{
		printf("In %d\n", counter);
		fwrite(items + i, sizeof(item_details), 1, bin);
	}

	fclose(bin);
	fclose(file);
	free(items);

	return 0;
}

int ask(item_details* list){

	printf("What do you wish to do with your inventory?\n");
	printf("			1. Add an item\n");
	printf("			2. Delete an item\n");
	printf("			3. Change an item\n");
	printf("			4. Check inventory\n");

	int in;
	scanf("%d", &in);

	if (in == 1)
	{   counter++;

		list = (item_details*)realloc(list, (counter+1)*sizeof(item_details));

		list[counter] =  add();
		print(list, counter);
	}
	else if (in == 2)
	{
		del(list, counter);
		counter--;
	}
	else if (in == 3)
	{
		print(list, counter);
		printf("Which item do you want to change?  ");
		int num;
		scanf("%d", &num);
	    printItem(list + num- 1);
		append(list + num- 1, counter - (num- 1));
	}
	else if (in == 4)
	{
		print(list, counter);
	}

	return in;
}

item_details add(){
	
    item_details temp;
	char ch;

	printf("Enter SKU    ");
	scanf("%d", &(temp.sku));

	printf("Enter name    "); 
	char tempo[30];
	scanf("%s", tempo);
	strcpy(temp.name, tempo);

	printf("Enter cost price   ");
	scanf("%f", &temp.cp);

	printf("Enter MRP   ");
	scanf("%f", &temp.mrp);

	printf("Discount (in %%) applicable   ");
	scanf("%f", &temp.discount);

	printf("Is it persishable ?    "); 
	scanf("%s", &ch);	
	if (ch == 'y')
	{
		temp.persishable = true;		
	}
	else if (ch == 'n')
	{
		temp.persishable = false;		
	}

	printf("Enter catergory    ");
	scanf("%s", &temp.catergory);

	return temp;
}

void del(item_details* list, int n){

	print(list, n);

	printf("Which item do you want to delete?   ");
	int num;
	scanf("%d", &num);
	num--;

	for (int i = num; i < n; ++i)
	{
		list[i] = list[i + 1];
	}
}

void append(item_details* list, int n){

	int num;

	printf("Which field do you want to change?  ");
	scanf("%d", &num);

	if (num == 1)
	{
		printf("SKU cannot be chaned\n");
	}
	else if (num == 2)
	{
		printf("Enter new name    "); 
		char tempo[30];
		scanf("%s", tempo);
		strcpy(list->name, tempo);
	}
	else if (num == 3)
	{
		printf("Enter new cost price\n");
		scanf("%f", &list->cp);
	}
	else if (num == 4)
	{
		printf("Enter new MRP\n");
		scanf("%f", &list->mrp);
	}
	else if (num == 5)
	{
		printf("Enter new discount \n");
		scanf("%f", &list->discount);
	}
	else if (num == 6)
	{
		printf("Enter new catergory \n");
		scanf("%s", &list->catergory);
	}
	else if (num == 7)
	{
		printf("Do you want to change perishibility?\n");

		char c;
		scanf("%s", &c);

		if (c == 'y')
		{
			list->persishable = (!(list->persishable));
		}
	}
}

void print(item_details* list, int n){

	printf("\033[2J");

	printf("\nYour inventory contains: \n");
	printf("Item No.   \tSKU       Name      \t\t\tMRP\n");

	for (int i = 0; i <= n; ++i)
	{
		printf("    %d\t\t%d\t  %s(%c)\t\t\t%0.2f", i+1, list[i].sku, list[i].name, list[i].catergory, list[i].mrp);
		if (list[i].persishable)
		{
			printf("\t%s\n", "(Persishable)");
		}
		else{
		 	printf("\n");
		}
	}
	printf("\n");
}

void printItem(item_details* list){

	item_details temp = *list;
	int i = 1;

	printf("%d. SKU   %d\n", i, temp.sku);
	i++;
	printf("%d.  Name   %s\n", i, temp.name);
	i++;
	printf("%d.  Cost Price   %0.2f\n", i, temp.cp);
	i++;
	printf("%d.  MRP   %0.2f\n", i, temp.mrp);
	i++;
	printf("%d.  Discount(%%)   %0.2f\n", i, temp.discount);
	i++;
	printf("%d.  Catergory   %c\n", i, temp.catergory);	
	i++;
	printf("%d.  Persishable ?   %c\n", i, temp.persishable);
}