#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int key;
    string number;
    Node(int key, string num) {
        this->key = key;
        this->number = num;
    }
    Node(){
        key=-1;
        number="";
    }
    
  //  Node() : key(-1), number("") {} // Default constructor for initializing with default values
};

class HashMap {
public:
    Node arr[10]; 
    // No initializer, so default constructor of Node will be called for each element

    // Constructor (not provided in your original code)
    // HashMap() {}

    int hashfunction(int key) {
        return (3 * key + 5) % 10;
    }

    int probe(int index) {
        int i = 0;
        while (!arr[(index + (3 * i + 5)) % 10].number.empty()) {
            i++;
        }
        return (index + (3 * i + 5)) % 10;
    }

    void insertwithoutreplacement(int key, string value) {
        int index = hashfunction(key);
        if (arr[index].number.empty()) {
            arr[index] = Node(key, value);
        }
        else {
            int newIndex = probe(index);
            arr[newIndex] = Node(key, value);
        }
    }

    void insertwithreplacement(int key, string value) {
        int index = hashfunction(key);
        if (arr[index].number.empty()) {
            arr[index] = Node(key, value);
        }
        else if ((3 * arr[index].key + 5) % 10 == index) {
            int next = probe(index);
            arr[next] = Node(key, value);
        }
        else {
            string val = arr[index].number;
            int key1 = arr[index].key;
            int newIndex = probe(index);
            arr[newIndex] = Node(key1, val);
            arr[index] = Node(key, value);
        }
    }

    void display() {
        for (int i = 0; i < 10; i++) {
            if (!arr[i].number.empty()) {
                cout << "Index " << i << ": Key " << arr[i].key << ", Value = " << arr[i].number << endl;
            }
            else {
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }
};

int main() {
    HashMap mp;
    mp.insertwithoutreplacement(5, "Five");
    mp.insertwithreplacement(15, "Fifteen");
    mp.display();

    return 0;
}
