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

Node* minimum(Node* root) {
    if(root == NULL) {
        return NULL;
    }

    while(root->left) {
        root = root->left;
    }

    return root;
}

Node* maximum(Node* root) {
    if(root == NULL) {
        return NULL;
    }

    while(root->right) {
        root = root->right;
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

    cout << "Minimum: " << minimum(root)->data << endl;
    cout << "Maximum: " << maximum(root)->data << endl;
}