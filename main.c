#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stackconfig.h"
#include "stack.h"

void testIntStack() {
    Stack stack;
    stack.top=-1;
    print(&stack);
    push(&stack, 3);
    print(&stack);
    push(&stack, 4);
    print(&stack);
    push(&stack, 5);
    print(&stack);
    pop(&stack);
    print(&stack);
    printf("%d\n", peek(&stack));
}

void testCharStack() {
    Stack stack;
    stack.top=-1;
    print(&stack);
    push(&stack, 3 + 'a');
    print(&stack);
    push(&stack, 4 + 'a');
    print(&stack);
    push(&stack, 5 + 'a');
    print(&stack);
    pop(&stack);
    print(&stack);
    printf("%c\n", peek(&stack));
}

void problemTwoCheckPalindrome() {
    char *string = "madam";
    int length = strlen(string);

    Stack leftStack = {NULL};
    int halfLength = length/2;
    for(int i=0; i<halfLength; ++i) {
        push(&leftStack, string[i]);
    }

    Stack rightStack = {NULL};
    for(int i=0; i<halfLength; ++i) {
        push(&rightStack, string[length-i-1]);
    }
    int palindrome = 1;
    while(!isEmpty(&leftStack)) {
        char left = pop(&leftStack);
        char right = pop(&rightStack);
        if(left != right) {
            palindrome = 0;
            break;
        }
    }
    if(palindrome) {
        printf("%s is a palindrome\n", string);
    } else {
        printf("%s is not a palindrome\n", string);
    }
}

void problemThreeSort() {
    int MAX = 255;
    Stack counts[MAX];
    for(int i=0; i<MAX; ++i) {
        counts[i].top = NULL;
    }
    char *string = "bcfda";
    int length = strlen(string);
    for(int i=0; i<length; ++i) {
        int ch = string[i];
        push(&counts[ch], ch);
    }
    char sorted[length+1];
    for(int i=0, j=0; i<MAX; ++i) {
        while(!isEmpty(&counts[i])) {
            sorted[j++] = pop(&counts[i]);
        }
    }
    sorted[length] = 0;
    printf("Input: %s\n", string);
    printf("Output: %s\n", sorted);
}

int main() {
    testCharStack();

    // refer stackconfig.h to change to an int stack
    // testIntStack();
    
    problemTwoCheckPalindrome();
    problemThreeSort();
    return 0;
}
