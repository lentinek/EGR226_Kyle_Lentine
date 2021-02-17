#include <stdio.h>
#include <stdlib.h>

/**************************************************************************************
 * Author:      Kyle Lentine
 * Course:      EGR 226 - 902
 * Date:        2/2/2021
 * Project:     Lab 02 - Part 2
 * File:        main.c
 * Description: This program is a book database, and allows the user to search by
 *              a title, author, or ISBN.
 * **************************************************************************************/

//Structures for books
typedef struct{
    char title[50];
    char author_name[50];
    char ISBN[10];
    int pages;
    int year_published;
} book;


/****| main | *****************************************
* Brief: This function displays most of the information for the user.
* param:
*      N/A
* return:
*      N/A
*************************************************************/

//Main Function
int main(){

//Variables
char input[100]; //User input
book my_book_array[360];
char filename[] = "BookList.txt";
int book = 0; //which book
int choice; //Variable for checking user input
int numBooks = 360;
int again = 0; //Variable to see if user wants to go again

//Prompt User
printf("\nPlease enter a number 0-2 for one of the following features:\n\n");
printf("[0] Search by Title\n");
printf("[1] Search by Author Name\n");
printf("[2] Search by ISBN\n\n");
printf("Option: ");

    fflush(stdin);
    //Check to see if user input valid, if not: prompt user again
    if(scanf("%d", &choice) == 1){

        //Search by Title
        if( choice == 0){
            parse_file(filename, my_book_array);
            printf("Input Title: \n");
            fflush(stdin);
            scanf("%s", &input);
            search_title(my_book_array, numBooks, input );

            //Ask user if they would like to go again
            printf("Would you like to go again?\n");
            printf("Enter ""1"" for Yes, anything else for No.\n\n");
            fflush(stdin);
            scanf("%d", &again);
            if(again == 1){
                main();
            }
        }

        //Search by Author Name
        else if( choice == 1 ){
            parse_file(filename, my_book_array);
            printf("Input Author Name: \n");
            fflush(stdin);
            scanf("%s", &input);
            search_author(my_book_array, numBooks, input );

            //Ask user if they would like to go again
            printf("Would you like to go again?\n");
            printf("Enter ""1"" for Yes, anything else for No.\n\n");
            fflush(stdin);
            scanf("%d", &again);
            if(again == 1){
                main();
            }
        }

        //Search by ISBN
        else if( choice == 2){
            parse_file(filename, my_book_array);
            printf("Input ISBN: \n");
            fflush(stdin);
            scanf("%s", &input);
            search_ISBN(my_book_array, numBooks, input );

            //Ask user if they would like to go again
            printf("Would you like to go again?\n");
            printf("Enter ""1"" for Yes, anything else for No.\n\n");
            fflush(stdin);
            scanf("%d", &again);
            if(again == 1){
                main();
            }
        }

        //If user did not pick valid option, prompt again.
        else{
            main();
        }

    }

    //If user did not provide valid input, prompt again.
    else{
        main();
    }

}

/****| parse_file | *****************************************
* Brief: This function reads the BookList.txt file, and
*        stores the information into an array.
* param:
*      (char filename[]) data: BookList info stored here
*      (book book_array[]) data: Information ordered into book structure array.
* return:
*      int
*************************************************************/

int parse_file(char filename[], book book_array[]){

    //Read file
    FILE* infile = fopen(filename, "r");
    if(infile == NULL)
        return 0;

    char buffer[512];   //Create temp string buffer variable
    int i = 0;          //Indexer for book array

    while( fgets(buffer, 512, infile)){         //Loop collecting each line from the file
        char * ptr = strtok(buffer, ",");       //Parse string by commas and newline
        if(strcmp(ptr, "N/A"))                  //Validate string
            strcpy(book_array[i].title,ptr);    //First parse is Title

        ptr = strtok(NULL, ",\n");
            if(strcmp(ptr, "N/A"))                      //Validate the string
                strcpy(book_array[i].author_name,ptr);  //Second parse is Author Name

        ptr = strtok(NULL, ",\n");
            if(strcmp(ptr, "N/A"))                      //Validate the string
                strcpy(book_array[i].ISBN,ptr);         //Third parse is ISBN

        ptr = strtok(NULL, ",\n");
            if(strcmp(ptr, "N/A"))                      //Validate the string
                book_array[i].pages = atoi(ptr);        //Fourth is # of Pages

        ptr = strtok(NULL, ",\n");
            if(strcmp(ptr, "N/A"))                          //Validate the string
                book_array[i].year_published = atoi(ptr);   //Fifth is Year Published

        i++;
    }
    return -1;
}

/****| print_book | *****************************************
* Brief: This function prints the specific book info
* param:
*      (book my_book_array[]) data: Data from file
*      (int book) data: Allows to print specific book
* return:
*      N/A
*************************************************************/

print_book(book my_book_array[], int book){

    //Display the book information
    printf("\tTitle:\t%s\n", my_book_array[book].title);
    printf("\tAuthor:\t%s\n", my_book_array[book].author_name);
    printf("\tISBN:\t%s\n", my_book_array[book].ISBN);
    printf("\tPages:\t%d\n", my_book_array[book].pages);
    printf("\tYear:\t%d\n\n", my_book_array[book].year_published);


}

/****| search_title | *****************************************
* Brief: Allows user to search by title.
* param:
*      (book my_book_array[]) data: Book data from file.
*      (int numBooks) data: Used by for-loop to search every book.
*      (char input[]) data: User's input, that is compared with books
* return:
*      N/A
*************************************************************/

search_title(book my_book_array[], int numBooks, char input[] ){

    char* result;   //Allows book to print
    int check = 0;  //If no matches -> print "No results"

    for(int i = 0; i < numBooks; i++ ){                     //Loop through the books
        result = strstr(my_book_array[i].title, input);     //Check to see if match

        if( result ){                                       //If any matches
            print_book(my_book_array, i);                   //Print the books with matches
            check++;
            }
    }

    if( check == 0 )
        printf("No results found.\n");
    }

    /****| search_author | *****************************************
* Brief: Allows user to search by author.
* param:
*      (book my_book_array[]) data: Book data from file.
*      (int numBooks) data: Used by for-loop to search every book.
*      (char input[]) data: User's input, that is compared with books
* return:
*      N/A
*************************************************************/

search_author(book my_book_array[], int numBooks, char input[] ){

    char* result;   //Allows book to print
    int check = 0;  //If no matches -> print "No results"

    for(int i = 0; i < numBooks; i++ ){                             //Loop through the books
        result = strstr(my_book_array[i].author_name, input);       //Check to see if match

        if( result ){
            print_book(my_book_array, i);                           //If any matches
            check++;                                                //Print the books with matches
            }
    }

    if( check == 0 )
        printf("No results found.\n");
    }

    /****| search_ISBN | *****************************************
* Brief: Allows user to search by ISBN.
* param:
*      (book my_book_array[]) data: Book data from file.
*      (int numBooks) data: Used by for-loop to search every book.
*      (char input[]) data: User's input, that is compared with books
* return:
*      N/A
*************************************************************/

search_ISBN(book my_book_array[], int numBooks, char input[] ){

    char* result;   //Allows book to print
    int check = 0;  //If no matches -> print "No results"

    for(int i = 0; i < numBooks; i++ ){                             //Loop through the books
        result = strstr(my_book_array[i].ISBN, input);              //Check to see if match

        if( result ){
            print_book(my_book_array, i);                           //If any matches
            check++;                                                //Print the books with matches
        }
    }

    if( check == 0 )
        printf("No results found.\n");
    }

