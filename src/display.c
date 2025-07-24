#include "headers.h"

void list_books(Book *books) {
    if (books == NULL) {
        fprintf(stderr, "Error: No records found.\n");
        return;
    }

    printf("\n\n\t\tBooks List:\n\n");
    printf("\t\t---------------------------------------------------------------------\n");
    printf("\t\t|  Books ID\t|   Books Title\t\t|  Author Name\t\t|  Books Copies   |\n");
    printf("\t\t---------------------------------------------------------------------\n");

    Book *current = books;
    while (current != NULL) {
        printf("\t\t|%-10d\t|%-25s\t|%-20s\t|%-10d\n", 
               current->id, 
               current->title, 
               current->author, 
               current->copies);
        current = current->next;
    }

    printf("\t\t--------------------------------------------------------------------\n");
    printf("\n\n\t\tPress Enter to return: ");
    getchar();
    getchar();
}

void search_book(Book *books){
    if (books == NULL) {
        fprintf(stderr, "Error: No records found.\n");
        return;
    }
    int op;
    char book_name[100],author_name[100];

    display_search_book_menu();
    scanf("%d",&op);
    switch (op)
    {
    case 1:
        printf("Enter the Book Title : ");
        scanf(" %[^\n]%*c",book_name);

        break;
    case 2:
        printf("Enter the Author name : ");
        scanf(" %[^\n]%*c",author_name);
        break;
    case 3:
        return;    
    default:
        printf("invalid Option, Try again\n");
        break;
    }

    int found = 0;
    Book *currentBook = books;

    while (currentBook != NULL) {
        if ((op == 1 && strcmp(currentBook->title, book_name) == 0) || 
            (op == 2 && strcmp(currentBook->author, author_name) == 0)) {
            found = 1;
            break;
        }
        currentBook = currentBook->next;
    }

    if (!found) {
        fprintf(stderr, "Error: No records found.\n");
        sleep(1);
    }else{
        printf("\n\n\t\tBooks List:\n\n");
        printf("\t\t---------------------------------------------------------------------\n");
        printf("\t\t|  Books ID\t|   Books Title\t\t|  Author Name\t\t|  Books Copies   |\n");
        printf("\t\t---------------------------------------------------------------------\n");
    
        Book *currentBook = books;
        while (currentBook != NULL) {
            if ((op == 1 && strcmp(currentBook->title, book_name) == 0) || 
                (op == 2 && strcmp(currentBook->author, author_name) == 0)) {
                found = 1;
                
                printf("\t\t|%-10d\t|%-25s\t|%-20s\t|%-10d\n", 
                    currentBook->id, 
                    currentBook->title, 
                    currentBook->author, 
                    currentBook->copies);
            }
            currentBook = currentBook->next;
        }

        printf("\t\t--------------------------------------------------------------------\n");
        printf("\n\n\t\tPress Enter to return: ");
        getchar();
        getchar();
    }
}