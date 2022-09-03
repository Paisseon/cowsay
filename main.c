#include <stdio.h>
#include <string.h>

void horizontal_border(int top, int len, int wCt) {
    printf("%s", top == 0 ? "┌" : "└");
    
    for (int i = (wCt <= 1) ? -2 : -1; i < len; ++i)
        printf("%s", "─");
    
    printf("%s\n", top == 0 ? "┐" : "┘");
}

int main(int argc, const char *argv[]) {
    int len = 0, lCt = 0, wCt = 0;
    char str[5000], *tmp[5000], line[42];
    
    if (argc == 1)
        return -1;
    
    // Concatenate all arguments into one string
    
    strcpy(str, argv[1]);
    
    for (int i = 2; i < argc; ++i) {
        strcat(str, " ");
        strcat(str, argv[i]);
    }
    
    // Get array of all words
    
    for (char *token = strtok(str, " "); token != NULL; token = strtok(NULL, " "))
        tmp[wCt++] = token;
    
    char *words[wCt];
    
    for (int i = 0; i < wCt; ++i)
        words[i] = tmp[i];
    
    // Get the box width
    
    for (int i = 0; i < wCt; ++i) {
        strcpy(line, words[i]);
        lCt++;
        
        for (int a = i + 1; a < wCt; ++a) {
            strcat(line, " ");
            strcat(line, words[a]);
            
            if (((strlen(line) + strlen(words[a])) > len) && ((strlen(line) + strlen(words[a]) + 3) <= 42)) {
                len = (strlen(line) + 1);
                i++;
            } else {
                break;
            }
        }
    }
    
    len = (len != strlen(argv[1]) && len < 5) ? strlen(argv[1]) : len;
    
    // Display the top row
    
    horizontal_border(0, len, wCt);
    
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
        
        for (int n = 0; wCt > 1 && n < (len - strlen(line) - 1); ++n)
            printf("%s", " ");
        
        printf("%s", " │\n");
    }
    
    // Display the bottom row
    
    horizontal_border(1, len, wCt);
    
    // Display the cow
    
    printf("%s\n", "\
      \\   ,__,\n\
       \\  (oo)____\n\
          (__)    )\\\n\
             ||--|| *");
    
    return 0;
}