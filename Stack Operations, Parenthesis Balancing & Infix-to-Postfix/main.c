#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return (top == -1) ? '\0' : stack[top--]; }
char peek() { return (top == -1) ? '\0' : stack[top]; }

int isMatching(char a, char b) {
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

int checkParentheses(char *exp) {
    top = -1;
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1 || !isMatching(pop(), exp[i])) return 0;
        }
    }
    return top == -1;
}

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(char *exp) {
    if (!checkParentheses(exp)) {
        printf("Error: Unbalanced Parentheses!\n"); return;
    }
    top = -1;
    char post[50]; int k = 0;
    printf("\nStep\tSymbol\tStack\t\tPostfix\n----------------------------------------\n");
    for (int i = 0; exp[i]; i++) {
        char c = exp[i];
        if (isalnum(c)) post[k++] = c;
        else if (c == '(') push(c);
        else if (c == ')') {
            while (top != -1 && peek() != '(') post[k++] = pop();
            pop();
        } else {
            while (top != -1 && (prec(peek()) > prec(c) || (prec(peek()) == prec(c) && c != '^')))
                post[k++] = pop();
            push(c);
        }
        post[k] = '\0'; stack[top + 1] = '\0';
        printf("%d\t%c\t%-10s\t%s\n", i + 1, c, stack, post);
    }
    while (top != -1) post[k++] = pop();
    post[k] = '\0';
    printf("Final Postfix Expression: %s\n", post);
}

int main() {
    char exp[50];
    printf("Enter Infix Expression: ");
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}