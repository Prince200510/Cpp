#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

int middle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        if(slow == NULL) {
            slow = head;
            fast = head;
        } else {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    return slow->data;
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        Node* newNode = new Node(val);

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    cout << middle(head) << endl;
}