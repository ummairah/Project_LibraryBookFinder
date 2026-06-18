#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

struct Book {
    string title;
    string isbn;
    string genre;
    string publisher;
};

// Excel Database Functions
void loadFromCSV(Book library[], int& bookCount);
void saveToCSV(Book library[], int bookCount);

// Ainaa
void addBook(Book library[], int& bookCount);
void displayBooks(Book library[], int bookCount);

// Search (Athirah & Dee)
void searchMenu(Book library[], int bookCount);
void searchByISBN(Book library[], int bookCount);
void searchByTitle(Book library[], int bookCount);

// Sort (Jemang & Haja)
void sortMenu(Book library[], int bookCount);
void sortByTitle(Book library[], int bookCount);
void sortByGenre(Book library[], int bookCount);
void sortByPublisher(Book library[], int bookCount);

#endif
