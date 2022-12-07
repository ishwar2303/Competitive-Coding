#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


class List {
    public:
    Node* start;

    public:
    List() {
        start = NULL;
    }

    bool isEmpty() {
        return start == NULL ? true : false;
    }

    // TC: O(N), SC: O(1)
    void add(int data) {
        Node* newNode = new Node(data);
        if(start == NULL) {
            start = newNode;
            return;
        }
        
        Node* temp = start;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;

    }

    void removeDuplicate() {
        Node *prev = start;
        Node *temp = start->next;
        Node* removeNode = NULL, *nextNode = NULL;

        while(temp != NULL) {
            removeNode = NULL;

            // duplicate node
            if(temp->data == prev->data) {
                removeNode = temp;
            }
            else {
                // not duplicate node
                prev = temp;
            }

            nextNode = temp->next;

            if(removeNode != NULL)  {

                // connect previous node with duplicate next node
                prev->next = nextNode;

                // delete duplicate node
                free(removeNode);
            }
            temp = nextNode;
        }
    }

    void print(Node* from) {
        Node* temp = from;
        while(temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {

    List list;
    list.add(1);
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(3);
    list.add(4);
    list.add(4);
    list.add(4);
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(7);

    list.print(list.start);
    list.removeDuplicate();
    list.print(list.start);
    return 0;
}