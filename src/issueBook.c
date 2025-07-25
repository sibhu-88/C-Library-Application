#include"headers.h"

void issue_book(Book *books, IssuedBook **issuedBooks){
    int bookId, found = 0;

    if (!books) {
        fprintf(stderr, "No books available.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    printf("\n\tEnter the Book Id : ");
    scanf("%d", &bookId);

    Book *current = books;
    while (current) {
        if (bookId == current->id) {
            printf("\n\tBook Id : %d\tBook Title : %s\tBook Author : %s\tCopies : %d\n",
                current->id, current->title, current->author, current->copies);
            if (current->copies == 0) {
                fprintf(stderr, "No More Book Copies available.\n");
                return;
            }
            found = 1;
            break;
        }
        current = current->next;
    }

    if (found) {
        IssuedBook *newIssuedBook = malloc(sizeof(IssuedBook));
        if (!newIssuedBook) {
            fprintf(stderr, "Memory allocation failed.\n");
            return;
        }
        memset(newIssuedBook, 0, sizeof(IssuedBook));

        newIssuedBook->book = current;

        printf("\n\tEnter the Borrower Id : ");
        scanf("%d", &newIssuedBook->borrower_id);

        printf("\n\tEnter the Borrower Name : ");
        scanf(" %[^\n]", newIssuedBook->borrower_name);

        sprintf(newIssuedBook->issue_date, "%02d-%02d-%04d",
            tm_info->tm_mday,
            tm_info->tm_mon + 1,
            tm_info->tm_year + 1900);

        strcpy(newIssuedBook->return_date, "NIL");

        printf("Borrower ID entered: %d\n", newIssuedBook->borrower_id);
        printf("Borrower Name entered: %s\n", newIssuedBook->borrower_name);
        printf("Issue Date recorded: %s\n", newIssuedBook->issue_date);

        newIssuedBook->next = NULL;

        if (*issuedBooks == NULL) {
            *issuedBooks = newIssuedBook;
        } else {
            IssuedBook *temp = *issuedBooks;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newIssuedBook;
        }

        current->copies--;

        printf("\n\tBook issued successfully on %s.\n", newIssuedBook->issue_date);

    } else {
        fprintf(stderr, "Error: Book record not found.\n");
    }
}

void return_book(IssuedBook **issued_books) {
    if (!*issued_books) {
        printf("No books have been issued.\n");
        return;
    }

    int borrowerId, bookId;

    printf("\n\tEnter the Borrower ID: ");
    scanf("%d", &borrowerId);

    printf("\n\tEnter the Book ID to return: ");
    scanf("%d", &bookId);

    IssuedBook *current = *issued_books;
    while (current) {
        if (current->borrower_id == borrowerId &&
            current->book->id == bookId &&
            strcmp(current->return_date, "NIL") == 0) {
            
            time_t t = time(NULL);
            struct tm *tm_info = localtime(&t);

            sprintf(current->return_date, "%02d-%02d-%04d",
                    tm_info->tm_mday,
                    tm_info->tm_mon + 1,
                    tm_info->tm_year + 1900);

            if (current->book)
                current->book->copies++;

            printf("\n\tBook with ID %d returned successfully by Borrower ID %d on %s.\n",
                   bookId, borrowerId, current->return_date);
            return;
        }
        current = current->next;
    }

    fprintf(stderr, "No issued book found with Book ID %d for Borrower ID %d, or book already returned.\n",
            bookId, borrowerId);
}

void list_issued_books(IssuedBook *issuedBooks) {
    if (issuedBooks == NULL) {
        fprintf(stderr, "Error: No issued book records found.\n");
        return;
    }

    printf("\n\t\tIssued Books List:\n");
    printf("\t+------+----------------------+----------------------+---------------+----------------+----------------+\n");
    printf("\t|  ID  |       Title          |   Borrower Name      | Borrower ID   |   Issue Date   |  Return Date   |\n");
    printf("\t+------+----------------------+----------------------+---------------+----------------+----------------+\n");

    while (issuedBooks != NULL) {
        printf("\t| %4d | %-20s | %-20s | %-13d | %-14s | %-14s |\n",
               issuedBooks->book->id,
               issuedBooks->book ? issuedBooks->book->title : "UNKNOWN",
               issuedBooks->borrower_name,
               issuedBooks->borrower_id,
               issuedBooks->issue_date,
               (strlen(issuedBooks->return_date) > 0) ? issuedBooks->return_date : "NIL");
    printf("\t+------+----------------------+----------------------+---------------+----------------+----------------+\n");

        issuedBooks = issuedBooks->next;
    }

    printf("\t+------+----------------------+----------------------+---------------+----------------+----------------+\n");
    printf("\n\n\t\tPress Enter to return: ");
    getchar(); 
    getchar(); 
}

