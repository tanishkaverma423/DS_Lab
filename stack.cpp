#include <bits/stdc++.h>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack overflow\n";
        } else {
            arr[++top] = x; // FIXED: actually assign x to arr[top]
            cout << x << " pushed into stack\n";
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack underflow\n";
        } else {
            cout << arr[top--] << " popped out from the stack\n"; // FIXED: added space and newline
        }
    }

    int peek() {
        if (top < 0) {
            cout << "Stack underflow\n";
            return -1;
        } else {
            return arr[top];
        }
    }

    void display() {
        if (top < 0) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top element is " << s.peek() << endl;
    s.pop();
    s.display();
    return 0;
}
