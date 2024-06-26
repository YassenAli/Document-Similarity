// File: A3_S1_SheetPb2_20220381.cpp
// Purpose: Document Similarity.
// Author: Yassin Ali Mamdouh
// Section: S1
// ID: 20220381
// TA: Khaled Ebrahim
// Date: 4 Dec 2023

#include <bits/stdc++.h> // Include all standard libraries

using namespace std;

class StringSet {
private:
    set<string> strings; // set to store unique strings
    vector<string> VectorOfStrings; // Vector to store strings
    string s;
public:
    StringSet(const string &filename); // Constructor that takes a filename as input

    StringSet(string s, const string &str); // Constructor that takes a string as input

    string add_string(const string &word); // Function to add a string to the set

    string remove_string(const string &word); // Function to remove a string from the set

    void clear(); // Function to clear the set

    int size(); // Function to get the size of the set

    void print(); // Function to print all strings in the vector
    void print_intersection(); // Function to print all strings in the set

    StringSet operator+(const StringSet &other); // Overload operator + to add set to another set

    StringSet operator*(const StringSet &other); // Overload operator * to get the intersection of two sets

    double similarity(StringSet other); // Function to calculate the similarity between two sets
};

// Helper function to process a string: remove punctuation and convert to lower case
string EditingWord(const string &word) {
    string NewWord;
    for (char c: word) {
        if (!ispunct(c)) {
            NewWord += ::tolower(c);
        }
    }
    return NewWord;
}

// Constructor that takes a file name
StringSet::StringSet(const string &filename) {
    ifstream file(filename);
    string word;
    while (file >> word) {
        VectorOfStrings.push_back(EditingWord(word)); // Add each word to the vector
        strings.insert(EditingWord(word)); // Add each word to the set
    }
    file.close(); // Close the file
}

// Constructor that takes a string
StringSet::StringSet(string s, const string &str) {
    s = this->s;
    istringstream iss(str);
    string token;
    while (iss >> token) {
        VectorOfStrings.push_back(EditingWord(token)); // Add each word to the vector
        strings.insert(EditingWord(token)); // Add each word to the set
    }
}

// Output all strings in vector
void StringSet::print() {
    for (const auto &i: VectorOfStrings)
        cout << i << ' '; // Print each string in vector
    cout << endl;
}

// Output all strings in set
void StringSet::print_intersection(){
    for (const auto &i: strings)
        cout << i << ' '; // Print each string in set
    cout << endl;
}

// Number Of Strings
int StringSet::size() {
    return VectorOfStrings.size(); // Return the size of the vector
}

// Make the set empty
void StringSet::clear() {
    strings.clear(); // Clear the set
    VectorOfStrings.clear(); // Clear the vector
}

// Remove string from the set
string StringSet::remove_string(const string &word) {
    strings.erase(EditingWord(word)); // Remove the word from the set
    remove(VectorOfStrings.begin(), VectorOfStrings.end(), EditingWord(word)); // Remove the word from the vector
    return word;
}

// Add string to the set
string StringSet::add_string(const string &word) {
    VectorOfStrings.push_back(EditingWord(word)); // Add the word to the vector
    strings.insert(EditingWord(word)); // Add the word to the set
    return word;
}

// Overload operator + to add set to another set
StringSet StringSet::operator+(const StringSet &other) {
    StringSet result(*this);
    result.strings.insert(other.strings.begin(), other.strings.end()); // Add the other set to the current set
    result.VectorOfStrings.insert(result.VectorOfStrings.end(), other.VectorOfStrings.begin(), other.VectorOfStrings.end()); // Add the other vector to the current vector
    return result;
}

// Overload operator * to store intersection between two sets in intersection set
StringSet StringSet::operator*(const StringSet &other) {
    StringSet intersection(*this);
    intersection.clear(); // Clear the intersection set
    set_intersection(strings.begin(), strings.end(), other.strings.begin(), other.strings.end(),
                     inserter(intersection.strings, intersection.strings.begin())); // Get the intersection of the two sets
    return intersection;
}

// Similarity is measured by binary cosine coefficient.
// The coefficient is a value between 0 and 1,
// where 1 indicates that the query (or document) is very similar to the document and 0 indicates that the query has no keywords in common with the document.
double StringSet::similarity(StringSet other) {
    StringSet intersection = *this * other; // Get the intersection of the two sets
    double num_common = intersection.strings.size(); // Get the number of common elements
    return num_common / (sqrt(this->strings.size()) * sqrt(other.strings.size())); // Calculate the similarity
}

int main() {
    string fileName;
    cout << "Please input the file name: ";
    cin >> fileName;
    ifstream file(fileName);
    if (file.fail()) {
        cout << '\n' << "Error, cannot open the file: " << fileName << endl;
        return 0;
    }

    StringSet ss1(fileName); // Create a StringSet from a file
    StringSet ss2("s", "Chocolate ice cream, chocolate milk, and chocolate bars are delicious."); // Create a StringSet from a string
    StringSet ss3(ss1 + ss2); // Create a StringSet that is the union of set 1 and set 2

    cout << "Set 1 is : ";
    ss1.print();

    cout << "\n\nSet 2 is : ";
    ss2.print();

    cout << "\n\nSet 3 is set 1 + set 2 : ";
    ss3.print();

    StringSet ss4(ss1 * ss2);
    cout << "\n\nIntersection set between set 1 and set 2 is : ";
    ss4.print_intersection(); // Print the intersection of set 1 and set 2

    cout << "\n\nSimilarity between set 1 and set 2 is : " << ss1.similarity(ss2) << endl; // Print the similarity between ss1 and ss2

    cout << "\n\nThe size of set 2 is " << ss2.size() << endl; // Print the size of set 2

    string word = "good";
    cout << "String (" << ss2.add_string(word) << ") was added to set 2.\n";
    cout << "String (" << ss2.remove_string(word) << ") was removed from set 2.\n";

    ss2.clear();
    cout << "\nNow, after clear the second set, the size of it is " << ss2.size() << endl;

    return 0;
}
