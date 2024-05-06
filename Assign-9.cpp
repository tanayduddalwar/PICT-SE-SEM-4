#include<bits/stdc++.h>
using namespace std;
class node {
    private:
        string key;
        string value;
        node* left;
        node* right;
    public:
        node(string key,string value):key(key),value(value),left(NULL),right(NULL){}
        friend class AVL;
};

class AVL{
    public:
        int height(node* root){
            if(root==NULL){
                return 0;
            }
            int left=height(root->left);
            int right=height(root->right);
            int ans=max(left,right)+1;
            return ans;
        }

        int balanceFactor(node* root){
            if(root==NULL){
                return 0;
            }
            return height(root->left)-height(root->right);
        }

        node* LL(node* root){
            node* x=root->left;
            node* y=x->right;
            x->right=root;
            root->left=y;
            return x;
        }

        node* RR(node* root){
            node* x=root->right;
            node* y=x->left;
            x->left=root;
            root->right=y;
            return x;
        }

        node* insert(node* root,node* newnode){
            if(root==NULL){
                root=newnode;
                cout<<"Data inserted successfully"<<endl;
                return root;
            }
            if(root->key > newnode->key){
                root->left=insert(root->left,newnode);
            }
            else if(root->key < newnode->key){
                root->right=insert(root->right,newnode);
            }
            else{
                cout<<"Duplicate data";
            }

            int bf=balanceFactor(root);
            if(bf>1 && root->left->key > newnode->key){
                return LL(root);
            }
            else if(bf<-1 && root->right->key < newnode->key){
                int bf=balanceFactor(root);
                cout<<bf<<endl;
                return RR(root);
            }
            else if(bf>1 && root->left->key < newnode->key){
                root->left=RR(root->left);
                return LL(root);
            }
            else if(bf<-1 && root->right->key >newnode->key){
                root->right=LL(root->right);
                int bf=balanceFactor(root->right);
                cout<<bf<<endl;
                return RR(root);
            }

            return root;
        }

        void inorder(node* root){
            if(root == NULL){
                return;
            }
            inorder(root->left);
            cout<<root->key<<"->"<<root->value;
            cout<<endl;
            inorder(root->right);
        }
};

int main(){
    AVL avlTree;
    node* root = NULL;

    
    root = avlTree.insert(root, new node("banana", "Another fruit"));
    root = avlTree.insert(root, new node("orange", "Yet another fruit"));
    root = avlTree.insert(root, new node("grape", "A grape fruit"));
    root = avlTree.insert(root, new node("kiwi", "A tropical fruit"));
    root = avlTree.insert(root, new node("apple", "A fruit"));
    root = avlTree.insert(root, new node("pear", "A pear fruit"));
    cout << "Inorder traversal of AVL tree:" << endl;
    avlTree.inorder(root);
    return 0;

}