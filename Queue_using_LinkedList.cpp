
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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    bool empty() {
        return front == nullptr;
    }

    void enqueue(int x) {
        Node* temp = new Node(x);

        if (empty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }

        cout << "\nInserted: " << x;
    }

    void dequeue() {
        if (empty()) {
            cout << "\nQueue Underflow!";
            return;
        }

        Node* temp = front;
        cout << "\nRemoved: " << temp->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    void peek() {
        if (empty()) {
            cout << "\nQueue is empty.";
            return;
        }

        cout << "\nFront element: " << front->data;
    }

    void display() {
        Node* temp = front;

        if (empty()) {
            cout << "\nQueue is empty.";
            return;
        }

        cout << "\nQueue (front to rear):";
        while (temp != nullptr) {
            cout << " " << temp->data;
            temp = temp->next;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(27);
    q.enqueue(34);
    q.enqueue(42);
    q.enqueue(58);
    q.enqueue(65);
    q.enqueue(70);

    q.display();
    q.dequeue();
    q.display();
    q.peek();

    cout << "\n";
    return 0;
}
