#include "library.h"
#include <limits>
#include <algorithm>
#include <fstream>  
#include <sstream>  

void loadFromCSV(Book library[], int& bookCount) {
    ifstream file("book_data.csv");
    if (!file.is_open()) {
        cout << "Database file not found. Starting with an empty library.\n";
        return;
    }

    string line;
    getline(file, line);

    bookCount = 0;
    while (getline(file, line) && bookCount < MAX) {
        stringstream ss(line);
        string dummyNo, title, isbn, genre, publisher;

        getline(ss, dummyNo, ',');
        getline(ss, title, ',');
        getline(ss, isbn, ',');
        getline(ss, genre, ',');
        getline(ss, publisher, ',');

        if (!title.empty()) {
            library[bookCount].title = title;
            library[bookCount].isbn = isbn;
            library[bookCount].genre = genre;
            library[bookCount].publisher = publisher;
            bookCount++;
        }
    }
    file.close();
    cout << "Loaded " << bookCount << " books successfully from Excel database!\n";
}

void saveToCSV(Book library[], int bookCount) {
    ofstream file("book_data.csv");
    if (!file.is_open()) {
        cout << "Error: Could not save data to database file.\n";
        return;
    }

    file << "No.,Title,ISBN,Genre,Publisher\n";

    for (int i = 0; i < bookCount; i++) {
        file << (i + 1) << ","
            << library[i].title << ","
            << library[i].isbn << ","
            << library[i].genre << ","
            << library[i].publisher << "\n";
    }
    file.close();
    cout << "Database updated successfully!\n";
}

// =====================
// AINAA PART
// =====================
void addBook(Book library[], int& bookCount) {
    if (bookCount >= MAX) {
        cout << "Library is full!\n";
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Title: ";
    getline(cin, library[bookCount].title);
    cout << "Enter ISBN: ";
    getline(cin, library[bookCount].isbn);
    cout << "Enter Genre: ";
    getline(cin, library[bookCount].genre);
    cout << "Enter Publisher: ";
    getline(cin, library[bookCount].publisher);
    bookCount++;

    cout << "Book added successfully!\n";

    saveToCSV(library, bookCount);
}


void displayBooks(Book library[], int bookCount) {
    if (bookCount == 0) {
        cout << "No books available.\n";
        return;
    }
    cout << "\n===== BOOK LIST =====\n";
    for (int i = 0; i < bookCount; i++) {
        cout << "\nBook " << i + 1 << endl;
        cout << "Title     : " << library[i].title << endl;
        cout << "ISBN      : " << library[i].isbn << endl;
        cout << "Genre     : " << library[i].genre << endl;
        cout << "Publisher : " << library[i].publisher << endl;
    }
}

// =====================
// SEARCH (ATHIRAH & DEE)
// =====================
void searchByISBN(Book library[], int bookCount) {
    string searchIsbn;
    bool found = false;
    cout << "Enter book ISBN to search: ";
    cin.ignore();
    getline(cin, searchIsbn);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].isbn == searchIsbn) {
            cout << "\nBook Found!" << endl;
            cout << "ISBN: " << library[i].isbn << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Genre: " << library[i].genre << endl;
            cout << "Publisher: " << library[i].publisher << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Book not found!!" << endl;
    }
}

void searchByTitle(Book library[], int bookCount) {
    string searchTitle;
    bool found = false;
    cout << "Enter book title to search: ";
    cin.ignore();
    getline(cin, searchTitle);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].title == searchTitle) {
            cout << "\nBook Found!" << endl;
            cout << "ISBN: " << library[i].isbn << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Genre: " << library[i].genre << endl;
            cout << "Publisher: " << library[i].publisher << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Book not found!!" << endl;
    }
}

void searchMenu(Book library[], int bookCount) {
    int choice;
    do {
        cout << "\n===== SEARCH MENU =====\n";
        cout << "1. Search by ISBN\n";
        cout << "2. Search by Title\n";
        cout << "3. Back\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: searchByISBN(library, bookCount); break;
        case 2: searchByTitle(library, bookCount); break;
        }
    } while (choice != 3);
}

// =====================
// SORT (JEMANG & HAJA)
// =====================
void sortByTitle(Book library[], int bookCount) {
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = 0; j < bookCount - i - 1; j++) {
            if (library[j].title > library[j + 1].title) {
                swap(library[j], library[j + 1]);
            }
        }
    }
    cout << "Sorted by Title!\n";
    displayBooks(library, bookCount);
}

void sortByGenre(Book library[], int bookCount) {
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = 0; j < bookCount - i - 1; j++) {
            if (library[j].genre > library[j + 1].genre) {
                swap(library[j], library[j + 1]);
            }
        }
    }
    cout << "Sorted by Genre!\n";
    displayBooks(library, bookCount);
}

void sortByPublisher(Book library[], int bookCount) {
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = 0; j < bookCount - i - 1; j++) {
            if (library[j].publisher > library[j + 1].publisher) {
                swap(library[j], library[j + 1]);
            }
        }
    }
    cout << "Sorted by Publisher!\n";
    displayBooks(library, bookCount);
}

void sortMenu(Book library[], int bookCount) {
    int choice;
    do {
        cout << "\n===== SORT MENU =====\n";
        cout << "1. Sort by Title (A-Z)\n";
        cout << "2. Sort by Genre\n";
        cout << "3. Sort by Publisher\n";
        cout << "4. Back\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: sortByTitle(library, bookCount); break;
        case 2: sortByGenre(library, bookCount); break;
        case 3: sortByPublisher(library, bookCount); break;
        }
    } while (choice != 4);
}
