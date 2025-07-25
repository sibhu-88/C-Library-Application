#include "headers.h"

void save_books(Book *books) {
    if (books == NULL) {
        fprintf(stderr, "Error: No records found.\n");
        return;
    }

    FILE *file = fopen("books.xls", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "Books Id\tBook Title\tAuthor Name\tCopies\n");

    Book *current = books;
    while (current != NULL) {
        fprintf(file, "%d\t%s\t%s\t%d\n", 
               current->id, 
               current->title, 
               current->author, 
               current->copies);
        current = current->next;
    }

    fclose(file);
    printf("Library successfully saved to books.xls\n");
}

void read_books(Book **books) {
    FILE *file = fopen("books.xls", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[200];
    fgets(line, sizeof(line), file);

    while (1) {
        Book *newBook = (Book *)malloc(sizeof(Book));
        if (newBook == NULL) {
            perror("Memory allocation failed");
            break;
        }

        int result = fscanf(file, "%d\t%99[^\t]\t%99[^\t]\t%d", 
                           &newBook->id,
                           newBook->title,
                           newBook->author,
                           &newBook->copies);
        
        if (result != 4) {
            free(newBook);
            break;
        }

        newBook->next = NULL;

        if (*books == NULL) {
            *books = newBook;
        } else {
            Book *current = *books;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newBook;
        }

    //  printf("New Book %d %s %s %d added successfully\n", newBook->id,newBook->title,newBook->author,newBook->copies);
    }

    fclose(file);
}

void save_issued_books_details(IssuedBook *issued_books) {
    if (issued_books == NULL) {
        fprintf(stderr, "Error: No records found.\n");
        return;
    }

    FILE *file = fopen("issuedBooks.xls", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "Books Id\tBook Title\tBorrower Name\tIssue Date\tReturn Date\n");

    IssuedBook *current = issued_books;
    while (current != NULL) {
        fprintf(file, "%d\t%s\t%s\t%s\t%s\n",
                current->book_id,
                current->book->title,
                current->borrower_name,
                current->issue_date,
                current->return_date);
        current = current->next;
    }

    fclose(file);
    printf("Issued books successfully saved to issuedBooks.xls\n");
}