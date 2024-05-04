#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler {
private:
    fstream MyFile;
    char buffer[40];

public:
    void write() {
        MyFile.open("demo.txt", ios::out);
        if (!MyFile) {
            cout << "Error Opening the File" << endl;
        }
        else {
            MyFile << "11-Nitya SE-1 COMPUTER KOTHRUD PUNE" << endl;
            MyFile << "12-Sanju SE-I Computer Ambegaon, Pune." << endl;
            MyFile << "21-Tanay SE-I Computer Yavatmal." << endl;
        }
        MyFile.close();
    }

    void read() {
        MyFile.open("demo.txt", ios::in);
        if (!MyFile) {
            cout << "Error opening the file" << endl;
        }
        else {
            int recordNum = 1;
            while (MyFile.getline(buffer, 40)) {
                cout << "Record-" << recordNum++ << ": " << buffer << endl;
            }
        }
        MyFile.close();
    }

   void removeFile() {
    if (remove("demo.txt") != 0) { // Use :: to access the global remove function
        cout << "Error deleting the file" << endl;
    }
    else {
        cout << "File deleted successfully" << endl;
    }
}

};

int main() {
    FileHandler fileHandler;
    fileHandler.write();
    fileHandler.read();
    //fileHandler.removeFile();

    return 0;
}
