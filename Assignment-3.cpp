#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int lbit;
    int rbit;
};

Node* temp;
Node* root = NULL;
Node* head;

void insert(Node* root, Node* temp);
void inorder(Node* head);

void create() {
    char ch;
    do {
        temp = new Node;
        cin >> temp->data;
        temp->left = NULL;
        temp->right = NULL;
        temp->lbit = 0;
        temp->rbit = 0;
        if (root == NULL) {
            root = temp;
            head = new Node;
            head->data = 999;
            head->rbit = 1;
            head->lbit = 1;
            head->left = root;
            root->left = head;
            root->right = head;
        }
        else {
            insert(root, temp);
        }
        cout << "Do you want to insert more nodes? ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}

void insert(Node* root, Node* temp) {
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

void inorder(Node* head) {
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

int main() {
    create();
    inorder(head);
    return 0;
}
