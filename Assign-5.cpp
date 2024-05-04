#include<iostream>
using namespace std;

class Node{
public:
    int key;
    int value;
    Node* next;
    
    Node(int key, int value): key(key), value(value), next(nullptr) {}
};
class HashMap{
private:
    Node* head[10]; // Array of linked list heads
public:
    HashMap() {
        for (int i = 0; i < 10; ++i) {
            head[i] = nullptr;
        }
    }
    int hashfunction(int key){
        return key % 10;
    }

    void insert(int key, int value){
        Node *temp = new Node(key, value);
        int index = hashfunction(key);
        if(head[index] == NULL){
            head[index] = temp;
        }
        
        else{
            Node* curr = head[index];
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = temp;
        }
    }

    int search(int key){
        int index = hashfunction(key);
        Node* curr = head[index];
        while(curr != NULL){
            if(curr->key == key){
                return curr->value;
            }
            curr = curr->next;
        }
        return -1;
    }
    void remove(int key){
        int index = hashfunction(key);
        Node* curr = head[index];
        Node* prev = NULL;
        while (curr != NULL && curr->key != key){
            prev = curr;
            curr = curr->next;
        }
        if(curr == NULL){
            cout << "No element found" << endl;
        }
        if(prev == NULL){
            head[index] = curr->next;
        }
        else{
            prev->next = curr->next;
        }
        delete curr;
        cout << "Node deleted successfully" << endl;
    }
    
    void display(){
        for(int i=0;i<10;i++){
            Node* tmp=head[i];
            cout<<"Index"<<i<<":";
            while(tmp!=NULL){   
                cout<<"["<<tmp->key<<","<<tmp->value<<"]"<<"->";
            }
            cout<<"NULL"<<endl;
        }
    }
};

int main(int argc, char const *argv[]){
    HashMap map;
    map.insert(5, 10);
    map.insert(12, 20);
    map.insert(25, 32);
    map.insert(14, 8);
    map.display();
    cout << "Value for key 5: " << map.search(5) << endl;
    cout << "Value for key 15: " << map.search(15) << endl;
    cout << "Value for key 25: " << map.search(25) << endl;
    cout << "Value for key 35: " << map.search(35) << endl;
    map.remove(5);
    cout << "Value for key 15 after removal: " << map.search(12) << endl;
    map.display();

    return 0;
}
