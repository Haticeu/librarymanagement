#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[100];
    char author[100];
    int available;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook();
void searchBook();
void borrowBook();
void listBooks();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n*** Library Management System ***\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Borrow Book\n");
        printf("4. List All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                listBooks();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book newBook;
    newBook.id = bookCount + 1;
    printf("Enter book title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';  // Remove trailing newline

    printf("Enter book author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';  // Remove trailing newline

    newBook.available = 1;

    library[bookCount] = newBook;
    bookCount++;

    printf("Book added successfully! Book ID: %d\n", newBook.id);
}

void searchBook() {
    char title[100];
    printf("Enter book title to search: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';  // Remove trailing newline

    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, title) != NULL) {
            printf("Book ID: %d, Title: %s, Author: %s, Available: %s\n",
                   library[i].id, library[i].title, library[i].author,
                   library[i].available ? "Yes" : "No");
            return;
        }
    }
    printf("Book not found!\n");
}

void borrowBook() {
    int bookId;
    printf("Enter book ID to borrow: ");
    scanf("%d", &bookId);
    clearInputBuffer();

    if (bookId <= 0 || bookId > bookCount) {
        printf("Invalid book ID!\n");
        return;
    }

    if (library[bookId - 1].available) {
        library[bookId - 1].available = 0;
        printf("Book borrowed successfully!\n");
    } else {
        printf("Book is already borrowed!\n");
    }
}

void listBooks() {
    if (bookCount == 0) {
        printf("No books found!\n");
        return;
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book ID: %d, Title: %s, Author: %s, Available: %s\n",
               library[i].id, library[i].title, library[i].author,
               library[i].available ? "Yes" : "No");
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

  system("PAUSE");	
  return 0;
}
