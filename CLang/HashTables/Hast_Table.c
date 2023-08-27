#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE ((person*)0xFFFFFFFFFFFFFFFFUL)
//data to insert
typedef struct person
{
    char name[MAX_NAME];
    int age;
} person;

//hash table size
person *hash_table[TABLE_SIZE];

//initiallize the hash table to NULL
void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
            hash_table[i] = NULL;
     //table is empty
}

//generate a hash code for each value
unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME), i;
    unsigned int hash_value = 0;

    for (i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return (hash_value);
}

//insert data to map
bool hash_table_insert(person *p)
{

    if (p == NULL)
        return (false);

    int index = hash(p->name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = p;
            return (true);
        }
    }
    return (false);
}

//delete a data in the table
person *hash_table_delete(char *name)
{
    int index = hash(name);
    person *tmp;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
         int try = (index + i) % TABLE_SIZE;
         if (hash_table[try] == NULL)
            return (NULL);
         if (hash_table[try] == DELETED_NODE)
            continue;
         if (strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0)
        {
            tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return (tmp);
        }
        else
            return (NULL);
    }
}

//find a person in the table by their name
person *hash_table_lookup(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + 1) % TABLE_SIZE;
        if (hash_table[try] == NULL)
            return (false); //not here
        if (hash_table[try] == DELETED_NODE)
            continue;
        if (strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0)
            return (hash_table[index]);
    }
    return (NULL);
}
//print table
void print_table()
{
printf("Start\n");
    for (int i = 0; i < TABLE_SIZE; i++)
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else if (hash_table[i] == DELETED_NODE)
        {
            printf("\t%i\t<deleted>\n", i);
        }
        else
        {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
printf("End\n");
}

int main()
{
    init_hash_table();
    person peoples[] = {
        {"Jacob", 25},
        {"Kate", 27},
        {"Mpho", 14},
        {"Sarah", 54},
        {"Edna", 15},
        {"Marren", 25},
        {"Eliza", 34},
        {"Robert",17},
        {"Jane", 75}
    };
    for (int i = 0; i < TABLE_SIZE; i++)
        hash_table_insert(&peoples[i]);
    
    print_table();

    person *tmp = hash_table_lookup("Mpho");
    if (tmp == NULL)
        printf("Not found\n");
    else
        printf("Found %s\n", tmp->name);




    // hash_table_delete("Mpho");
    // tmp = hash_table_lookup("George");
    // if (tmp == NULL)
    //     printf("Not found\n");
    // else
    //     printf("Found %s\n", tmp->name);

    // print_table();
    // printf("Jacop => %u\n", hash("Jacop"));
    // printf("Natalie => %u\n", hash("Natalie"));
    // printf("Sara => %u\n", hash("Sara"));
    // printf("Mpho => %u\n", hash("Mpho"));
    // printf("Tebogo => %u\n", hash("Tebogo"));
    // printf("Ron => %u\n", hash("Ron"));
    // printf("Jane => %u\n", hash("Jane"));
    // printf("Maren => %u\n", hash("Maren"));
    // printf("Bill => %u\n", hash("Bill"));
    return (0);
}
