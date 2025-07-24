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

void add_book(Book **books);
void remove_book(int id);
void search_book(const char *title);
void list_books();
void save_library();
void load_library();

#endif // LIBRARY_H