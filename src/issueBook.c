#include"headers.h"

void list_issued_books(IssuedBook *issued_books) {
    printf("\n\t\tIssued Books List:\n");
    printf("\t+------+---------------------+---------------------+----------------+---------------+\n");
    printf("\t|  ID  |      Title          |     Borrower        |   Issue Date    | Return Date   |\n");
    printf("\t+------+---------------------+---------------------+----------------+---------------+\n");

    while (issued_books != NULL) {
        printf("\t| %4d | %-20s | %-20s | %15s | %15s |\n",
               issued_books->book_id,
               issued_books->book->title,
               issued_books->borrower_name,
               issued_books->issue_date,
               issued_books->return_date);
        issued_books = issued_books->next;
    }
    printf("\t+------+---------------------+---------------------+----------------+---------------+\n");
}
