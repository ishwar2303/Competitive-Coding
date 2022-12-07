#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *right, *down;

    public:
    Node(int data) {
        this->data = data;
        this->right = this->down = NULL;
    }
};

class LinkedList {
    public:
    Node *start;

    public:
    LinkedList() {
        this->start = NULL;
    }

    public:
    void insert(int data, string direction) {
        Node *newNode = new Node(data);
        if(start == NULL) {
            start = newNode;
        }
        else {
            Node* temp = start;
            if(direction == "RIGHT") {
                while(temp->right != NULL) {
                    temp = temp->right;
                }
                temp->right = newNode;
            }
            else if(direction == "DOWN") {
                while(temp->right != NULL) {
                    temp = temp->right;
                }
                while(temp->down != NULL) {
                    temp = temp->down;
                }
                temp->down = newNode;
            }
        }
    }

    void print() {
        Node* temp = start;
        while(temp != NULL) {
            Node* tempDown = temp;
            while(tempDown != NULL) {
                cout << tempDown->data << "->";
                tempDown = tempDown->down;
            }
            cout << endl;
            cout << "|" << endl;
            cout << "V" << endl;
            temp = temp->right;
        }
        cout << endl;
    }

    // convert the list to one directional sorted list
    void flatten() {
        Node *temp = NULL;
        while(true) {
            Node *tempRight = start;
            temp = start;
            // stop at the node where there is a vertical list
            while(tempRight != NULL) {
                if(tempRight->down == NULL)
                    tempRight = tempRight->right;
                else break;
            }
            
            // no vertical list left to be flatten
            if(tempRight == NULL)
                break;

            Node *tempDown = tempRight->down;
            tempRight->down = NULL;

            Node* prevRight = NULL;
            Node* nextDown = NULL;

            // traverse the vertical list
            // place vertical list item to their correct position in horizontal list
            while(tempDown != NULL && temp != NULL) {

                // placing vertical item to its correct position
                if(temp->data > tempDown->data) {
                    nextDown = tempDown->down;

                    // make vertical node start node
                    if(prevRight == NULL) {
                        start = tempDown;
                    }
                    else {
                        prevRight->right = tempDown;
                    }
                    tempDown->down = NULL;
                    tempDown->right = temp;
                    temp = tempDown;
                    tempDown = nextDown;
                }
                prevRight = temp;
                temp = temp->right;
            }

            if(tempDown == NULL) continue;

            // place down list at the end of horizontal list
            if(temp == NULL) {
                prevRight->right = tempDown;

                while(tempDown != NULL) {
                    tempDown->right = tempDown->down;
                    tempDown->down = NULL;
                    tempDown = tempDown->right;
                }
            }

        }
    }

};

int main() {
    LinkedList list;
    list.insert(3, "RIGHT");
    list.insert(9, "DOWN");
    list.insert(17, "DOWN");
    list.insert(10, "RIGHT");
    list.insert(47, "DOWN");
    list.insert(50, "DOWN");
    list.insert(15, "RIGHT");
    list.insert(19, "DOWN");
    list.insert(30, "DOWN");
    list.insert(28, "RIGHT");
    list.insert(49, "DOWN");

    cout << "Original Linked List" << endl;
    list.print();

    list.flatten();

    cout << "Flattened Linked List" << endl;
    list.print();

    return 0;
}