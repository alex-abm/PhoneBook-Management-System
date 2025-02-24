#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#define MAX_NAME 100
#define MAX_PHONE 20

typedef struct
{
    char name[MAX_NAME];
    char phone[MAX_PHONE];
} Entry;

typedef struct 
{
    Entry *entry;
    int num_entry;
    int max_entry;
} PhoneBook;

void initialize(PhoneBook *pb, int max_entry);
void destruct(PhoneBook *pb);
void insert(PhoneBook *pb, const char *name, const char *phone);
const char* search(const PhoneBook *pb, const char *name);
void print(const PhoneBook *pb);

#endif