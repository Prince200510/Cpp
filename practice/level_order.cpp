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

Node* build_tree(vector<int>& arr, int i) {
    if(i >= arr.size() || arr[i] == -1) {
        return NULL;
    }

    Node* root = new Node(arr[i]);
    root->left = build_tree(arr, 2 * i + 1);
    root->right = build_tree(arr, 2 * i + 2);

    return root;
}

int level(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int max_level = 0;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        max_level = max(max_level, size);

        while(size--) {
            Node* current = q.front();
            q.pop();

            if(current->left) {
                q.push(current->left);
            }

            if(current->right) {
                q.push(current->right);
            }
        }
    }
    return max_level;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }   

    Node* root = build_tree(arr, 0);
    cout << "Maximum nodes at any level: " << level(root) << endl;
}