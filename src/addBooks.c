#include "headers.h"

void add_book(Book **books){
    Book *newBook = (Book *)malloc(sizeof(Book));

    printf("Enter the Book details: \n");
    printf("Enter the Title: \n");


    if (books==NULL)
    {
        newBook->next=books;
        books=newBook;
    }
    

}