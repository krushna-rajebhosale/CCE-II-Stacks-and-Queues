
#include <iostream>
using namespace std;

const int MAX = 5;

class Stack {
private:
    int a[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool empty() {
        return top == -1;
    }

    bool full() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (full()) {
            cout << "\nStack Overflow!";
            return;
        }

        a[++top] = x;
        cout << "\nInserted: " << x;
    }

    void pop() {
        if (empty()) {
            cout << "\nStack Underflow!";
            return;
        }

        cout << "\nRemoved: " << a[top--];
    }

    void peek() {
        if (empty()) {
            cout << "\nStack is empty.";
            return;
        }

        cout << "\nTop element: " << a[top];
    }

    void display() {
        if (empty()) {
            cout << "\nStack is empty.";
            return;
        }

        cout << "\nStack (top to bottom):";
        for (int i = top; i >= 0; i--) {
            cout << "\n" << a[i];
        }
    }
};

int main() {
    Stack s;

    s.push(12);
    s.push(34);
    s.push(56);
    s.push(87);
    s.push(92);
    s.push(99);

    s.display();
    s.pop();
    s.display();
    s.peek();

    cout << "\n";
    return 0;
}
