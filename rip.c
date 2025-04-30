#include <unistd.h>
#include <stdlib.h>

void    ft_putstr(char *s) {
    while (*s)
        write(1, s++, 1);
}

/* Validate if parentheses are balanced */
int is_valid(char *s) {
    int balance = 0;
    while (*s) {
        if (*s == '(') balance++;
        else if (*s == ')') {
            balance--;
            if (balance < 0) return 0; // Excess ')'
        }
        s++;
    }
    return balance == 0;
}

/* Backtracking function to generate all solutions */
void    backtrack(char *s, int index, int open_to_remove, int close_to_remove) {
    // Base case: If the string is valid after all removals, print it.
    if (open_to_remove == 0 && close_to_remove == 0 && is_valid(s)) {
        ft_putstr(s);
        write(1, "\n", 1);
        return;
    }
    
    // Recursively remove characters to find all solutions
    for (int i = index; s[i]; i++) {
        if ((s[i] == '(' && open_to_remove) || (s[i] == ')' && close_to_remove)) {
            char temp = s[i];
            s[i] = ' '; // Remove current '(' or ')'
            backtrack(s, i + 1, open_to_remove - (temp == '('), close_to_remove - (temp == ')'));
            s[i] = temp; // Restore for next iteration
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        ft_putstr("Usage: ./rip \"string\"\n");
        return 1;
    }
    char *s = argv[1];

    /* Step 1: Count excess '(' and ')' */
    int open_count = 0, close_count = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') open_count++;
        else if (s[i] == ')') {
            if (open_count > 0) open_count--;
            else close_count++;
        }
    }

    /* Step 2: Call recursive function to generate solutions */
    backtrack(s, 0, open_count, close_count);

    return 0;
}
