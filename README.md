# Programming: Principles and Practice Using C++
This repository's purpose is to host my notes from Bjarne Stroustrup's "Programming: Principles and Practice Using C++" textbook. I am not intending this repository to be helpful to others, so the structure may only suit my needs.

In each folder labeled by the chapter name you can find the following:
+ Attempt of Review Questions
+ Attempt of Drills
+ Terms and their meaning
+ Exercise Attempts

Although I have programmed in Java, Python, R, and SAS before, my programming has been statistical in nature and I have not spent as much time exploring the theory behind programming. By going through this text I hope to cement my understanding of programming fundamentals that I can use in my future career. I settled on this book because I was interested in learning through c++ (no particular reason), and why not learn from the man who invented the language? 

## Resources & General Notes
+ [Book's Website](http://www.stroustrup.com/Programming/)
+ For compiling C++ on my windows machine I have chosen the MINGW compiler
+ For compiling C++ on my linux machine I have yet to choose a compiler

### How to compile on windows
```
g++ file.cpp -o file.exe
```

### How to execute file in git bash

```
./file.exe
```

### Commenting in C++
```
// Single line comment

/*  This
      is
       a
       multiline
       comment
*/
```

### How to load the standard library facilities
```
#include "../../../std_lib_facilities.h"; // path to file
```

### How to compile a file which relies on multiple classes in multiple files
```
#Example from Chapter 9 exercise (Library class)

g++ main.cpp library.cpp book.cpp patron.cpp ../../Code/Chrono.cpp -o main.exe

# not: g++ main.cpp -o main.exe

```

### FLTK
This has probably been the most difficult part of teaching myself C++ using PPP; however, I found a great [tutorial](https://www.youtube.com/watch?v=6sNKtyl4hQM&t=909s) by Kenneth Burchfiel. Although this tutorial is very thorough I did find that the file fltk_jpegd.lib was not in by build library, so I simply excluded this library from the additional dependencies section.
