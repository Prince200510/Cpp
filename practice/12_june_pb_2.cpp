#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

Node* create_list(vector<int> arr) {
    Node* head = NULL;
    Node* tail = NULL;

    for(int val : arr) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
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
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    vector<int> arr;
    Node* current = head;

    while(current) {
        arr.push_back(current->data);
        current = current->next;
    }

    vector<int> ans;

    for(int x : arr) {
        if(find(ans.begin(), ans.end(), x) == ans.end()) {
            ans.push_back(x);
        }
    }

    reverse(ans.begin(), ans.end());

    Node* newHead = create_list(ans);

    while(newHead) {
        cout << newHead->data << " ";
        newHead = newHead->next;
    }
}