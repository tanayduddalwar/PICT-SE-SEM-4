#include<iostream>
using namespace std;
struct Node{
    Node* next;
    int key;
    int value;
};
Node* head[10];
int hashfunction(int key){
    return key%10;
}
int insert(int key,int value){
    Node *temp=new Node();
    temp->key=key;
    temp->value=value;
    temp->next=NULL;
    int index=hashfunction(key);
    if(head[index]==NULL){
        head[index]=temp;
    }
    else{
        Node* curr=head[index];
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
    }
}
int search(int key){
    int index=hashfunction(key);
    Node* curr=head[index];
    while(curr!=NULL){
        if(curr->key==key){
            return curr->value;
        }
        curr=curr->next;
    }
    return -1;
}
int remove(int key){
    int index=hashfunction(key);
    Node* curr=head[index];
    Node* prev=NULL;
    while (curr!=NULL && curr->key!=key){
        prev=curr;
        curr=curr->next;
    }
    if(curr==NULL){
        cout<<"No ele found"<<endl;
    }
    if(prev==NULL){
        head[index]=curr->next;
    }
    else{
    prev->next=curr->next;
    }
    delete(curr);
    cout<<"Node deleted succesfully"<<endl;
}
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; ++i) {
        head[i] = nullptr;
    }
    insert(5, 10);
    insert(12, 20);
    insert(25, 32);
    insert(14, 8);
    for(int i=0;i<10;i++){
        Node* tmp=head[i];
        cout<<"Index"<<i<<":";
        while(tmp!=NULL){
            cout<<"["<<tmp->key<<","<<tmp->value<<"]"<<"->";
            tmp=tmp->next;
        }
        cout<<"nullptr"<<endl;
    }
    //     cout << endl;
    cout << "Value for key 5: " << search(5) << endl;
    cout << "Value for key 15: " << search(15) << endl;
    cout << "Value for key 25: " << search(25) << endl;
    cout << "Value for key 35: " << search(35) << endl;
    remove(15);
    cout << "Value for key 15 after removal: " << search(15) << endl;
    return 0;
}
