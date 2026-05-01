# String_from_scratch_c++
## Overview:

This project demonstrates a **custom implementation of a String class in C++**, built entirely from scratch without relying on `std::string`.  
It showcases fundamental concepts of **object-oriented programming, operator overloading, and memory management**.

## 📂 Folder Structure

String_from_scratch_c-/
- String.h          # Header file (class definition)
- String.cpp        # Implementation file
- main.cpp          # Example usage
- .gitignore
- .gitattributes


## ⚙️ Build & Run Instructions

### 🔹 On Windows (Visual Studio)
1. Open the project in Visual Studio.
2. Add `String.cpp` and `String.h` to your solution.
3. Create a `main.cpp` file with sample usage.
4. Press **Ctrl+F5** to build and run.

### 🔹 On Linux/Mac (g++)
```
g++ String.cpp main.cpp -o string_app
./string_app
```

## 🧩 Example Usage
String s1("Hello");
String s2("World");

String s3 = s1 + " " + s2;
cout << s3 << endl;  // Output: Hello World

cout << "Length: " << s3.length() << endl;

## 🚀 Features Implemented
- Constructors & Destructor
- Copy and Assignment operators
- Concatenation (`+`)
- Comparison (`==`, `<`, `>`)
- Length function
- Substring extraction
- Character access (`[]`)
- Find string
- Replace string
- Typecast operators(long long int , double)
- Reverse string
- Insert into a string
- Trim from left/right
- Stream insertion and extraction operators (`<<` and `>>`) 

## 📌 Future Improvements
- Add unit tests for all functions
- Provide benchmarks vs `std::string`.


