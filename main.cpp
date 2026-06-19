#include "library.h"

int main()
{
    Book library[MAX];
    int bookCount = 0;
    int choice;

    loadFromCSV(library, bookCount);

    do
    {
        cout << "\n===== LIBRARY SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books (Unsorted)\n";
        cout << "3. Search\n";
        cout << "4. Sort\n";
        cout << "5. Save & Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        switch (choice)
        {
        case 1:
            addBook(library, bookCount);
            break;

        case 2:
            displayBooks(library, bookCount);
            break;

        case 3:
            searchMenu(library, bookCount);
            break;

        case 4:
            sortMenu(library, bookCount);
            break;

        case 5:

            saveToCSV(library, bookCount);
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
