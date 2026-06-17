#include "library.h"

#include <limits>

// =====================
// AINAA PART
// =====================
//TRY TEST
void addBook(Book library[], int& bookCount)
{
    if (bookCount >= MAX)
    {
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
}

void displayBooks(Book library[], int bookCount)
{
    if (bookCount == 0)
    {
        cout << "No books available.\n";
        return;
    }

    cout << "\n===== BOOK LIST (UNSORTED) =====\n";

    for (int i = 0; i < bookCount; i++)
    {
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

void searchByISBN(Book library[], int bookCount)
{

}

void searchByTitle(Book library[], int bookCount)
{
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
            cout << "Publisher: " << library[i].publisher << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "Book not found!!" << endl;
    }
}

void searchMenu(Book library[], int bookCount)
{
    int choice;

    do
    {
        cout << "\n===== SEARCH MENU =====\n";
        cout << "1. Search by ISBN\n";
        cout << "2. Search by Title\n";
        cout << "3. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            searchByISBN(library, bookCount);
            break;
        case 2:
            searchByTitle(library, bookCount);
            break;
        }
    } while (choice != 3);
}

// =====================
// SORT (JEMANG & HAJA)
// =====================

void sortByTitle(Book library[], int bookCount)
{

}

void sortByGenre(Book library[], int bookCount)
{

}

void sortByPublisher(Book library[], int bookCount)
{

}

void sortMenu(Book library[], int bookCount)
{
    int choice;

    do
    {
        cout << "\n===== SORT MENU =====\n";
        cout << "1. Sort by Title (A-Z)\n";
        cout << "2. Sort by Genre\n";
        cout << "3. Sort by Publisher\n";
        cout << "4. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sortByTitle(library, bookCount);
            break;
        case 2:
            sortByGenre(library, bookCount);
            break;
        case 3:
            sortByPublisher(library, bookCount);
            break;
        }
    } while (choice != 4);
}