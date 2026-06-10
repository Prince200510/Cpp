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

void display(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        while(size--) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";
            
            if(current->left) {
                q.push(current->left);
            }

            if(current->right) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;

        Node* root = NULL;
        root = insert(root, data);

        display(root);
    }
}