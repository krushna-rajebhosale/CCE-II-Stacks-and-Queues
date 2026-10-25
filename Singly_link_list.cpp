// Program for Linked List Operations
#include <iostream>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    // Constructor for Node
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Linked List operations
class LinkedList {
private:
    Node* head;

public:
    // Constructor for Linked List
    LinkedList() {
        head = NULL;
    }

    // Insert a node at the end
    void insert(int val) {
        Node* p = new Node(val);

        if (head == NULL) {
            head = p;
        }
        else {
            Node* q = head;

            while (q->next != NULL) {
                q = q->next;
            }

            q->next = p;
        }
    }

    // Delete a node by value
    void remove(int val) {

        // If the list is empty
        if (head == NULL) {
            cout << "\nList is empty.";
            return;
        }

        // If the head node contains the value
        if (head->data == val) {
            Node* p = head;
            head = head->next;
            delete p;
            return;
        }

        // Traverse the list
        Node* q = head;

        while (q->next != NULL) {

            if (q->next->data == val) {
                Node* p = q->next;
                q->next = p->next;
                delete p;
                return;
            }

            q = q->next;
        }

        cout << "\nValue " << val << " not found in the list.";
    }

    // Display the list
    void display() {
        cout << "\nLinked List: ";

        Node* q = head;

        while (q != NULL) {
            cout << q->data << " -> ";
            q = q->next;
        }

        cout << "NULL\n";
    }
};

// Main function
int main() {

    LinkedList list;

    // Insert values
    list.insert(5);
    list.insert(15);
    list.insert(25);

    list.display();

    list.insert(35);
    list.insert(45);
    list.insert(55);

    list.display();

    // Delete 35
    list.remove(35);
    list.display();

    // Delete 55
    list.remove(55);
    list.display();

    // Try to delete a value that does not exist
    list.remove(100);
    list.display();

    return 0;
}

OUTPUT:
// PS C:\Users\student\Desktop\Rajebhosale_krushna> cd "
// c:\Users\student\Desktop\Rajebhosale_krushna\" ; 
// if ($?) { g++ Singly_link_list.cpp -o Singly_link_list } ;
//  if ($?) { .\Singly_link_list }

// Linked List: 5 -> 15 -> 25 -> NULL

// Linked List: 5 -> 15 -> 25 -> 35 -> 45 -> 55 -> NULL

// Linked List: 5 -> 15 -> 25 -> 45 -> 55 -> NULL

// Linked List: 5 -> 15 -> 25 -> 45 -> NULL

// Value 100 not found in the list.
// Linked List: 5 -> 15 -> 25 -> 45 -> NULL