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

// Case 1: Node is a Leaf (No Children)
Node* delete_case1(Node* root) {
    if(root->left == NULL && root->right == NULL) {
        delete root;
        return NULL;
    }

    return root;
}

// Case 2: Node Has One Child
// Only Left Child
Node* delete_case2_left(Node* root) {
    if(root->left != NULL && root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    return root;
}

// Only Right Child
Node* delete_case2_right(Node* root) {
    if(root->left == NULL && root->right != NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    return root;
}

// Case 3: Two children
// complete delete function
Node* min_value(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }

    return root;
}

Node* delete_case3(Node* root, int key) {
    if(root == NULL) {
        return NULL;
    }

    if(key < root->data) {
        root->left = delete_case3(root->left, key);
    } else if(key > root->data) {
        root->right = delete_case3(root->right, key);
    } else {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = min_value(root->right);
        root->data = temp->data;
        root->right = delete_case3(root->right, temp->data);
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
    }
    cout << endl;
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

    int key;
    cin >> key;
    
    cout << "Before Deletion :" << endl;
    display(root);

    root = delete_case3(root, key);
    
    cout << "After Deletion :" << endl;
    display(root);
}