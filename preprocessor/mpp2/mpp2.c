#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preProc(char *s, int argc);
void addInclude(char *s, int index, char *fname, int argc);
FILE *fpout;
int longComment = 0;
int line = 1;

int main(int argc, char *argv[])
{
    // Check to see if user supplied 2 arguments
    if (argc < 2)
    {
        printf("Please supply an input and optionally an output file\n");
        exit(2);
    }
    
    // Open first argument for reading
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (!fp)
    {
        printf("Can't open %s for reading\n", argv[1]);
        exit(1);
    }
    
    // Open second argument for writing
    if (argc == 3)
    {
        fpout = fopen(argv[2], "w");
        if (!fpout)
        {
            printf("Can't open %s for writing\n", argv[2]);
            exit(1);
        }
    }
    
    // Read all lines and print them as we go
    char line[100];
    while(fgets(line, 100, fp) != NULL)
    {
        preProc(line, argc);

        if (argc == 3)
            fprintf(fpout, "%s", line);
        else
            printf("%s", line);
    }
    
    // Close file
    fclose(fp);
    if (argc == 3) fclose(fpout);
}

void addInclude(char *s, int index, char *fname, int argc)
{
    FILE *fp = fopen(fname, "r");
    
    if (!fp)
    {
        printf("Line %d: Can't find %s for include\n", line, fname);
    }
    else
    {
        // Read lines into output
        char line[100];
        s[index] = '\0';
        while(fgets(line, 100, fp) != NULL)
        {
            preProc(line, argc);
            if (argc == 3)
                fprintf(fpout, "%s", line);
            else
                printf("%s", line);
        }
        fclose(fp);
    }
}

// Gathers name of include
char *includeName(char *s, int index)
{
    char *final;
    final = (char*)calloc(20, sizeof(char));
    
    int flag = 0;
    int j = 0;
    
    for (int i = index; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            flag = 1;
            i += 1;
        }
        
        if (s[i] =='\n')
            break;
            
        if (flag)
        {
            final[j] = s[i];
            j++;
        }
    }
    return final;
}

// Can handle the following: /* */ // and #include
void preProc(char *s, int argc)
{
    char *temp;
    int quoteFlag = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '/' && s[i+1] == '*' && !quoteFlag)
            longComment = 1;
        else if (s[i] == '*' && s[i+1] == '/' && !quoteFlag)
        {
            longComment = 0;
            s[i] = '\0';
        }
        
        if (!longComment)
        {
            if (s[i] == '"')
                quoteFlag = 1;
            else if (s[i] == '"' && quoteFlag) 
                quoteFlag = 0;
                
            // Include
            if ((s[i-1] == '\n' || s[i-1] == '\0') && s[i] == '#' && s[i+1] == 'i'  && s[i+2] == 'n'  
            && s[i+3] == 'c'  && s[i+4] == 'l'  && s[i+5] == 'u'  && s[i+6] == 'd'  && s[i+7] == 'e' && !quoteFlag)
            {
                temp = includeName(s, i);
                addInclude(s, i, temp, argc);
            }
            
            // Comment Stripping
            if (s[i] == '/' && s[i+1] == '/' && !quoteFlag)
            {
                s[i] = '\0';
                s[i-1] = '\n';
            }
        } 
        else
        {
            s[i] = '\0';
            s[i-1] = '\n';
        }
    }
    line++;
}