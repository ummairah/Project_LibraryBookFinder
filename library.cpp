#include "library.h"
#include <limits>
#include <algorithm>
#include <fstream>  
#include <sstream>  
#include <iomanip>

//Function display in table 
void displayBookHeader()
{
    cout << left << setw(5) << "No."  << setw(15) << "ISBN" << setw(35) << "Title" << setw(20) << "Genre" << setw(20) << "Publisher" << endl;
    cout << string(85, '-') << endl;
}
void displayBookRow(int no, const Book& book)
{
    cout << left << setw(5) << no << setw(15) << book.isbn << setw(35) << book.title << setw(20) << book.genre << setw(20) << book.publisher << endl;
}

//Function to validate user input for menu choices (so if user enter char instead of int, it will not cause infinite loop)
template <typename T>
void getValidInput(T& value)
{
    if (!(cin >> value))
    {
        cout << "Invalid input! Please enter the right input\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

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
			//library[bookCount] = dummyNo;
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
	//DISPLAY BOOKS IN CSV FORMAT (TUKAR DALAM TABLE)
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
    bool duplicate;
    string isbn;
    if (bookCount >= MAX) {
        cout << "Library is full!\n";
        return;
    }
	

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Title: ";
    getline(cin, library[bookCount].title);
   
    //CHECK FOR DUPLICATE ISBN
    do
    {
        duplicate = false;

        cout << "Enter ISBN: ";
        getline(cin, isbn);

        for (int i = 0; i < bookCount; i++)
        {
            if (library[i].isbn == isbn)
            {
                cout << "ISBN already exists! Please enter a different ISBN.\n";
                duplicate = true;
                break;
            }
        }

    } while (duplicate);
    library[bookCount].isbn = isbn;
    
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
    displayBookHeader();
    for (int i = 0; i < bookCount; i++) {
        displayBookRow(i + 1, library[i]);
    }
}

// =====================
// SEARCH (ATHIRAH & DEE)
// =====================
void searchByISBN(Book library[], int bookCount) {
    string searchIsbn;
    bool found = false;
    cout << "Enter book ISBN to search: \n";
    cin.ignore();
    getline(cin, searchIsbn);
    displayBookHeader();
    for (int i = 0; i < bookCount; i++) {
        if (library[i].isbn == searchIsbn) {
            displayBookRow(i + 1, library[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Book not found!" << endl;
    }
}

void searchByTitle(Book library[], int bookCount) {
    string searchTitle;
    bool found = false;
    cout << "Enter book title to search: ";
    cin.ignore();
    getline(cin, searchTitle);
    displayBookHeader();
    for (int i = 0; i < bookCount; i++) {
        if (library[i].title == searchTitle) {
            displayBookRow(i + 1, library[i]);
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
        getValidInput(choice);
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

        getValidInput(choice);

        switch (choice) {
        case 1: sortByTitle(library, bookCount); break;
        case 2: sortByGenre(library, bookCount); break;
        case 3: sortByPublisher(library, bookCount); break;
       
        }
    } while (choice != 4);
}
