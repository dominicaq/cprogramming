#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "md5.h"

const int PASS_LEN=20;        // Maximum any password will be
const int HASH_LEN=33;        // Length of MD5 hash strings

int fileLength(char *fname)
{
    struct stat info;
    int ret = stat(fname, &info);
    
    if (ret == -1)
        return -1;
    else
        return info.st_size;
}
// Given a hash and a plaintext guess, return 1 if
// the hash of the guess matches the given hash.
// That is, return 1 if the guess is correct.
int tryguess(char *hash, char *guess)
{
    // Hash the guess using MD5
    char *holdGuess = md5(guess, strlen(guess));
    
    // Compare the two hashes
    if (strcmp(hash, holdGuess) == 0)
    {
        free(holdGuess);
        return 1;
    }

    // Free any malloc'd memory
    free(holdGuess);
    return 0;
}

// Read in the dictionary file and return the array of strings
// and store the length of the array in size.
// This function is responsible for opening the dictionary file,
// reading from it, building the data structure, and closing the
// file.
char **read_dictionary(char *filename, int *size)
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
    // Allocate space and return pointer array
    char **temp = malloc(fsize * sizeof(char *));
    temp[0] = &dict[0];
    
    int j = 1;
    for (int i = 0; i < fileSize-1; i++)
    {
        if (dict[i] == '\0')
        {
            temp[j] = &dict[i+1];
            j++;
        }
    }
    return temp;
}

int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }
    
    // Read the dictionary file into an array of strings.
    int dlen = 0;
    char **dict = read_dictionary(argv[2], &dlen);
    
    // Open the hash file for reading.
    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        printf("Can't open %s for reading.\n", argv[1]);
        exit(1);
    }
    // For each hash, try every entry in the dictionary.
    char line[HASH_LEN];
    while(fgets(line, HASH_LEN, fp) != NULL)
    {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';
        
        for (int i = 0; i < dlen; i++)
        {
            if (tryguess(line, dict[i]) == 1)
            {
                printf("Match found: %s, %s\n", dict[i], line);
                break;
            }
        }
    }
    fclose(fp);
}