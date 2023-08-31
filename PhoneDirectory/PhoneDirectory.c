#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[15];
} Contact;

Contact phoneDirectory[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts < MAX_CONTACTS) {
        Contact newContact;
        printf("Enter name: ");
        scanf("%s", newContact.name);
        printf("Enter phone number: ");
        scanf("%s", newContact.phone);
        phoneDirectory[numContacts] = newContact;
        numContacts++;
        printf("Contact added successfully!\n");
    } else {
        printf("Phone directory is full.\n");
    }
}

void displayContacts() {
    printf("Phone Directory:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s, Phone: %s\n", phoneDirectory[i].name, phoneDirectory[i].phone);
    }
}

void searchContact() {
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(searchName, phoneDirectory[i].name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s, Phone: %s\n", phoneDirectory[i].name, phoneDirectory[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    int choice;
    do {
        printf("\nPhone Directory Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
