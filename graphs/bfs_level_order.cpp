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

void level_order(Node* root) {
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
 
            if(current->left)
                q.push(current->left);
            if(current->right)
                q.push(current->right);
        }
        cout << endl; 
    }
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

    vector<Node*> roots;

    for(auto x : mp) {
        if(child.find(x.first) == child.end()) {
            roots.push_back(x.second);
        }
    }

    for(Node* root : roots) {
        level_order(root);
    }
}


// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };


// Node* buildTree() {

//     int rootValue;
//     cin >> rootValue;

//     if(rootValue == -1)
//         return NULL;


//     Node* root = new Node(rootValue);

//     queue<Node*> q;
//     q.push(root);


//     while(!q.empty()) {

//         Node* current = q.front();
//         q.pop();


//         int leftValue, rightValue;

//         cin >> leftValue >> rightValue;


//         // left child
//         if(leftValue != -1) {

//             current->left = new Node(leftValue);
//             q.push(current->left);
//         }


//         // right child
//         if(rightValue != -1) {

//             current->right = new Node(rightValue);
//             q.push(current->right);
//         }
//     }


//     return root;
// }


// void levelOrder(Node* root) {

//     if(root == NULL)
//         return;


//     queue<Node*> q;
//     q.push(root);


//     while(!q.empty()) {

//         int size = q.size();


//         while(size--) {

//             Node* curr = q.front();
//             q.pop();

//             cout << curr->data << " ";


//             if(curr->left)
//                 q.push(curr->left);


//             if(curr->right)
//                 q.push(curr->right);
//         }

//         cout << endl;
//     }
// }


// int main() {

//     Node* root = buildTree();


//     cout << "Level Order:\n";

//     levelOrder(root);


//     return 0;
// }

// input:
// 1
// 2 3
// 4 5
// -1 6
// -1 -1
// -1 -1

// Tree Created:
    //     1
    //    / \
    //   2   3
    //  / \   \
    // 4   5   6