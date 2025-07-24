#include"headers.h"

Book *books=NULL;

int main() {
    int choice;

    do {
        system("clear");
        main_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1: 
                printf("\nAdding a book...\n"); 
                add_book(&books);
                sleep(1);
                break;
            case 2: 
                printf("\nRemoving a book...\n"); 
                sleep(1);
                break;
            case 3: 
                printf("\nSearching for a book...\n"); 
                sleep(1);
                break;
            case 4: 
                printf("\nListing all books...\n"); 
                list_books(books);
                sleep(1);
                break;
            case 5: 
                printf("\nIssuing a book...\n"); 
                sleep(1);
                break;
            case 6: 
                printf("\nReturning a book...\n"); 
                sleep(1);
                break;
            case 7: 
                printf("\nListing issued books...\n"); 
                sleep(1);
                break;
            case 0: 
                printf("\nExiting the program...\n"); 
                sleep(1);
                return 0;
            default: 
                printf("\nInvalid choice. Please try again.\n");
                sleep(1);
        }
    } while (choice != 0);

    return 0;
}

void main_menu() {
    printf("\n\n");
    printf("\t\t\t----------------------------------------\n");
    printf("\t\t\t\tLIBRARY MANAGEMENT SYSTEM\n");
    printf("\t\t\t----------------------------------------\n");
    printf("\t\t\t\t1. Add Book\n");
    printf("\t\t\t\t2. Remove Book\n");
    printf("\t\t\t\t3. Search Book\n");
    printf("\t\t\t\t4. List Books\n");
    printf("\t\t\t\t5. Issue Book\n");
    printf("\t\t\t\t6. Return Book\n");
    printf("\t\t\t\t7. List Issued Books\n");
    printf("\t\t\t\t0. Exit\n");
    printf("\t\t\t----------------------------------------\n");
    printf("\n\t\t\tEnter your choice: ");
}