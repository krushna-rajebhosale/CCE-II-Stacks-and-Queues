#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert node at the end
    void insert(int val) {
        Node* p = new Node(val); // p is used for new node
        if (head == nullptr) {
            head = p;
        } else {
            Node* q = head; // q is used for traversal
            while (q->next != nullptr) {
                q = q->next;
            }
            q->next = p;
            p->prev = q;
        }
    }

    // Delete node by value
    void remove(int val) {
        Node *p,*q;
               q = head;

                if (q->data == val) {
                p = head;
                head=head->next;
                head->prev=nullptr;
                delete p;
                return;
                }
                
                while (q->next != NULL) {
            if (q->next->data == val) {
                p = q->next;
                q->next = p->next;
                p->next->prev=q;
                delete p;
                return;
            }
            q = q->next;
        }
       
  

        cout << "Value " << val << " not found in the list.\n";
    }

    // Display list forward
    void displayForward() {
        Node* q = head;
        cout << "Forward: ";
        while (q != nullptr) {
            cout << q->data << " <-> ";
            q = q->next;
        }
        cout << "NULL\n";
    }

    // Display list backward
    void displayBackward() {
        Node* q = head;
        if (q == nullptr) {
            cout << "Backward: NULL\n";
            return;
        }

        // Move to the tail
        while (q->next != nullptr) {
            q = q->next;
        }

        cout << "Backward: ";
        while (q != nullptr) {
            cout << q->data << " <-> ";
            q = q->prev;
        }
        cout << "NULL\n";
    }
};

// Main function to test the doubly linked list
int main() {
    DoublyLinkedList list;

    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.displayForward();   
    list.displayBackward(); 

    list.remove(10);
    list.displayForward();   
    list.displayBackward();  

    return 0;
}

//OUTPUT:
// PS C:\Users\student\Desktop\Rajebhosale_krushna> cd "
// c:\Users\student\Desktop\Rajebhosale_krushna\" ; 
// if ($?) { g++ Doubly_link_list.cpp -o Doubly_link_list } ; 
// if ($?) { .\Doubly_link_list }
// Forward: 5 <-> 10 <-> 15 <-> NULL
// Backward: 15 <-> 10 <-> 5 <-> NULL
// Forward: 5 <-> 15 <-> NULL
// Backward: 15 <-> 5 <-> NULL