#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    Node* lchild;
    Node* rchild;
    int data;

    // Overloaded assignment operator for Node
    Node& operator=(const Node& other) {
        if (this != &other) {
            data = other.data;
            if (other.lchild) {
                lchild = new Node;
                *(lchild) = *(other.lchild);
            } else {
                lchild = nullptr;
            }
            if (other.rchild) {
                rchild = new Node;
                *(rchild) = *(other.rchild);
            } else {
                rchild = nullptr;
            }
        }
        return *this;
    }
};

void create(Node*& root) {
    Node *p, *t;
    cout << "Enter the value of the root:" << endl;
    root = new Node;
    int val;
    cin >> val;
    root->data = val;
    root->lchild = root->rchild = NULL;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        t = q.front();
        q.pop();
        cout << "Enter the left child of " << t->data << endl;
        int x;
        cin >> x;
        if (x != -1) {
            p = new Node;
            p->data = x;
            p->lchild = p->rchild = NULL;
            t->lchild = p;
            q.push(p);
        }
        cout << "Enter the right child of " << t->data << endl;
        cin >> x;
        if (x != -1) {
            p = new Node;
            p->data = x;
            p->lchild = p->rchild = NULL;
            t->rchild = p;
            q.push(p);
        }
    }
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    } else {
        cout << root->data << " ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->lchild);
    cout << root->data << " ";
    inorder(root->rchild);
}

void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    cout << root->data << " ";
}

void preorder1(Node* root) {
    stack<Node*> st;
    
    while (!st.empty() || root != NULL) {
        if (root != NULL) {
            cout << root->data << " ";
            st.push(root);
            root = root->lchild;
        } else {
            root = st.top();
            st.pop();
            root = root->rchild;
        }
    }
}

void inorder1(Node* root) {
    stack<Node*> st;
   
    while (!st.empty() || root != NULL) {
        if (root != NULL) {
            st.push(root);
            root = root->lchild;
        } else {
            root = st.top();
            cout << root->data << " ";
            st.pop();
            root = root->rchild;
        }
    }
}

void postorder1(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> st1;
    stack<Node*> st2;

    st1.push(root);

    while (!st1.empty()) {
        Node* node = st1.top();
        st1.pop();
        st2.push(node);

        if (node->lchild)
            st1.push(node->lchild);
        if (node->rchild)
            st1.push(node->rchild);
    }

    while (!st2.empty()) {
        Node* node = st2.top();
        cout << node->data << " ";
        st2.pop();
    }
}


void leafnodes(Node* root) {
    int count = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
    
            Node* node = q.front();
            q.pop();
            if (node->lchild != NULL) {
                q.push(node->lchild);
            }
            if (node->rchild != NULL) {
                q.push(node->rchild);
            }
            if (node->lchild == NULL && node->rchild == NULL) {
                count++;
            }
        
    }

    cout << "Number of leaf nodes are: " << count;
}

int internalnodes(Node* root) {
    int count = 0;
    if (root == NULL) {
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        if (node->lchild != NULL || node->rchild != NULL) {
            count++;
        }
        if (node->lchild != NULL) {
            q.push(node->lchild);
        }
        if (node->rchild != NULL) {
            q.push(node->rchild);
        }
    }
    return count;
}

int depth(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int ldepth = depth(root->lchild);
    int rdepth = depth(root->rchild);
    return 1 + max(ldepth, rdepth);
}

void erase(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->lchild) {
        erase(root->lchild);
    }
    if (root->rchild) {
        erase(root->rchild);
    }
    delete(root);
}

void swapLeftAndRight(Node* root) {
    if (root == nullptr) {
        return;
    }

  
    Node* temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;


    swapLeftAndRight(root->lchild);
    swapLeftAndRight(root->rchild);
}

int main() {
    Node* root = nullptr;
    Node* newroot = nullptr;

    create(root);

    cout << "Preorder:";
    preorder(root);
    cout << endl;
    cout << "Inorder:";
    inorder(root);
    cout << endl;
    cout << "PostOrder:";
    postorder(root);
    cout << endl;
    cout << "Depth of the tree is: " << depth(root) << endl;
    cout << "Inorder by iterative:";
    inorder1(root);
    cout << endl;
    cout << "Preorder by iterative:";
    preorder1(root);
    cout << endl;
    cout << "Postorder by iterative:";
    postorder1(root);
    cout << endl;
    cout << "Number of leaf nodes are: ";
    leafnodes(root);
    cout << endl;


     Node* root2 = new Node();
    *root2 = *root; 


    cout << "Address of original tree root: " << root << endl;
    cout << "Address of copied tree root: " << root2 << endl;


    swapLeftAndRight(root);

   
    erase(root);
    erase(newroot);

    return 0;
}
