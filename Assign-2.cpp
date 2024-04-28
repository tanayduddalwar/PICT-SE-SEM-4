#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node* lchild;
    Node* rchild;
};

void insert(Node*& root) {
    int value;
    while (true) {
        cout << "Enter the value of the root (-1 to stop):" << endl;
        cin >> value;
        if (value == -1) {
            break;
        }
        if (root == NULL) {
            root = new Node();
            root->val = value;
            root->lchild = root->rchild = NULL;
            continue;
        }
        Node* curr = root;
        while (true) {
            if (value < curr->val) {
                if (curr->lchild == NULL) {
                    curr->lchild = new Node();
                    curr->lchild->lchild = curr->lchild->rchild = NULL;
                    curr->lchild->val = value;
                    break;
                } else {
                    curr = curr->lchild;
                }
            } else if (value > curr->val) {
                if (curr->rchild == NULL) {
                    curr->rchild = new Node();
                    curr->rchild->lchild = curr->rchild->rchild = NULL;
                    curr->rchild->val = value;
                    break;
                } else {
                    curr = curr->rchild;
                }
            }
        }
    }
}

void findmin(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }
    while (root->lchild != NULL) {
        root = root->lchild;
    }
    cout << "Min value in the BST is: " << root->val << endl;
}

void findmax(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }
    while (root->rchild != NULL) {
        root = root->rchild;
    }
    cout << "Max value in the BST is: " << root->val << endl;
}

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int lh = height(root->lchild);
    int rh = height(root->rchild);
    return 1 + max(lh, rh);
}

void swapping(Node* root) {
    if (root == NULL) {
        return;
    }
    Node* temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;
    swapping(root->lchild);
    swapping(root->rchild);
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->lchild);
    cout << root->val << " ";
    inorderTraversal(root->rchild);
}

void search(Node* root, int value) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }
    Node* curr = root;
    while (curr != NULL) {
        if (curr->val == value) {
            cout << "Element is found in BST" << endl;
            return;
        } else if (curr->val < value) {
            curr = curr->rchild;
        } else if (value < curr->val) {
            curr = curr->lchild;
        }
    }
    cout << "Element is not found" << endl;
}

int main() {
    Node* root = nullptr;
    cout << "Inserting Values" << endl;
    insert(root);
    inorderTraversal(root);
    cout << endl;
    cout << "Height of the tree: " << height(root) << endl;
    findmin(root);
    findmax(root);
    int searchValue;
    cout << "Enter the value to be searched: ";
    cin >> searchValue;
    search(root, searchValue);
    cout << "Swapping left and right pointers" << endl;
    swapping(root);
    inorderTraversal(root);
    cout << endl;
    return 0;
}
