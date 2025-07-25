#include"headers.h"

Book *books=NULL;
IssuedBook *issuBook = NULL;

int main() {
    int choice;

    read_books(&books);
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
                remove_book(&books);
                sleep(1);
                break;
            case 3: 
                printf("\nSearching for a book...\n"); 
                search_book(books);
                break;
            case 4: 
                printf("\nListing all books...\n"); 
                list_books(books);
                break;
            case 5: 
                printf("\nSaving books...\n"); 
                save_books(books);
                sleep(1);
                break;
            case 6: 
                printf("\nIssuing a book...\n"); 
                issue_book(books,&issuBook);
                sleep(1);
                break;
            case 7: 
                printf("\nReturning a book...\n"); 
                return_book(&issuBook);
                sleep(1);
                break;
            case 8: 
                printf("\nListing issued books...\n"); 
                list_issued_books(issuBook);
                break;
            case 9: 
                printf("\nSaving book Issued Details...\n"); 
                save_issued_books_details(issuBook);
                sleep(1);
                break;
            case 0: 
                printf("\nExiting the program...\n");
                save_books(books);
                save_issued_books_details(issuBook);
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
    printf("\t\t\t\t5. Save Books\n");
    printf("\t\t\t\t6. Issue Book\n");
    printf("\t\t\t\t7. Return Book\n");
    printf("\t\t\t\t8. List Issued Books\n");
    printf("\t\t\t\t9. Save Issued Books Details\n");
    printf("\t\t\t\t0. Exit\n");
    printf("\t\t\t----------------------------------------\n");
    printf("\n\t\t\tEnter your choice: ");
}

void display_book_search_menu() {
    printf("\n\n\t\t\tBOOK SEARCH MENU\n");
    printf("\t+-------------------------------------+\n");
    printf("\t| 1. Search by Book ID                |\n");
    printf("\t| 2. Search by Book Title             |\n");
    printf("\t| 0. Return to Main Menu              |\n");
    printf("\t+-------------------------------------+\n");
    printf("\tEnter your choice: ");
}

void display_search_book_menu() {
    printf("\n\n\t\t\tBOOK SEARCH MENU\n");
    printf("\t+-------------------------------------+\n");
    printf("\t| 1. Search by Book Title             |\n");
    printf("\t| 2. Search by Book Author            |\n");
    printf("\t| 0. Return to Main Menu              |\n");
    printf("\t+-------------------------------------+\n");
    printf("\tEnter your choice: ");
}