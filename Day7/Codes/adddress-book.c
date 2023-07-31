#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Structure to represent a contact
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

// Function to add a new contact
void addContact(struct Contact contacts[], int *numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Address book is full. Cannot add more contacts.\n");
        return;
    }

    struct Contact newContact;

    printf("Enter name: ");
    scanf("%s", newContact.name);
    printf("Enter phone: ");
    scanf("%s", newContact.phone);
    printf("Enter email: ");
    scanf("%s", newContact.email);

    contacts[*numContacts] = newContact;
    (*numContacts)++;

    printf("Contact added successfully.\n");
}

// Function to view all contacts
void viewContacts(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Address book is empty.\n");
        return;
    }

    printf("Contact List:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n\n", contacts[i].email);
    }
}

// Function to search for a contact by name
void searchContact(struct Contact contacts[], int numContacts) {
    char searchName[50];
    int found = 0;

    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n\n", contacts[i].email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact by name
void deleteContact(struct Contact contacts[], int *numContacts) {
    char deleteName[50];
    int found = 0;

    printf("Enter name to delete: ");
    scanf("%s", deleteName);

    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(contacts[i].name, deleteName) == 0) {
            for (int j = i; j < *numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*numContacts)--;
            printf("Contact deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    while (1) {
        printf("\nSimple Address Book\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                viewContacts(contacts, numContacts);
                break;
            case 3:
                searchContact(contacts, numContacts);
                break;
            case 4:
                deleteContact(contacts, &numContacts);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
