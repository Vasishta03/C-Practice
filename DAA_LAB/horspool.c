#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASCII_SIZE 128
void create_shift_table(const char *pattern, int *table, int pattern_len) {
    for(int i = 0; i < ASCII_SIZE; i++) {
        table[i] = pattern_len;
    }
    for(int j = 0; j < pattern_len - 1; j++) {
        table[(int)pattern[j]] = pattern_len - 1 - j;
    }
}
int horspool_search(const char *text, const char *pattern, int *table) {
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    if(pattern_len == 0) return -1;
    if(text_len < pattern_len) return -1;
    
    int i = pattern_len - 1; 
    while(i < text_len) {
        int k = 0; 
        
        // Right-to-left comparison
        while(k < pattern_len && 
              pattern[pattern_len - 1 - k] == text[i - k]) {
            k++;
        }
        
        if(k == pattern_len) {
            return i - pattern_len + 1; 
        } else {
            i += table[(int)text[i]];
        }
    }
    
    return -1; // No match found
}

int main() {
    char text[1024];
    char pattern[256];
    int *shift_table = malloc(ASCII_SIZE * sizeof(int));
    
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 
    
    printf("Enter pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';
    
    int pattern_len = strlen(pattern);
    create_shift_table(pattern, shift_table, pattern_len);
    
    int position = horspool_search(text, pattern, shift_table);
    
    if(position != -1) {
        printf("Pattern found at position: %d\n", position);
    } else {
        printf("Pattern not found in text.\n");
    }
    
    free(shift_table);
    return 0;
}
