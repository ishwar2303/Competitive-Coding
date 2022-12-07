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

    string addOne() {
        stack<int> s;
        Node* temp = start;
        while(temp != NULL) {
            s.push(temp->data);
            temp = temp->next;
        }

        int carry = 0;
        int one = 1;
        string output;
        while(!s.empty()) {
            int sum = s.top() + carry + one;
            if(sum == 10) {
                carry = 1;
                output = to_string(0) + output;
            }
            else {
                carry = 0;
                output = to_string(sum) + output;
            }
            
            if(one) one = 0;

            s.pop();
        }
        if(carry == 1)
            output = to_string(1) + output;

        return output;
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

    list.print(list.start);
    string ans = list.addOne();
    cout << ans << endl;
    return 0;
}