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

bool search(Node* root, int key) {
    if(root == NULL) {
        return false;
    }

    if(root->data == key) {
        return true;
    }

    return search(root->left, key) || search(root->right, key);
}

int main() {
    map<int, Node*> mp;
    set<int> child;

    int n;
    cin >> n;

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

    int key = 40;
    
    if(search(root, key)) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }
}