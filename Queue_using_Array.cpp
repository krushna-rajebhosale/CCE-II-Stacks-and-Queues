
#include <iostream>
using namespace std;

const int MAX = 5;

class Queue {
private:
    int a[MAX];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool empty() {
        return front == -1;
    }

    bool full() {
        return rear == MAX - 1;
    }

    void enqueue(int x) {
        if (full()) {
            cout << "\nQueue Overflow!";
            return;
        }

        if (empty()) {
            front = 0;
        }

        a[++rear] = x;
        cout << "\nInserted: " << x;
    }

    void dequeue() {
        if (empty()) {
            cout << "\nQueue Underflow!";
            return;
        }

        cout << "\nRemoved: " << a[front++];

        if (front > rear) {
            front = rear = -1;
        }
    }

    void peek() {
        if (empty()) {
            cout << "\nQueue is empty.";
            return;
        }

        cout << "\nFront element: " << a[front];
    }

    void display() {
        if (empty()) {
            cout << "\nQueue is empty.";
            return;
        }

        cout << "\nQueue (front to rear):";
        for (int i = front; i <= rear; i++) {
            cout << " " << a[i];
        }
    }
};

int main() {
    Queue q;

    q.enqueue(25);
    q.enqueue(57);
    q.enqueue(35);
    q.enqueue(82);
    q.enqueue(99);
    q.enqueue(100);

    q.display();
    q.dequeue();
    q.display();
    q.peek();

    cout << "\n";
    return 0;
}
