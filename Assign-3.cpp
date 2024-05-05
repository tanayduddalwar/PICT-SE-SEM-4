#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    bool lbit;
    bool rbit;
};

// Function to find the inorder successor of a node
Node* inorderSuccessor(Node* node) {
    // If the right child is a thread, return it
    if (node->rbit)
        return node->right;

    // Otherwise, find the leftmost child of the right subtree
    node = node->right;
    while (!node->lbit)
        node = node->left;
    return node;
}

// Function to insert a node into the threaded binary tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        root = new Node();
        root->val = value;
        root->left = root->right = NULL;
        root->lbit = root->rbit = true;
    } else {
        Node* child = root;
        Node* parent = NULL;
        while (child != NULL) {
            parent = child;
            if (value < child->val) {
                if (child->lbit) {
                    Node* tmp = new Node();
                    tmp->val = value;
                    tmp->left = child->left;
                    tmp->right = child;
                    tmp->lbit = tmp->rbit = true;
                    child->left = tmp;
                    child->lbit = false;
                    return root;
                } else {
                    child = child->left;
                }
            } else {
                if (child->rbit) {
                    Node* tmp = new Node();
                    tmp->val = value;
                    tmp->right = child->right;
                    tmp->left = child;
                    tmp->lbit = tmp->rbit = true;
                    child->right = tmp;
                    child->rbit = false;
                    return root;
                } else {
                    child = child->right;
                }
            }
        }
    }
    return root;
}

// Function to perform an inorder traversal of the threaded binary tree
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    
    Node* curr = root;
    Node* prev = nullptr;

    while (curr != nullptr) {
        while (curr->lbit == false) {
            curr = curr->left;
        }

        cout << curr->val << " ";

        while (curr->rbit && curr->right != prev) {
            prev = curr;
            curr = curr->right;
            cout << curr->val << " ";
        }

        prev = curr;
        curr = curr->right;
    }
}

// Function to delete a node from the threaded binary tree
// Node* deleteNode(Node* root, int key) {
//     // Base case: if the tree is empty
//     if (root == nullptr)
//         return nullptr;

//     Node* curr = root;
//     Node* parent = nullptr;

//     // Search for the node to be deleted
//     while (curr != nullptr && curr->val != key) {
//         parent = curr;
//         if (key < curr->val)
//             curr = curr->left;
//         else
//             curr = curr->right;
//     }

//     // If the node with the given key is not found
//     if (curr == nullptr)
//         return root;

//     // Case 1: Node to be deleted is a leaf node
//     if (curr->left == nullptr && curr->right == nullptr) {
//         // If the node to be deleted is not the root
//         if (curr != root) {
//             if (parent->left == curr) {
//                 parent->lbit = true;
//                 parent->left = curr->left;
//             } else {
//                 parent->rbit = true;
//                 parent->right = curr->right;
//             }
//         } else {
//             // If the node to be deleted is the root
//             delete root;
//             return nullptr;
//         }
//         delete curr;
//     }
//     // Case 2: Node to be deleted has only one child
//     else if (curr->left == nullptr || curr->right == nullptr) {
//         Node* child = (curr->left != nullptr) ? curr->left : curr->right;
//         // If the node to be deleted is not the root
//         if (curr != root) {
//             if (parent->left == curr)
//                 parent->left = child;
//             else
//                 parent->right = child;
//         } else {
//             // If the node to be deleted is the root
//             root = child;
//         }
//         delete curr;
//     }
//     // Case 3: Node to be deleted has two children
//     else {
//         Node* successor = inorderSuccessor(curr);
//         curr->val = successor->val;
//         // Delete the successor node
//         curr->right = deleteNode(curr->right, successor->val);
//     }
//     return root;
// }

int main() {
    // Example usage
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 18);

    cout << "Inorder Traversal before deletion: ";
    inorderTraversal(root);
    cout << endl;

   // root = deleteNode(root, 10);

    cout << "Inorder Traversal after deletion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
