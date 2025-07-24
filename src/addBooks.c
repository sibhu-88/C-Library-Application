#include "headers.h"

void add_book(Book **books){
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the Book details: \n");
    
     printf("Enter the Title: ");
    scanf(" %[^\n]%*c", newBook->title);

    printf("Enter the Author Name: ");
    scanf(" %[^\n]%*c", newBook->author); 

    printf("Enter the number of copies: ");
    while (scanf("%d", &newBook->copies) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    getchar();

    if (books==NULL)
    {
        newBook->next=books;
        newBook->id = 1;
        books=newBook;
    }else{
        Book *current = *books;
        while (current->next!=NULL) current = current->next;
        newBook->next = current->next;
        current->next = newBook; 
        newBook->id = current->id+1;      
    }
}