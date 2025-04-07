#include <stdio.h>
#include <string.h>

int check_pattern(const char *text, const char *pattern) {
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    if (text_len != pattern_len) return 0;
    for (int i = 0; i < text_len; i++) {
        int rule = i % 3;
        char t_char = text[i];
        char p_char = pattern[i];
        
        if (rule == 0) {         // Pattern LESS
            if (p_char >= t_char) return 0;
        } 
        else if (rule == 1) {    // Pattern EQUAL
            if (p_char != t_char) return 0;
        } 
        else {                   // Pattern GREATER
            if (p_char <= t_char) return 0;
        }
    }
    return 1;
}

int main() {
    char text[256];
    char pattern[256];
    
    printf("Enter text string: ");
    scanf("%255s", text);
    printf("Enter pattern string: ");
    scanf("%255s", pattern);
    
    if (check_pattern(text, pattern)) {
        printf("Pattern matches the rules!\n");
    } else {
        printf("Pattern does NOT match the rules.\n");
    }
    
    return 0;
}
