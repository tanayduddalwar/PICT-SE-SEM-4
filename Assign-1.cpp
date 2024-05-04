// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
#include<queue>
using namespace std;
class TreeNode{
    public:
    TreeNode*left;
    TreeNode*right;
    int data;
    TreeNode(int val){
    this->data=val;
    left=nullptr;
    right=nullptr;
}
};
class Node {
    public:
    TreeNode* root;
    Node(){
        this->root=NULL;
    }
    void create(){
        TreeNode *p,*t;
        queue<TreeNode*>q;
        cout<<"Enter the value of root node"<<endl;
        int rootval;
        cin>>rootval;
        root=new TreeNode(0);
        root->data=rootval;
        root->left=root->right=NULL;
        q.push(root);
        while(!q.empty()){
            t=q.front();
            q.pop();
            cout<<"Enter the left child of :"<<t->data<<endl;
            int x;
         cin>>x;
         if(x!=-1){
             p =new TreeNode(x);
             p->left=p->right=NULL;
             t->left=p;
             q.push(p);
         }
         cout<<"Enter the right child of :"<<t->data<<endl;
         cin>>x;
         if(x!=-1){
             p=new TreeNode(x);
             p->left=p->right=NULL;
             t->right=p;
             q.push(p);
         }
        }
    }
    void preorder(TreeNode* root){
        if(root==NULL){
            return ;
        }
        else{
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }
       void inorder(TreeNode* root){
        if(root==NULL){
            return ;
        }
        else{
            
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }
    void postorder(TreeNode* root){
        if(root==NULL){
            return ;
        }
        else{
            
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }
       void preorder1(TreeNode* root){
        stack<TreeNode*>st;
        TreeNode *node=root;
        while(root!=NULL && !st.empty()){
            if(root!=NULL){
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
           void inorder1(TreeNode* root){
        stack<TreeNode*>st;
        TreeNode *node=root;
        while(root!=NULL && !st.empty()){
            if(root!=NULL){
                //cout<<node->data<<" ";
                st.push(node);
                node=node->left;
            }
            else{
                cout<<node->data<<" ";
                node=st.top();
                st.pop();
                node=node->right;
            }
        }}
         void postorder1(TreeNode* root){
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node=st1.top();
            st1.pop();
            st2.push(node);
            if(node->left!=NULL){
                st1.push(node->left);
            }
            if(node->right!=NULL){
                st1.push(node->right);
            }
        }
    }
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(lh,rh);
    }
    int leafnodes(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        return leafnodes(root->left)+leafnodes(root->right);
    }
    int leafnodes1(TreeNode* root){
        int count=0;
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                if(node->left==NULL && node->right==NULL){
                    count++;
                }
            }
        
        cout<<"Number of leaf nodes are:"<<count<<endl;
    }
    int internalnodes(TreeNode* root){
        int intcount=0;
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node =q.front();
            q.pop();
            if(node->left!=NULL || node->right!=NULL){
                intcount++;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        cout<<"Number of internal nodes are:"<<intcount;
    }
    void leveltraversal(TreeNode* root){
        if(root==NULL){
            return ;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    void swapleftandright(TreeNode* root){
        if(root==NULL){
            return;
        }
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        swapleftandright(root->left);
        swapleftandright(root->right);
    }
    
    
};
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    Node rw;
    rw.create();
    rw.preorder(rw.root);
    cout<<endl;
    rw.inorder(rw.root);
    cout<<endl;
    rw.postorder(rw.root);
    rw.swapleftandright(rw.root);
    cout<<endl;
    rw.preorder(rw.root);
    

    return 0;
}