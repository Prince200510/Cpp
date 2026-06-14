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

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        Node* newNode = new Node(val);

        // insert at beginning
        // newNode->next = head;
        // head = newNode;

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}