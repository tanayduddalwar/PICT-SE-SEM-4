#include <iostream>
using namespace std;

class ThreadedBinaryTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        int lbit;
        int rbit;

        Node(int value) : data(value), left(nullptr), right(nullptr), lbit(0), rbit(0) {}
    };

    Node* root;
    Node* head;

    void insert(Node* root, Node* temp);
    void inorder(Node* head);

public:
    ThreadedBinaryTree() : root(nullptr), head(nullptr) {}

    void create();
    void traverseInorder();
};

void ThreadedBinaryTree::create() {
    char ch;
    do {
        int value;
        cout << "Enter value to insert: ";
        cin >> value;

        Node* temp = new Node(value);

        if (root == nullptr) {
            root = temp;
            head = new Node(999);
            head->rbit = 1;
            head->lbit = 1;
            head->left = root;
            root->left = head;
            root->right = head;
        } else {
            insert(root, temp);
        }

        cout << "Do you want to insert more nodes? (Y/N): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}

void ThreadedBinaryTree::insert(Node* root, Node* temp) {
    if (temp->data < root->data) {
        if (root->lbit == 0) {
            temp->left = root->left;
            temp->right = root;
            root->left = temp;
            root->lbit = 1;
        } else {
            insert(root->left, temp);
        }
    } else if (temp->data > root->data) {
        if (root->rbit == 0) {
            temp->right = root->right;
            temp->left = root;
            root->right = temp;
            root->rbit = 1;
        } else {
            insert(root->right, temp);
        }
    }
}

void ThreadedBinaryTree::inorder(Node* head) {
    Node* t = head->left;
    while (t->lbit != 0) {
        t = t->left;
    }
    while (t != head) {
        cout << t->data << " ";
        if (t->rbit == 1) {
            t = t->right;
            while (t->lbit != 0) {
                t = t->left;
            }
        } else {
            t = t->right;
        }
        if (t == head) {
            break; // Exit the loop when reaching the head node again
        }
    }
}

void ThreadedBinaryTree::traverseInorder() {
    if (head == nullptr || root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }
    inorder(head);
}

int main() {
    ThreadedBinaryTree tree;
    tree.create();
    cout << "Inorder Traversal: ";
    tree.traverseInorder();
    return 0;
}
