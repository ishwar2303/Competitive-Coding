#include <iostream>
#include <stack>
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
    list.add(3);
    list.add(1);
    list.add(7);
    list.add(8);
    list.add(9);
    list.add(9);

    return 0;
}