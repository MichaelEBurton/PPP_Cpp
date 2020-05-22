1. Name the four major types of errors and briefly define each one.
+ Compile-time errors: errors found by the compiler; they can either be syntax or type errors.
+ Link-time errors: errors found by the linker when it is trying to combine object files into an executable program.
+ Run-time errors: errors found by checks ina  running program. There are three types 1) errors detected by the computer (hardware) 2) errors detected by a library and 3) errors detected by user code.
+ Logic errors: Maybe the hardest error to find because the code may run but produces an erroneous result



2. What kinds of errors can we ignore in student programs?
+ Errors relating to misbehaving hardware
+ Errors relating to misbehaving systems software
+ Errors which do not terminate the program.


3. What guarantees should every completed project offer?
+ Our software should be correct and reliable.


4. List three approaches we can take to eliminate errors in programs and produce acceptable software?
+ Organize software to minimize errors
+ Elminate most of the rrors we made through debugging and testing
+ Make sure the remaining errors are not serious

5. Why do we hate debugging?
+ Debugging is a tedious task that involves spending lots of time looking through your code for what caused your error. Sometimes finding the bug can be straightforward other times it cold be an arduous task that will eat up much of your valuable time. 
+ We should try to design our programs to minimize the chance for bugs to creep into our program (approach 1 above). This can involve breaking your code up into functions that are no larger than ~ 2 pages (less room for the bugs to hide).


6. What is a syntax error? Give five examples.
+ A syntax error is an error in which the user's code is not well formed to the grammar of the programming language.
```
\\ Five examples of syntax errors
Char alpha = 'a';
char beta = 'b'
vector<int ten(10);
Vector<int> ten(10);
```

7. What is a type error? Give five examples.
+ A type error results from a mismatch in the type you declared (or forgot to declare) for your variables.
```
\\ Five examples of type errors
sotr(v1);
int x1 = square(3,4,5);
int x2 = square("seven");
int x3 = squire(5);
bool x4 = 7;
```
8. What is a linker error? Give three examples.
+ A linker error results when every function in a program is not declared with the same type in every translation unit in which it is used, of every function is not defined exactly once in the program.
```
int area(int length, int width) {/*..*/}
\\ Errors
double area(double x, double y);
int area(char x, int y);
int area(int x, int y, int z);
```

9. What is a logic error? Give three examples.
+ An error where no output is produced or is just wrong.
```
\\ Error

```

10. List four potential sources of program errors discussed in the text.
+ Incomplete programs: some cases haven't been accounted for.
+ Unexpected arguments: A function is given an argument it can't handle.
+ Unexpected input: The program recieves input from the user that it was not expecting.
+ Poor Specification: we did not spend enough time designing our program.


11. How do you know if a result is plausible? What techniques do you have to answer such questions?
+ You can do the math yourself and make an estimated guess on whether the answer you get is reasonable. 

12. Compares and contrast having the caller of a function handle a run-time error vs. the called function's handling the run-time error.
+ By having the called function deal with error handling you eliminate the need to write many lines of code each time you call the function. On the other hand this could slow the performance of your program. On the other hand sometimes you are not able to edit the function's source code and having the caller handle the error is the only thing you can do.


13. Why is using exceptions a better idea than returning an "error value"?
+ It separates the detection of an error from the handling of an error while ensuring the error cannot be ignored. 


14. How do you test if an input operation succeeded?
+ We can test if an input operation succeeded by placing cin in an if statement. If it worked properly (input was read) then it well evaluate to true.

15. Describe the process of how exceptions are thrown and caught?
+ Exepctions are caught using try-catch blocks.
+ You place the code you want to test in a _try_ block, then in separate catch blocks you can catch different errors and tell the program what to do in that case. 

16. Why, with a vector called v, is v[v.size()] a range error? What would be the result of calling this?
+ This is a range error because C++ is a 0-based indexing language so the last possible range value is v.size() - 1.

17. Define _pre-condition_ and _post-condition_; give an example (that is not the area() function from this chapter), preferably a computation that requires a loop.
+ A pre-condition is a requirement on the function's arguments 
+ A post condition is one that check's that the return value is valid.
```
double square_root(double x){
    if(x < 0) error("square_root() pre-condition");
    \\ ... code ...
    if(res < 0) error("square_root() post-condition");
    return res;
}
```

18. When would you not test a pre-condition?
+ It is too complicated to check and would take more work than simply executing the function.

19. When would you not test a post-condition?
+ Probably if it is also too complicated.


20. What are the steps in debugging a program?
+ 1. Get the program to compile  
+ 2. Get the program to link 
+ 3. Get the program to do what it is supposed to do. 


21. Why does commenting help when debugging?
+ It helps you to understand what your code is doing when it cannot be clearly interpreted.

22. How does testing differ from debugging?
+ Testing is a systematic way to search for errors, and it's my understanding that debugging is the process of removing the bugs that cause those errors. 
