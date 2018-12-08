#include <stdio.h>
#include <libsocket/libinetsocket.h>
#include <stdlib.h>
#include <string.h>

char *cleanup(char *data);

int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        printf("Usage: ./weather ZIPCODE\n");
        exit(1);
    }
    
    // Networking
    char *ZIPCODE = argv[1];
    // http://api.wunderground.com/api/1655f919bbcd29ed/conditions/q/ZIPCODE.json
    int fd = create_inet_stream_socket("api.wunderground.com", "80", LIBSOCKET_IPv4, 0);
    if (fd == -1)
    {
        printf("Can't connect\n");
        exit(1);
    }
    
    FILE *f = fdopen(fd, "rb+");
    if (!f)
    {
        printf("Can't convert fd to FILE\n");
        exit(1);
    }
    // http://api.wunderground.com/api/1655f919bbcd29ed/conditions/q/ZIPCODE.json
    //http://api.wunderground.com/api/1655f919bbcd29ed/conditions/forecast10day/q/ZIPCODE.json
    fprintf(f, "GET /api/1655f919bbcd29ed/conditions/forecast10day/q/%s.json HTTP/1.0\n", ZIPCODE);
    fprintf(f, "Host: api.wunderground.com\n");
    fprintf(f, "\n");
    
    // Reading JSON file
    const char *fields[] = {"observation_time\":", "full", "temp_f", "relative_humidity", "wind_dir", "wind_mph" };
    int j = 0;
    char line[1000];
    char data[7][100]; // Store incoming data into 2D array
    
    // Forecast variables
    char *weekd = "weekday\":\"";
    char *fahr = "fahrenheit\":\"";
    
    char days[5][100];
    char high[5][100];
    char low[5][100];
    
    int flag = 0;
    int d = 0;
    int h = 0;
    int l = 0;
    
    while (fgets(line, 1000, f) != NULL)
    {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';
            
        for (int i = 0; i < 6; i++)
        {
            char *p = strstr(line, fields[i]);
            
            if (p)
            {
                p = cleanup(p);
                strcpy(data[j], p);
                j++;
                break;
            }
        }
        // Gather forecast data
        char *f = strstr(line, weekd);
        if (f)
        {
            f = cleanup(f);
            strcpy(days[d], f);
            d++;
        }
        
        char *foo = strstr(line, fahr);
        if(foo)
        {
            foo = cleanup(foo);
            if (flag == 0)
            {
                strcpy(high[h], foo);
                flag = 1;
                h++;
            }
            else
            {
                strcpy(low[l], foo);
                flag = 0;
                l++;
            }
        }
        //printf("%s", line); // Read the JSON file in terminal
    }
    
    // Data complete, clean it up
    char *obs = data[2];
    char *city = data[0];
    char *temp = data[3];
    char *humid = data[4];
    char *winddir = data[5];
    char *windmph = data[6];
    
    int ret = strncmp(obs, "ERROR", 10);
    
    if (ret == 0)
        printf("Unable to process request at this time, please try again in a moment.\n");
    else
    {
        printf("Current Conditions\n");
        printf("Observation Time: %s\n", obs);
        printf("Location: %s\n", city);
        printf("Temperature: %s F\n", temp);
        printf("Humidity: %s\n", humid);
        printf("Wind: %s %s mph\n", winddir, windmph);
        
        printf("\n");
        printf("Forecast\n");
        for (int i = 0; i < 4; i ++)
        {
            printf("%s: %s %s\n", days[i], high[i], low[i]);
        }
    }

    fclose(f);
    destroy_inet_socket(fd);
}

char *cleanup(char *s)
{
    char *final;
    final = (char*)calloc(50, sizeof(char));    
    
    int index = 0;
    int j = 0;
    
    for(int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ':')
        {
            index = i;
            break;
        }
    }
    
    if (s[strlen(s)-2] == '"')
    {
        s[strlen(s)-2] = '\0';
        for(int i = index+1; i < strlen(s); i++)
        {
            if(s[i] == '"')
                i += 1;
            
            final[j] = s[i];
            j++;
        }
    }
    else if (s[strlen(s)-1] == ',')
    {
        s[strlen(s)-1] = '\0';
        for(int i = index+1; i < strlen(s); i++)
        {
            final[j] = s[i];
            j++;               
        }
    }
    else
        final = "ERROR";
        
    return final;
}