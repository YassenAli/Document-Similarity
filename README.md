# Document Similarity

This repository contains a C++ program that demonstrates document similarity using sets and vectors. The program reads text from a file and calculates similarity coefficients between documents based on common words.

## Files

- `CMakeLists.txt`: CMake configuration file for building the project.
- `cmake-build-debug/`: Folder containing build artifacts (generated by CMake).
- `text.txt`: Example input file used by the main program (`Document Similarity.cpp`).
- `Document Similarity.cpp`: C++ source code file implementing the document similarity functionality.

## Description

The main program, `Document Similarity.cpp`, utilizes sets and vectors to represent and process strings from a text file (`text.txt`). It calculates the similarity between different sets of strings using the binary cosine coefficient. Here are some key functionalities of the program:

- **StringSet Class**: Represents a set of strings with methods to add, remove, clear, print, and calculate similarity.
- **Operators Overloading**: Overloaded operators `+` for set union and `*` for set intersection.
- **Similarity Calculation**: Computes similarity between two StringSet objects based on common elements.

## Example Output
```plaintext
Please input the file name: text.txt

Set 1 is : i love chocolate i love ice cream i love milk there are delicious 

Set 2 is : chocolate ice cream and chocolate bars are delicious 

Set 3 is set 1 + set 2 : i love chocolate i love ice cream i love milk there are delicious chocolate ice cream and chocolate bars are 

Intersection set between set 1 and set 2 is : chocolate delicious ice cream 

Similarity between set 1 and set 2 is : 0.516398

The size of set 2 is 10
String (good) was added to set 2.
String (good) was removed from set 2.

Now, after clear the second set, the size of it is 0
```

#### This output corresponds to the following actions in the program:

1. Sets ss1 and ss2 are created from text.txt and a predefined string, respectively.
2. Set ss3 is created as the union of sets ss1 and ss2.
3. Set ss4 is created as the intersection of sets ss1 and ss2.
4. Similarity coefficient between sets ss1 and ss2 is calculated.
5. Operations to add and remove a word (good) from ss2.
6. Set ss2 is cleared, and its size is displayed.

This output demonstrates how the program processes strings from files and calculates similarity coefficients based on common words using set operations.

## Usage

To run the program:
1. Compile `Document Similarity.cpp` using a C++ compiler.
2. Ensure `text.txt` is present in the same directory.
3. Execute the compiled binary.

Example usage:
```bash
$ g++ Document\ Similarity.cpp -o document_similarity
$ ./document_similarity
```

## Contact

For any questions or suggestions regarding this repository, feel free to [open an issue](https://github.com/YassenAli/Document-Similarity/issues) on GitHub.
