#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *prev;
    Node *next;

    public: 
    Node(int data) {
        this->data = data;
        this->prev = this->next = NULL;
    }
};

class DoublyLinkedList {
    Node *head;
    Node *tail;

    public: 
    DoublyLinkedList() {
        this->head = this->tail = NULL;
    }

    Node* createNode(int data) {
        return new Node(data);
    }

    public:
    void addFront(int data) {
        Node *newNode = createNode(data);
        if(head == NULL) {
            head = newNode;
            tail = head;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    public: 
    void addRear(int data) {
        Node *newNode = createNode(data);
        if(tail == NULL) {
            tail = newNode;
            head = tail;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    public: 
    void print() {
        Node *temp = head;
        while(temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    public: 
    void printReverse() {
        Node *temp = tail;
        while(temp != NULL) {
            cout << temp->data << "->";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.addFront(10);
    list.addFront(20);
    list.addRear(30);
    list.addRear(40);
    list.addFront(50);
    
    // Output
    // 50 20 10 30 40
    // 40 30 10 20 50
    list.print();

    list.printReverse();
    return 0;
}