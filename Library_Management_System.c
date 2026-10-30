
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    int quantity;
    int available;
    struct Book *next;
};

struct Book *head = NULL;

// Add a new book
void addBook()
{
    struct Book *newBook, *temp;

    newBook = (struct Book *)malloc(sizeof(struct Book));

    printf("\nEnter Book ID: ");
    scanf("%d", &newBook->id);

    temp = head;
    while (temp != NULL)
    {
        if (temp->id == newBook->id)
        {
            printf("Book ID already exists!\n");
            free(newBook);
            return;
        }
        temp = temp->next;
    }

    printf("Enter Book Title: ");
    scanf(" %[^\n]", newBook->title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", newBook->author);

    printf("Enter Quantity: ");
    scanf("%d", &newBook->quantity);

    if (newBook->quantity <= 0)
    {
        printf("Invalid quantity!\n");
        free(newBook);
        return;
    }

    newBook->available = newBook->quantity;
    newBook->next = NULL;

    if (head == NULL)
        head = newBook;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newBook;
    }

    printf("Book added successfully!\n");
}

// Display all books
void displayBooks()
{
    struct Book *temp = head;

    if (temp == NULL)
    {
        printf("\nNo books available!\n");
        return;
    }

    printf("\nID\tTitle\t\tAuthor\t\tQuantity\tAvailable\n");

    while (temp != NULL)
    {
        printf("%d\t%s\t\t%s\t\t%d\t\t%d\n",
               temp->id, temp->title, temp->author,
               temp->quantity, temp->available);

        temp = temp->next;
    }
}

// Search a book
void searchBook()
{
    int id, found = 0;
    struct Book *temp = head;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("\nBook Found!\n");
            printf("ID: %d\n", temp->id);
            printf("Title: %s\n", temp->title);
            printf("Author: %s\n", temp->author);
            printf("Available Copies: %d\n", temp->available);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found)
        printf("Book not found!\n");
}

// Issue a book
void issueBook()
{
    int id;
    struct Book *temp = head;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (temp->available > 0)
            {
                temp->available--;
                printf("Book issued successfully!\n");
            }
            else
                printf("Book is not available!\n");

            return;
        }
        temp = temp->next;
    }

    printf("Book not found!\n");
}

// Return a book
void returnBook()
{
    int id;
    struct Book *temp = head;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (temp->available < temp->quantity)
            {
                temp->available++;
                printf("Book returned successfully!\n");
            }
            else
                printf("No issued copy to return!\n");

            return;
        }
        temp = temp->next;
    }

    printf("Book not found!\n");
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
