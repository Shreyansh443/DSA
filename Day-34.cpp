#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Top of stack
struct Node* top = NULL;

// Push operation
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int popped = temp->data;
    top = top->next;
    free(temp);
    return popped;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    int i = 0;

    while (exp[i] != '\0') {
        
        // If operand (digit)
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }

        // If operator
        else if (exp[i] == '+' || exp[i] == '-' || 
                 exp[i] == '*' || exp[i] == '/') {

            int val2 = pop();
            int val1 = pop();

            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }

        i++;
    }

    return pop();
}

// Main function
int main() {
    char exp[] = "231*+9-"; // spaces removed
    printf("Result = %d\n", evaluatePostfix(exp));
    return 0;
}