#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure for operators and operands
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Stack structure for postfix evaluation
typedef struct {
    int top;
    int items[MAX];
} IntStack;

// Function prototypes
void push(Stack *s, char item);
char pop(Stack *s);
char peek(Stack *s);
int isEmpty(Stack *s);
int precedence(char op);
int isOperator(char ch);
void infixToPostfix(char infix[], char postfix[]);
int evaluatePostfix(char postfix[]);
void pushInt(IntStack *s, int item);
int popInt(IntStack *s);
void displayMenu();
void programDescription();
void evaluateExpressions();

int main() {
    char choice;
    
    do {
        displayMenu();
        printf("Choice: ");
        scanf(" %c", &choice);
        choice = toupper(choice);
        
        switch (choice) {
            case 'P':
                programDescription();
                break;
            case 'E':
                evaluateExpressions();
                break;
            case 'X':
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter P, E, or X.\n");
        }
    } while (1);

    return 0;
}

// Display main menu
void displayMenu() {
    printf("\nWelcome to this Expression Evaluator program!\n");
    printf("Please choose an action to perform…\n");
    printf("     [P] Program Description\n");
    printf("     [E] Evaluate Expression(s)\n");
    printf("     [X] Exit\n");
}

// Program description
void programDescription() {
    printf("\n--- Program Description ---\n");
    printf("Developers: Kyle Senoy (2023-096686) a nd Justin Veloso(SN)\n");
    printf("Date Developed: 02/10/2025\n");
    printf("This program converts an infix expression to postfix notation and evaluates it.\n");
    printf("Valid operators: +, -, *, /, and %.\n");
    printf("Parentheses () are supported.\n");
    printf("Spaces are optional.\n");
    printf("Return to the main menu...\n");
}

// Evaluate expressions
void evaluateExpressions() {
    char infix[MAX], postfix[MAX];
    
    while (1) {
        printf("\nEnter an infix expression (or type 'exit' to go back): ");
        scanf(" %[^\n]", infix);

        if (strcmp(infix, "exit") == 0) {
            printf("Returning to main menu...\n");
            break;
        }

        infixToPostfix(infix, postfix);
        printf("Postfix Expression: %s\n", postfix);
        printf("Evaluation Result: %d\n", evaluatePostfix(postfix));
    }
}

// Stack operations for characters
void push(Stack *s, char item) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++(s->top)] = item;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    return s->items[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

// Operator precedence
int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
        default: return 0;
    }
}

// Check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    s.top = -1;
    int i = 0, j = 0;
    char ch, temp;

    while ((ch = infix[i++]) != '\0') {
        if (isdigit(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '('
        } else if (isOperator(ch)) {
            postfix[j++] = ' '; // Space as delimiter
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

// Stack operations for integer evaluation
void pushInt(IntStack *s, int item) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++(s->top)] = item;
}

int popInt(IntStack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return 0;
    }
    return s->items[(s->top)--];
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    IntStack s;
    s.top = -1;
    int i = 0, num;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            num = ch - '0';
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i++] - '0');
            }
            pushInt(&s, num);
        } else if (isOperator(ch)) {
            int b = popInt(&s);
            int a = popInt(&s);
            switch (ch) {
                case '+': pushInt(&s, a + b); break;
                case '-': pushInt(&s, a - b); break;
                case '*': pushInt(&s, a * b); break;
                case '/': pushInt(&s, b != 0 ? a / b : 0); break;
                case '%': pushInt(&s, b != 0 ? a % b : 0); break;
            }
        }
    }
    return popInt(&s);
}
