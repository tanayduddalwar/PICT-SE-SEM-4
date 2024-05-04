#include <iostream>
#include <stack>
#include<queue>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;
    Node(int val) {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() {
        root = NULL;
    }

    void insert(Node*& root, int value) {
        if (root == nullptr) {
            root = new Node(value);
            return;
        }

        if (value < root->data) {
            if (root->left == nullptr) {
                root->left = new Node(value);
            } else {
                insert(root->left, value);
            }
        } else if (value > root->data) {
            if (root->right == nullptr) {
                root->right = new Node(value);
            } else {
                insert(root->right, value);
            }
        }
    }

    void deleted(Node*& root, int value) {
        if (root == NULL) {
            return;
        }

        if (value < root->data) {
            deleted(root->left, value);
        } else if (value > root->data) {
            deleted(root->right, value);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                root = temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                root = temp;
            } else {
                Node* temp = findmin(root->right);
                root = temp;
                deleted(root->right, temp->data);
            }
        }
    }

    Node* findmin(Node* root) {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
          
        }
        while (root->left != NULL) {
            root = root->left;
        }
        cout << "Minimum value in the tree: " << root->data << endl;
    }

    int height(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh, rh);
    }

    void inorder(Node* root) {
        stack<Node*> st;
        Node* node = root;
        while (node != NULL || !st.empty()) {
            if (node != NULL) {
                st.push(node);
                node = node->left;
            }
            else{
            node = st.top();
            st.pop();
            cout << node->data << " ";
            node = node->right;
        }}
    }
    void preorder(Node* root){
        stack<Node*>st;
        Node* node=root;
        while(!st.empty() || node!=NULL){
            if(node!=NULL){
                cout<<node->data<<" ";
                st.push(node);
                node=node->left;
            }
            else{
                node=st.top();
                st.pop();
                node=node->right;
            }
        }
    }
    void searching(Node* root) {
        int noofcomparisons = 0;
        int x;
        cout << "Enter the element to search: ";
        cin >> x;

        Node* current = root;
        while (current != NULL) {
            noofcomparisons++;
            if (current->data == x) {
                cout << "Element found after " << noofcomparisons << " comparisons." << endl;
                return;
            } else if (x < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        cout << "Element not found." << endl;
    }
    void inorderDesc(Node* root) {
    if (root == NULL)
        return;
    stack<Node*> st;
    Node* node = root;
    while (node != NULL || !st.empty()) {
        if (node != NULL) {
            st.push(node);
            node = node->right; // Visit right subtree first
        } else {
            node = st.top();
            st.pop();
            cout << node->data << " "; // Print current node
            node = node->left; // Visit left subtree
        }
    }
}

void levelorder(Node* root){
    if(root==NULL){
        return;
    }
    
    queue<Node*>q;
    q.push(root);
    while(root!=NULL){
        Node *node=q.front();
        cout<<node<<" ";
        q.pop();
        if(root->left){
            q.push(node->left);
        }
        if(root->right){
            q.push(node->right);
        }

    }
}
void swapTree(Node* root) {
    if (root == NULL) {
        return;
    }
    
    // Swap left and right pointers
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Recursively swap the left and right subtrees
    swapTree(root->left);
    swapTree(root->right);
}


};

int main() {
    BinaryTree tree;
  int size;
  cout<<"Enter the size of the tree"<<endl;
  cin>>size;
  for(int i=0;i<size;i++){
    int value;
    cout<<"Enter the value of the node"<<endl;
    cin>>value;
    tree.insert(tree.root,value);
  }

    cout << "Inorder traversal of the tree: ";
    tree.inorder(tree.root);
    cout << endl;

    tree.findmin(tree.root);
    tree.searching(tree.root);
    tree.levelorder(tree.root);
    tree.inorderDesc(tree.root);

    return 0;
}
