#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* root, int value) {
        if (root == NULL) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
        return root;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    Node* findMax(Node* node) {
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == NULL) return root;

        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* temp = findMax(root->left);
                root->data = temp->data;
                root->left = deleteNode(root->left, temp->data);
            }
        }
        return root;
    }
    void deleteNode(int key) {
        root = deleteNode(root, key);
    }
    void displayTree(Node* node, int space = 0, int height = 10) {
        if (node == NULL)
            return;
        space += height;
        displayTree(node->right, space);
        cout << endl;
        for (int i = height; i < space; i++)
            cout << " ";
        cout << node->data << "\n";
        displayTree(node->left, space);
    }

    void display() {
        cout << "Visual Tree Structure:\n";
        displayTree(root);
    }
    void showTraversals() {
        cout << "\nIn-Order Traversal: ";
        inorder(root);
        cout << "\nPre-Order Traversal: ";
        preorder(root);
        cout << "\nPost-Order Traversal: ";
        postorder(root);
        cout << "\n";
    }
};

int main() {
    BST tree;
    int values[] = {40, 20, 66, 1, 32, 51, 78};
    cout << "Inserting values: ";
    for (int val : values) {
        cout << val << " ";
        tree.insert(val);
    }
    cout << "\n";
    tree.display();

    cout << "\nTraversals after insertion:\n";
    tree.showTraversals();

    cout << "\nDeleting node with value 66...\n";
    tree.deleteNode(66);
    tree.display();

    cout << "\nIn-Order Traversal after deleting 66: ";
    tree.inorder(tree.root);
    cout << "\n";

    return 0;
}
