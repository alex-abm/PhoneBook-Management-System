#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phonebook.h"


void insert(PhoneBook *pb, const char *name, const char *phone)
{
    if (pb->num_entry < pb->max_entry) 
    {
        Entry *current_entry = &pb->entry[pb->num_entry];
        strncpy(current_entry->name, name, MAX_NAME - 1);
        current_entry->name[MAX_NAME - 1] = '\0';
        strncpy(current_entry->phone, phone, MAX_PHONE - 1);
        current_entry->phone[MAX_PHONE - 1] = '\0';
        pb->num_entry++;
    } 
    else 
    {
        printf("phonebook is full\n");
    }
}

const char *search(const PhoneBook *pb, const char *name)
{
    for (int i = 0; i < pb->num_entry; ++i)
    {
        if (strcmp(pb->entry[i].name, name) == 0)
        {
            return pb->entry[i].phone;
        }
    }
    return NULL;
}

void print(const PhoneBook *pb) 
{
    for (int i = 0; i < pb->num_entry; ++i)
    {
        printf("%s: %s\n", pb->entry[i].name, pb->entry[i].phone);
    }
}

void initialize(PhoneBook *pb, int max_entry) 
{
    pb->entry = malloc(max_entry * sizeof(Entry));
    if (!pb->entry)
    {
        fprintf(stderr, "memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    pb->num_entry = 0;
    pb->max_entry = max_entry;
}

void destruct(PhoneBook *pb)
{
    free(pb->entry);
    pb->entry = NULL;
    pb->num_entry = 0;
    pb->max_entry = 0;
}