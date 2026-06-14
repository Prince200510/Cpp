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

Node* insert(vector<int>& arr, int left, int right) {
    if(left > right) {
        return NULL;
    }

    int mid = left + (right - left) / 2;
    Node * root = new Node(arr[mid]);

    root->left = insert(arr, left, mid - 1);
    root->right = insert(arr, mid + 1, right);

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

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = insert(arr, 0, n - 1);
    display(root);
}