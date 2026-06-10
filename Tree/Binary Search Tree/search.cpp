#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool search(Node* root, int target) {
    if(root == NULL) {
        return false;
    }

    if(root->data == target) {
        return true;
    }

    if(target < root->data) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

Node* insert(Node* root, int data) {
    if(root == NULL) {
        return new Node(data);
    }

    if(data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

int main() {
    int n;
    cin >> n;
    
    Node* root = NULL;
    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;

        root = insert(root, data);
    }
    
    int target;
    cin >> target;

    if(search(root, target)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }
}