#include "headers.h"

void list_books(Book *books) {
    if (books == NULL) {
        fprintf(stderr, "Error: No records found.\n");
        return;
    }
    printf("Books List:\n");
    printf("\tBooks ID\tBooks Title\t\tAuthor Name\t\tBooks Copies\n");
    printf("---------------------------------------------------------------\n");
    Book *current = books;
    while (current != NULL) {
        printf("\t%d\t\t%-25s\t%-20s\t%d\n", 
               current->id, 
               current->title, 
               current->author, 
               current->copies);
        current = current->next;
    }

    printf("Press Any Key to return :");
    getchar();
}
