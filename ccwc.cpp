#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <locale>

using namespace std;

// Function to count the number of bytes (or characters) from a stream
long long countBytes(istream &input) {
    input.seekg(0, ios::end);  // Move to the end of the stream
    long long byteCount = input.tellg();  // Get the number of bytes
    //input.seekg(0, ios::beg);  // Reset to the beginning of the stream
    return byteCount;
}

// Function to count the number of lines in a stream
long long countLines(istream &input) {
    long long lineCount = 0;
    string line;
    while (getline(input, line)) {  // Read each line
        lineCount++;  // Increment line count
    }
    return lineCount;
}

// Function to count the number of words in a stream
long long countWords(istream &input) {
    long long wordCount = 0;
    string line;
    while (getline(input, line)) {  // Read each line
        stringstream ss(line);
        string word;
        while (ss >> word) {  // Extract words from the line
            wordCount++;  // Increment word count
        }
    }
    return wordCount;
}

// Function to count the number of characters in a stream (supporting multibyte)
long long countCharacters(istream &input) {
    long long charCount = 0;
    char ch;
    while (input.get(ch)) {  // Read each character (bytes for UTF-8)
        charCount++;  // Increment character count
    }
    return charCount;
}

int main(int argc, char *argv[]) {
    if (argc == 3) {  // Case when option (-c, -l, -w, -m) and filename are provided
        string option = argv[1];  // Get the option
        string filename = argv[2];  // Get the filename
        if (option == "-c" || option == "-l" || option == "-w" || option == "-m") {
            ifstream file(filename);  // Open the file
            if (!file.is_open()) {  // Check if file is open
                cerr << "Error: Could not open file " << filename << endl;
                return 1;
            }

            // Handle different options
            if (option == "-c") {
                long long byteCount = countBytes(file);
                cout << byteCount << " " << filename << endl;
            } else if (option == "-l") {
                long long lineCount = countLines(file);
                cout << lineCount << " " << filename << endl;
            } else if (option == "-w") {
                long long wordCount = countWords(file);
                cout << wordCount << " " << filename << endl;
            } else if (option == "-m") {
                long long charCount = countCharacters(file);
                cout << charCount << " " << filename << endl;
            }
            file.close();  // Close the file after processing
        }
    } else if (argc == 2) {  // Case when only option is provided, reading from stdin
        string optionOrFile = argv[1];

        ifstream file(optionOrFile);  // Try to open the argument as a file
        if (file) {
            // If the argument is a valid file, process the file for lines, words, and bytes
            long long lineCount = countLines(file);
            long long wordCount = countWords(file);
            long long byteCount = countBytes(file);

            cout << lineCount << " " << wordCount << " " << byteCount << " " << optionOrFile << endl;
            
        } else {
            // Otherwise, the argument is an option (like "-l" or "-w") for standard input
            string option = argv[1];

            if (option == "-l") {
                long long lineCount = countLines(cin);  // Count lines from stdin
                cout << lineCount << endl;
            } else if (option == "-w") {
                long long wordCount = countWords(cin);  // Count words from stdin
                cout << wordCount << endl;
            } else if (option == "-c") {
                long long byteCount = countBytes(cin);  // Count bytes from stdin
                cout << byteCount << endl;
            } else if (option == "-m") {
                long long charCount = countCharacters(cin);  // Count characters from stdin
                cout << charCount << endl;
            } else {
                cerr << "Unknown option: " << option << endl;
            }
        }
    } else {  // Case when no options are provided
        stringstream buffer;
        buffer << cin.rdbuf();  // Read from standard input into a stringstream
        istream &input = buffer;

        // Count bytes, words, and lines from standard input
        long long byteCount = countBytes(input);
        long long lineCount = countLines(input);
        long long wordCount = countWords(input);

        // Output the results
        cout << lineCount << " " << wordCount << " " << byteCount << endl;
    }

    return 0;
}
