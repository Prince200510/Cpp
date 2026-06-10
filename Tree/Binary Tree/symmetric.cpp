#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int data) {
        data = data;
        left = nullptr;
        right = nullptr;
    }
};

bool mirror(Node* left, Node* right) {
    if(left == NULL && right == NULL) {
        return true;
    }

    if(left == NULL || right == NULL) {
        return false;
    }

    return (left->data == right->data) && mirror(left->left, right->right) && mirror(left->right, right->left);
}

bool symmetric(Node* root) {
    if(root == NULL) {
        return false;
    }

    return mirror(root->left, root->right);
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

    cout << symmetric(root) << endl;
}