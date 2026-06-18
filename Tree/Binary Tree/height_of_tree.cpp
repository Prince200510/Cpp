#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
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
    for(auto it : mp) {
        if(child.find(it.first) == child.end()) {
            root = it.second;
            break;
        }
    }

    cout << height(root) << endl;
    cout << "Edges : " << height(root) - 1 << endl; 
}