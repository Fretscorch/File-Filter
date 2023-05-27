/* Programmer Name: Connor Hathaway
* 
*  Description: This program demonstrates the use of an abstract class and its subclasses to transform a text file. The user will be prompted to enter two file names, one for input and the other for output. It will then display a menu of choices
*  for transformation: one to encrypt the text, one to capitalize every character, and one to make a copy with no changes. Once the user has made their selection, the program will call the appropriate subclass function to make the necessary transformations
*  and output the changes (or lack thereof) in the users desired output file.
* 
*  Date: 5/18/23
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class FileFilter {
public:
    virtual void CharTransform(ifstream &in, ofstream &out);
};

class Encryption : public FileFilter {
public:
    void EncryptionFun(istream &in, ofstream &out) {
        string sentence;

        while (!in.eof()) {
            getline(in, sentence);
            for (int i = 0; i < sentence.length(); i++) {
                sentence[i] = sentence[i] + 2;
            }
            if (!in.eof()) {
                out << sentence << endl;
            }
            else {
                out << sentence;
            }
        }
    }
};

class Uppercase : public FileFilter {
public:
    void UppercaseFun(ifstream& in, ofstream& out) {
        string sentence;

        while (!in.eof()) {
            getline(in, sentence);
            for (int i = 0; i < sentence.length(); i++) {
                if (islower(sentence[i])) {
                    sentence[i] = toupper(sentence[i]);
                }
                else {
                    continue;
                }
            }
            if (!in.eof()) {
                out << sentence << endl;
            }
            else {
                out << sentence;
            }
        }
    }
};

class Copy : public FileFilter {
public:
    void CopyFun(ifstream &in, ofstream &out) {
        string sentence;

        while (!in.eof()) {
            getline(in, sentence);
            if (!in.eof()) {
                out << sentence << endl;
            }
            else {
                out << sentence;
            }
        }
    }
};

void FileFilter::CharTransform(ifstream &in, ofstream &out) {
    Encryption encrypt;
    Uppercase upper;
    Copy copy;
    int userInput;

    cout << "What would you like to do to the input file?\n";
    cout << "1) Encrypt it\n";
    cout << "2) Capitalize every character\n";
    cout << "3) Make an unchanged copy\n";
    cout << "Choose an option (1, 2, or 3): ";
    cin >> userInput;
    if (userInput == 1) {
        encrypt.EncryptionFun(in, out);
    }
    else if (userInput == 2) {
        upper.UppercaseFun(in, out);
    }
    else if (userInput == 3) {
        copy.CopyFun(in, out);
    }
};

int main(){
    string inputFileName;
    string outputFileName;
    ifstream inputFile;
    ofstream outputFile;
    FileFilter file;

    cout << "Enter the file name of your input: ";
    cin >> inputFileName;
    inputFile.open(inputFileName);
    cout << "Enter the file name of your output: ";
    cin >> outputFileName;
    outputFile.open(outputFileName);
    file.CharTransform(inputFile, outputFile);

    inputFile.close();
    outputFile.close();

    return 0;
}