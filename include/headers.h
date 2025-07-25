#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Book{
    int id;
    char title[100];
    char author[50];
    int copies;
    struct Book *next;
} Book;

typedef struct IssuedBook {
    Book *book;               
    int book_id;              
    char borrower_name[100];  
    char issue_date[20];    
    char return_date[20];    
    struct IssuedBook *next; 
} IssuedBook;

void main_menu();
void display_book_search_menu();
void display_search_book_menu();

void add_book(Book **books);
void remove_book(Book **books);
void search_book(Book *books);
void list_books(Book *books);
void save_books(Book *books);
void read_books(Book **books);

void issue_book(Book *books, IssuedBook **issued_books);
void return_book(Book *books, IssuedBook **issued_books);
void list_issued_books(IssuedBook *issued_books);
void save_issued_books_details(IssuedBook *issued_books);

#endif // LIBRARY_H