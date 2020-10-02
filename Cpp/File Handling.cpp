#include <bits/stdc++.h>

using namespace std;


// ifstream for file read
void readFile(char filename[]) {
    ifstream readStream;
    readStream.open(filename);
    string line;
    while(readStream) {        
        getline(readStream, line);
        cout << line <<"\n";
    }
    readStream.close();
}


// ofstream for file write
void writeFile(char filename[]) {
    ofstream writeStream;
    writeStream.open(filename);
    string line;
    while(writeStream) {
        getline(cin, line);
        if (line == "-1") break;
        writeStream << line << "\n";    
    }
    writeStream.close();
}


// fstream for file read and write
void readAndWriteFile(char filename[]) {
    fstream RAndWStream;
    RAndWStream.open(filename);
    string line;

    // write file
    while(RAndWStream) {
        getline(cin, line);
        if (line == "-1") break;
        RAndWStream << line << "\n";    
    }
    RAndWStream.close();

    // read file
    RAndWStream.open(filename);
    while(RAndWStream) {        
        getline(RAndWStream, line);
        cout << line <<"\n";
    }
    RAndWStream.close();
}

int main() {
    char filename[] = "sample.txt";
    readFile(filename);
    writeFile(filename);
    readAndWriteFile(filename);
    return 0;
}