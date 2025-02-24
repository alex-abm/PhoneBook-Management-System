#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

int main() 
{
    PhoneBook pb;
    int max_entry;
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char command[10];

    printf("enter the limit of entries: ");
    scanf("%d", &max_entry);
    initialize(&pb, max_entry);

    while (1) 
    {
        printf("choose a command by typing it (insert, search, print, exit): ");
        scanf("%s", command);

        if (strcmp(command, "insert") == 0) 
        {
            printf("name: ");
            scanf("%s", name);
            printf("phone number: ");
            scanf("%s", phone);
            insert(&pb, name, phone);
        } 
        else if (strcmp(command, "search") == 0) 
        {
            printf("name: ");
            scanf("%s", name);
            const char *number = search(&pb, name);
            if (number)
            {
                printf("%s: %s\n", name, number);
            } else
            {
                printf("%s was not found\n", name);
            }
        }
        else if (strcmp(command, "print") == 0)
        {
            print(&pb);
        }
        else if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else
        {
            printf("choose a correct command and make sure for typos\n");
        }
    }

    destruct(&pb);
    return 0;
}