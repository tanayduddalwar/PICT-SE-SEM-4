#include <iostream>
#include <map>
using namespace std;

struct Node{
    int key;
    string value;
    Node* next;
};
int hashfunc(int key) {
    return key % 10;
}
int probe(Node arr[],int key){
    int index=hashfunc(key);
    int i=0;
    while(!arr[index+i%10].value.empty()){
        i++;
    }
    return (index+i)%10;
}
int insertwithoutreplacement(Node arr[],int key,string value){
    int index=hashfunc(key);
    if(arr[index].value.empty()){
        arr[index].key=key;
        arr[index].value=value;

    }
    else{
        int next=probe(arr,key);
        arr[next].key=key;
        arr[next].value=value;
    }
}

int insertwithreplacement(Node arr[],int key,string value){
    int index=hashfunc(key);
    if(arr[index].value.empty()){
        arr[index].key=key;
        arr[index].value=value;
    }
    else{
        if(arr[index].key%10 == index){
            int next=probe(arr,key);
            arr[next].key=key;
            arr[next].value=value;
        }
        else{
            string value=arr[index].value;
            int key1=arr[index].key;
            arr[index].key=key;
            arr[index].value=value;
            int nt=probe(arr,key1);
            arr[nt].key=key1;
            arr[nt].value=value;
        }
    }
}


int main() {
    Node hashTable[10]; // Array of Nodes

    // Example usage
    insertwithoutreplacement(hashTable, 5, "Five");
    insertwithreplacement(hashTable, 15, "Fifteen");
    insertwithreplacement(hashTable, 14, "Four");
    insertwithoutreplacement(hashTable,24,"Twenty Four");
    insertwithreplacement(hashTable, 17, "SeVENTEEN");

    // Display the contents of the hash table
    for (int i = 0; i < 10; ++i) {
        if (!hashTable[i].value.empty()) {
            cout << "Index " << i << ": Key = " << hashTable[i].key << ", Value = " << hashTable[i].value << endl;
        } else {
            cout << "Index " << i << ": Empty" << endl;
        }
    }

    return 0;
}
