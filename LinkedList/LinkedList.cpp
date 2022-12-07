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

    // TC: O(N), SC: O(1)
    void remove(int data) {
        
        if(isEmpty()) return;

        Node* temp = NULL;
        if(start->data == data) {
            temp = start;
            start = start->next;
            free(temp);
            return;
        }

        Node* prev = start;
        temp = start->next;

        while(temp != NULL) {
            if(temp->data == data) {
                prev->next = temp->next;
                free(temp);
                return;
            } 
            prev = temp;
            temp = temp->next;
        }
    }

    // TC: O(N), SC: O(1)
    void reverse() {
        Node* ptr1 = start;
        Node* ptr2 = start->next;
        Node* temp = NULL;
        ptr1->next = NULL;
        while(ptr2 != NULL) {
            temp = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            if(temp == NULL)
                start = ptr2;
            ptr2 = temp;
        }
    }

    int count() {
        Node* temp = start;
        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    Node* middle() {
        Node *fast, *slow;
        fast = slow = start;

        while(true) {
            if(fast->next == NULL) break;
            if(fast->next->next == NULL) break;
            cout << slow->data << " ";
            slow = slow->next;
            cout << fast->data << " ";
            fast = fast->next->next;
        }

        if(fast->next == NULL) cout << "ODD Size" << endl;
        if(fast->next->next == NULL) cout << "EVEN Size" << endl;

        return slow;
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
    list.add(10);
    list.add(3);
    list.add(7);
    list.add(1);
    list.add(5);

    // list.remove(3);
    // list.remove(5);

    list.print(list.start);

    // list.reverse();

    list.print(list.start);

    Node* mid = list.middle();
    list.print(mid);

    return 0;
}