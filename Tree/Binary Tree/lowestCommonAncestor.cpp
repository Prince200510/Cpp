#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

Node* ancestor(Node* root, Node* p, Node* q) {
    if(root == NULL) {
        return NULL;
    }

    if(root == p || root == q) {
        return root;
    }

    Node* left = ancestor(root->left, p, q);
    Node* right = ancestor(root->right, p, q);

    if(left && right) {
        return root;
    }

    return left ? left : right;
}

int main() {
    int n;
    cin >> n;

    map<int, Node*> mp;
    set<int> child;

    for(int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;

        if(mp.find(p) == mp.end()) {
            mp[p] = new Node(p);
        }

        if(mp.find(c) == mp.end()) {
            mp[c] = new Node(c);
        }

        if(mp[p]->left == NULL) {
            mp[p]->left = mp[c];
        } else {
            mp[p]->right = mp[c];
        }
        child.insert(c);
    }

    Node* root = NULL;

    for(auto x : mp) {
        if(child.find(x.first) == child.end()) {
            root = x.second;
            break;
        }
    }

    cout << ancestor(root, mp[5], mp[1])->data << endl;
}