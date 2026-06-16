#include <bits/stdc++.h>
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

vector<int> left_view(Node* root) {
    vector<int> ans;

    if(root == NULL) {
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();

        for(int i = 0; i < n; i++) {
            Node* current = q.front();
            q.pop();
            
            if(i == 0) {
                ans.push_back(current->data);
            }

            if(current->left) {
                q.push(current->left);
            }
            if(current->right) {
                q.push(current->right);
            }
        }
    }
    return ans;
}

vector<int> right_view(Node* root) {
    vector<int> ans;

    if(root == NULL) {
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();

        for(int i = 0; i < n; i++) {
            Node* current = q.front();
            q.pop();
            
            if(i == n - 1) {
                ans.push_back(current->data);
            }

            if(current->left) {
                q.push(current->left);
            }
            if(current->right) {
                q.push(current->right);
            }
        }
    }
    return ans;
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

    vector<int> l = left_view(root);
    vector<int> r = right_view(root);

    cout << "Left View: ";
    for(int x : l) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Right View: ";
    for(int x : r) {
        cout << x << " ";
    }
    cout << endl;
}