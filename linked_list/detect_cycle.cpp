#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

Node* cycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            slow = head;

            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;
    vector<Node*> nodes;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;

        Node* newNode = new Node(val);
        nodes.push_back(newNode);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int pos;
    if(cin >> pos && pos != -1) {
        if(pos >= 1 && pos <= n) {
            tail->next = nodes[pos - 1];
        }
    }

    Node* start = cycle(head);

    if(start == NULL) {
        cout << "No cycle detected" << endl;
    } else {
        cout << "Cycle starts at node with value: " << start->data << endl;
    }
}