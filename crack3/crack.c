#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "md5.h"

const int PASS_LEN=50;        // Maximum any password can be
const int HASH_LEN=33;        // Length of MD5 hash strings

// Stucture to hold both a plaintext password and a hash.
struct entry 
{
    char password[PASS_LEN];
    char hash[HASH_LEN];
};

int fileLength(char *fname)
{
    struct stat info;
    int ret = stat(fname, &info);
    
    if (ret == -1)
        return -1;
    else
        return info.st_size;
}

int compare(const void *a, const void *b)
{
    return strcmp(((struct entry *)a)->hash, ((struct entry *)b)->hash);
}

int wordSearch(const void *a, const void *b)
{
    return strcmp(a, ((struct entry *)b)->hash);
}

// TODO
// Read in the dictionary file and return an array of structs.
// Each entry should contain both the hash and the dictionary
// word.
struct entry *read_dictionary(char *filename, int *size)
{
    int fileSize = fileLength(filename);
    char *dict = malloc(fileSize);
    
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Can't open %s for reading.", filename);
        exit(1);
    }
    fread(dict, sizeof(char), fileSize, fp);
    fclose(fp);
    
    int fsize = 0;
    // Change new lines into nulls and count them as we go
    for (int i = 0; i < fileSize; i++)
    {
        if (dict[i] == '\n')
        {
            dict[i] = '\0';
            fsize++;
        }
    }
    *size = fsize;
    // Finished reading the file
    // Store password and its hash into a struct
    struct entry *entries = malloc(fsize * sizeof(struct entry));
    
    // Now entering the loop
    int j = 1;
    for (int i = 0; i < fileSize; i++)
    {
        if (dict[i] == '\0')
        {
            char *word = &dict[i+1];
            char *wordHash = md5(word, strlen(word));
            strcpy(entries[j].password, word);
            strcpy(entries[j].hash, wordHash);
            j++;
        }
    }
    return entries;
}

int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // Read the dictionary file into an array of entry structures
    int length = 0;
    struct entry *dict = read_dictionary(argv[2], &length);
    
    // Sort the hashed dictionary using qsort.
    // You will need to provide a comparison function.
    qsort(dict, length, sizeof(struct entry), compare); // Compare function is interchangeable

    // Open the hash file for reading.
    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        printf("Can't open %s for reading.\n", argv[1]);
        exit(1);
    }
    
    int count = 1;
    char line[100];
    while(fgets(line, 100, fp) != NULL)
    {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';
        
        struct entry *lookup = bsearch(line, dict, length, sizeof(struct entry), wordSearch);

        if (lookup != NULL)
        {
            printf("Match %d: %s, %s\n", count, lookup->password, line);
            count++;
        }
    }
    printf("Passwords cracked: %d\n", count-1);
    // For each hash, search for it in the dictionary using
    // binary search.
    // If you find it, get the corresponding plaintext dictionary word.
    // Print out both the hash and word.
}
