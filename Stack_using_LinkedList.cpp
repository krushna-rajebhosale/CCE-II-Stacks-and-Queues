
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool empty() {
        return top == nullptr;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        cout << "\nInserted: " << x;
    }

    void pop() {
        if (empty()) {
            cout << "\nStack Underflow!";
            return;
        }

        Node* temp = top;
        cout << "\nRemoved: " << temp->data;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (empty()) {
            cout << "\nStack is empty.";
            return;
        }

        cout << "\nTop element: " << top->data;
    }

    void display() {
        Node* temp = top;

        cout << "\nStack (top to bottom):";
        while (temp != nullptr) {
            cout << "\n" << temp->data;
            temp = temp->next;
        }
    }
};

int main() {
    Stack s;

    s.push(990);
    s.push(810);
    s.push(333);
    s.push(578);
    s.push(100);
    s.push(220);

    s.display();
    s.pop();
    s.display();
    s.peek();

    cout << "\n";
    return 0;
}