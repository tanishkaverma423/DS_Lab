#include <stdio.h>
#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Push operation
void push(struct Stack *s, int x) {
    if (s->top >= MAX - 1) {
        printf("Stack overflow\n");
    } else {
        s->arr[++(s->top)] = x;
        printf("%d pushed into stack\n", x);
    }
}

// Pop operation
void pop(struct Stack *s) {
    if (s->top < 0) {
        printf("Stack underflow\n");
    } else {
        printf("%d popped out from the stack\n", s->arr[s->top--]);
    }
}

// Peek operation
int peek(struct Stack *s) {
    if (s->top < 0) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return s->arr[s->top];
    }
}

// Display all elements
void display(struct Stack *s) {
    if (s->top < 0) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    printf("Top element is %d\n", peek(&s));

    pop(&s);
    display(&s);

    return 0;
}
