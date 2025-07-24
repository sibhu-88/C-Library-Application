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
    scanf("%d", &newBook->copies);

    if (*books==NULL)
    {
        newBook->id = 1;
        newBook->next=*books;
        *books=newBook;
    }else{
        Book *current = *books;
        while (current->next!=NULL) current = current->next;
        newBook->next = current->next;
        current->next = newBook; 
        newBook->id = current->id+1;      
    }
    printf("Book Added successfully\n ");
}

void remove_book(Book **books){
    int op,book_id;
    char book_name[100];

    if (*books == NULL) {
        fprintf(stderr, "Error: No records found.\n");
        return;
    }
    display_book_search_menu();
    scanf("%d",&op);
    switch (op)
    {
    case 1:
        printf("Enter the Book ID : ");
        scanf("%d",&book_id);
        break;
    case 2:
        printf("Enter the Book Title : ");
        scanf(" %[^\n]%*c",book_name);
        break;
    case 3:
        return;    
    default:
        printf("invalid Option, Try again\n");
        break;
    }

    int found = 0;
    Book *currentBook = *books;
    Book *preBook = NULL;

    while (currentBook != NULL) {
        if ((op == 1 && currentBook->id == book_id) || 
            (op == 2 && strcmp(currentBook->title, book_name) == 0)) {
            found = 1;
            break;
        }
        preBook = currentBook;
        currentBook = currentBook->next;
    }

    if (found) {
        if (preBook == NULL) *books = currentBook->next;
        else preBook->next = currentBook->next;
        free(currentBook);
        printf("Book removed successfully.\n");
    } else {
        fprintf(stderr, "Error: No records found.\n");
    }

}