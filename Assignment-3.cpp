#include <iostream>
using namespace std;

class Node {
    Node* left;
    Node* right;
    int lbit;
    int rbit;
    int data;
public:
    Node(int key) {
        this->data = key;
        left = right = NULL;
        lbit = rbit = 0;
    }
    friend class TBT;
};

class TBT {
public:
    Node* head;
    Node* root;
    TBT() {
        root = NULL;
    }

    void create() {
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
                root->right = temp;

                temp->left = root;
                root->rbit = 1;
            } else {
                insert(root->right, temp);
            }
        }
    }

    void preorder(Node* root) {
        Node* t = head->left;
        do {
            while (t->lbit != 0) {
                cout << t->data << " ";
                t = t->left;
            }
            cout << t->data << " ";
            while (t->rbit == 0) {
                t = t->right;
                if (t == head) {
                    return;
                }
            }
            t = t->right;
        } while (t != head);
    }

    void inorder(Node* root) {
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

    Node* caseA(Node*& root, Node*& par, Node*& ptr) {
        if (par == NULL) {
            root = NULL;
        } else if (ptr == par->left) {
            par->lbit = 0;
            par->left = ptr->left;
        } else {
            par->rbit = 0;
            par->right = ptr->right;
        }

        delete ptr;
        return root;
    }

    Node* caseB(Node*& root, Node*& par, Node*& ptr) {
        Node* child;
        if (ptr->lbit == 1) {
            child = ptr->left;
        } else {
            child = ptr->right;
        }

        if (par == NULL) {
            root = child;
        } else if (ptr == par->left) {
            par->left = child;
        } else {
            par->right = child;
        }
        Node* s = inorderSuccessor(ptr);
        Node* p = inorderPredecessor(ptr);
        if (ptr->lbit == 1) {
            p->right = s;
        } else if (ptr->rbit == 1) {
            s->left = p;
        }
        delete ptr;
        return root;
    }

    Node* caseC(Node*& root, Node*& par, Node*& ptr) {
        Node* parSucc = ptr;
        Node* succ = ptr->right;

        while (succ->lbit == 1) {
            parSucc = succ;
            succ = succ->left;
        }

        ptr->data = succ->data;

        if (succ->lbit == 0 && succ->rbit == 0) {
            root = caseA(root, parSucc, succ);
        } else {
            root = caseB(root, parSucc, succ);
        }
        return root;
    }

    Node* delTBST(Node*& root, int dkey) {
        Node* par = NULL;
        Node* ptr = root;
        int found = 0;
        while (ptr != NULL) {
            if (ptr->data == dkey) {
                found = 1;
                break;
            }
            par = ptr;
            if (dkey < ptr->data) {
                if (ptr->lbit == 1) {
                    ptr = ptr->left;
                } else {
                    break;
                }
            } else {
                if (ptr->rbit == 1) {
                    ptr = ptr->right;
                } else {
                    break;
                }
            }
        }
        if (found == 0) {
            cout << "Key not Present\n";
        } else if (ptr->lbit == 1 && ptr->rbit == 1) {
            root = caseC(root, par, ptr);
        } else if (ptr->lbit == 1) {
            root = caseB(root, par, ptr);
        } else if (ptr->rbit == 1) {
            root = caseB(root, par, ptr);
        } else {
            root = caseA(root, par, ptr);
        }
        return root;
    }

    Node* inorderSuccessor(Node* ptr) {
        if (ptr->rbit == 0) {
            return ptr->right;
        }
        ptr = ptr->right;
        while (ptr->lbit == 1) {
            ptr = ptr->left;
        }
        return ptr;
    }

    Node* inorderPredecessor(Node* ptr) {
        if (ptr->lbit == 0) {
            return ptr->left;
        }
        ptr = ptr->left;
        while (ptr->rbit == 1) {
            ptr = ptr->right;
        }
        return ptr;
    }
};

int main() {
    TBT tbt;
    tbt.create();
    int key;
    cout << "Enter key to delete: ";
    cin >> key;
    tbt.delTBST(tbt.root, key);
    cout << "Inorder Traversal: ";
    tbt.preorder(tbt.root);
    return 0;
}
