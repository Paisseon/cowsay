#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[]) {
    int len, wCt = 0;
    char str[1000], *tmp[1000], line[42];
    
    if (argc == 1)
        return -1;
    
    // Concatenate all arguments into one string
    
    strcpy(str, argv[1]);
    
    for (int i = 2; i < argc; ++i) {
        strcat(str, " ");
        strcat(str, argv[i]);
    }
    
    // Get array of all words
    
    for (char *token = strtok(str, " "); token != NULL; token = strtok(NULL, " ")) {
        tmp[wCt] = token;
        wCt++;
    }
    
    char *words[wCt];
    
    for (int i = 0; i < wCt; ++i) {
        words[i] = tmp[i];
    }
    
    // Get the box width
    
    for (int i = 0; i < wCt; ++i) {
        strcpy(line, words[i]);
        
        for (int a = i + 1; a < wCt; ++a) {
            strcat(line, " ");
            strcat(line, words[a]);
            
            if ((strlen(line) + strlen(words[a])) > len && (strlen(line) + strlen(words[a])) < 42) {
                len = (strlen(line) + strlen(words[a]));
                i++;
            } else {
                break;
            }
        }
    }
    
    len = (len != strlen(argv[1]) && len < 5) ? strlen(argv[1]) : len;
    
    // Display the top row
    
    printf("%s", "┌");
    for (int i = -2; i < len; ++i) {
        printf("%s", "─");
    }
    printf("%s\n", "┐");
    
    // Display the input message
    
    for (int i = 0; i < wCt; ++i) {
        strcpy(line, words[i]);
        
        for (int a = i + 1; a < wCt; ++a) {
            if ((strlen(line) + strlen(words[a]) + 1) < len) {
                strcat(line, " ");
                strcat(line, words[a]);
                i++;
            } else {
                break;
            }
        }
        
        printf("│ %s", line);
        for (int n = 0; n < (len - strlen(line)); ++n) {
            printf("%s", " ");
        }
        printf("%s", " │\n");
    }
    
    // Display the bottom row
    
    printf("%s", "└");
    for (int i = -2; i < len; ++i) {
        printf("%s", "─");
    }
    printf("%s\n", "┘");
    
    // Display the cow
    
    printf("%s\n", "\
      \\   ,__,\n\
       \\  (oo)____\n\
          (__)    )\\\n\
             ||--|| *");
    
    return 0;
}