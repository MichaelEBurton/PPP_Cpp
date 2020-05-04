1. What is meant by the term prompt?
+ A prompt is a message that encourages the user to take action.

2. Which operator do you use to read into a variable?
+ To read into a variable you must use the input operator: >>

3. If you want the user to input an integer value into your program for a variable named number, what are two lines of code you could write to ask the user to do it and to input the value into your program?
```
cout<<"Please enter an integer\n";
int number;
cin>>number;
```

4. What is \n called and what purpose does it serve?
+ This is a newline character and it creates a newline after the preceding text.

5. What terminates input into a string?
+ A newline entered by the user (the Enter key is hit)

6. What terminates input into an integer?
+ Same as above?

7. How would you write the following as a single line of code?
```
cout<<"Hello,";
cout<<first_name;
cout<<"!\n";

// Solution:
cout<<"Hello,"<<first_name<<"!\n";
```
8. What is an object?
+ An _object_ is a region of memory that holds a value of a given type.

9. What is a literal?
+ A _literal_ is used to produce a literal string, so if we want to return the string "Hey whats up" you encapsulate it in quotations otherwise the program will look for the objects hey, whats, and up.
+ Wikipedia defines a literal as notation for representing a fixed value in source code.

10. What kind of literals are there?
+ Based of the wikipedia article I suppose the following can be used as literals: 
+ int
+ double 
+ char
+ string 
+ bool 

11. What is a variable?
+ A variable is a named object.

12. What are typical sizes for a char, an int, and a double?
+ char: 1 byte (8 bits)
+ int: 4 bytes (32 bits)
+ double: 8 bytes (64 bits)

13. What measures do we use for the size of small entities in memory, such as ints and strings?
+ The small entities in memory are bits.

14. What is the difference between = and ==?
+ = is used for assignment
+ == is used to check a condition (is a equal to b)

15. What is a definition? 
+ A definiton is a declaration that sets aside memory for an object.

16. What is an intialization and how does it differ from an assignment?
+ Initialization is when you give a variable its initial value.
+ Assignment is when you give a variable a new value

17. What is a string concatenation and how do you make it work in C++?
+ String concatenation is when you coalesce two strings together.
+ To concatenate in C++ you can use the + operator.

18. Which of the following are legal names in C++? If a name is not legal, why not?
+ Legal
    - This_little_pig
    - MineMineMine
    - number
+ Illegal
    - latest thing // spaces are not allowed
    - This_1_is fine // spaces are not allowed
    - the_$12_method // only characters, underscores, and digits are allowed.
    - 2_For_1_special // must begin with a character
    - _this_is_ok // must begin with a character
    - correct? // cannot include ?


19. Give five examples of legal names that you shouldn't use because they are likely to cause confusion.
+ Hell0, h3110, x1, X2, X1

20. What are some good rules for choosing names?
+ Do not use a name that is the same as a keyword
+ Avoid names that are easy to mistype, misread, or confuse.
+ Don't use overly long names
+ Avoid acronyms

21. What is type safety and why is it important?
+ Type safety is the idea that objects are used only according to the rules for their type.
+ It's important to know about type safety (in my opinion) because it will help us understand when something goes wrong; for instance when narrowing occurs.

22. Why can conversion from double to int be a bad thing?
+ It truncates the double value, thus effectively rounding the double down. This can cause a loss of information.

23. Define a rule to help decide if a conversion from one type to another is safe or unsafe.
+ If the first letter of the type of the variable you are converting is less than (alphabetically) the first letter of the type of what you are converting to then this is a safe conversion. This has the exception of int to double conversion, and double should not be converted to any other type.
+ Safe
    - bool to char
    - bool to int
    - bool to double
    - char to int
    - char to double
    - int to double