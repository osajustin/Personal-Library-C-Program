//Simple program to keep track of the books I own
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Book Struct
struct book
 {
    char title[50];
    char author[50];
    char subject[50];
} ;

int main()
{

//Array of books
struct book books[6];
int i;
char t[50]; //title
char a[50]; //author
char s[50]; //subject

//Loop to get book information (should ignore whitespace)
    for (i = 0; i < 6; i++)
    {
        printf("\nEnter Title: "); 
        gets(t);
        strcpy(books[i].title, t);
        strcpy(t, "\0"); //clear string after recieving input

        printf("Enter Author: ");
        gets(a);
        strcpy(books[i].author, a);
        strcpy(a, "\0"); //clear string after recieving input

        printf("Fiction or Non-Fiction: ");
        gets(s);
        strcpy(books[i].subject, s);
        strcpy(s, "\0"); //clear string after recieving input
    }

//Putting book information into a text file
FILE *fp;
char output[100] = "privateBookCollection.txt";

fp = fopen(output, "w");
if (fp == NULL)
{
    printf("Unable to open file\n");
    return 1;
}

//printing book information
int x;

for (x = 0; x < i; x++ )
{
    fprintf(fp, "Author: %s\n Title: %s\n Genre: %s\n\n", books[x].title, books[x].author, books[x].subject);
}

fclose(fp);

return 0;

}



