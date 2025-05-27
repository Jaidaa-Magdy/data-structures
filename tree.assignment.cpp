#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {

    Node* root = new Node(63);
    root->left = new Node(41);
    root->right = new Node(74);
    root->left->left = new Node(16);
    root->left->right = new Node(53);
    root->left->right->left = new Node(46);
    root->left->right->right = new Node(55);
    root->left->right->right->right = new Node(25);
    root->right->left = new Node(65);
    root->right->left->left = new Node(64);
    root->right->right = new Node(70);

    cout << "In-Order Traversal: ";
    inOrder(root);
    cout << "\n";

    cout << "Pre-Order Traversal: ";
    preOrder(root);
    cout << "\n";

    cout << "Post-Order Traversal: ";
    postOrder(root);
    cout << "\n";
    return 0;
}
