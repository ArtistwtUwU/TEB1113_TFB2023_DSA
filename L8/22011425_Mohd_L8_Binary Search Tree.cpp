/** Name: Mohd Adrian Firdaus bin Mohd Rosli
Student ID: 22011425 **/

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }
    
    void insert(int value) {
        root = insert_recursive(root, value);
    }

    void search(int key) {
        bool found = search_recursive(root, key);
        if (found) {
            cout << "Value " << key << " found in the tree." << endl;
        } else {
            cout << "Value " << key << " not found in the tree." << endl;
        }
    }

    void inorder() {
        cout << "In-order traversal: ";
        inorder_recursive(root);
        cout << endl;
    }

private:
    Node* insert_recursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insert_recursive(node->left, value);
        } else if (value > node->value) {
            node->right = insert_recursive(node->right, value);
        }
        return node;
    }

    bool search_recursive(Node* node, int key) {
        if (node == nullptr) return false;
        if (key == node->value) return true;
        if (key < node->value)
            return search_recursive(node->left, key);
        else
            return search_recursive(node->right, key);
    }

    void inorder_recursive(Node* node) {
        if (node == nullptr) return;
        inorder_recursive(node->left);
        cout << node->value << " ";
        inorder_recursive(node->right);
    }
};

int main() {
    Tree tree;
    int key;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.inorder();  // Output: 20 30 40 50 60 70 80

    cout << "Enter value to search: ";
    cin >> key;
    tree.search(key);

    return 0;
}

