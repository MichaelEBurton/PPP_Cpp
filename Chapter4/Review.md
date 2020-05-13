1. What is a computation?
+ A computation is the production of output given some input. 
+ Throughout this book we use the term computation to describe computations performed by a computer. For instance, in the drill we wrote a program that computes the smallest, and largest distances, as well as the sum of all distances.


2. What do we mean by inputs and outputs to a computation? Give examples.
+ Inputs are **arguments** that tell the computer what to perform the computation on.
+ Outputs are the **results** of applying the computation to the inputs.


3. What are the three requirements a programmer should keep in mind when expressing computations?
+ Correctness: Is the computation correct?
+ Simpleness: Is this the simplest way we can express the computation?
+ Efficiency: Is our code efficient?


4. What does an expression do?
+ An expression computes a value from a number of operands.


5. What is the difference between a statement and an expression, as described in this chapter?
+ An _expression_ is used when you wish to compute a single value from a set of operands using operators. When you want to produce several values, do things many times, or choose among alternatives you use a _statement_.


6. What is an lvalue? List operators that require an lvalue. Why do these operators, and not the others require an lvalue?
+ An lvalue (left-hand value?) is used when refering to the "box" referred to by the lvalue.
+ pre-increment (++lval), pre-decrement(--lval), assignment and compound assignment require an lvalue.
+ Other operators do not require an lvalue because they do not change the value of a variable unless used in an assignment statement.


7. What is a constant expression?
+ A constant expression is used when we have a constant that we do not want to change accidentally (euler's number, pi, g)
+ In order to use a constant that is not known at compile time you must use const instead of constexpr


8. What is a literal?
+ A literal is a value, unassociated with a variable.
+ For instance if we were to just write int lval = 5; then 5 is a literal integer.


9. What is a symbolic constant and why do we use them?
+ A symbolic constant is a named object which you cannot five a new value after it has been intialized.
+ We don't want to accidentally change the value.


10. Whatr is a magic constant?
+ A magic constant is a non-obvious literal found in the code (outside definitions of symbolic constants)


11. What are some operators that we can use for integers and floating-point values?
+ *, /, +, -, <, <=, >, >=, ==, !=, +=, ++, --


12. What operators can be used on integers but not on floating-point numbers?
+ %

13. What are some operators that can be used for strings?
+ +


14. When would a programmer prefer a switch-statement to an if-statement?
+ When we are comparing a value against several constants.


15. What are some common problems with switch-statements?
+ The value you switch on must be an integer.
+ The value in the case labels must be constant expressions
+ You cannot use the same value for two case labels
+ You can use several cas elabels for a single cae
+ Don't forget to end each case with a break; statement.


16. What is the function of each part of the header line in a for-loop, and what sequence are they executed?
+ Initialize the control variable
+ Define the loop condition
+ Increment operation

17. When should the for-loop be used and when should the while-loop be used?
+ I would say we should use a for-loop when there is a set number of iterations that need to be performed.
+ Use a while-loop when we do not know how many iterations are required but know another stopping criteria.


18. How do you print the numeric value of a char?
+ To print the numeric value of a char you can print int(char) to the standard output.


19. Describe what the line char foo(int x) means in a function definition?
+ Char is the return type
+ foo is the identifier
+ int x is the parameter list


20. When should you define a separate function for part of a program? List reasons.
+ Logically separate the computation
+ Make the program text clearer
+ Reuse the same line of code
+ Ease testing.


21. What can you do to an int that you cannot do to a string?
+ Most operations


22. What can you do to a string that you cannot do to an int?
+ += (add to end)


23. What is the index of the third element of a vector?
+ The index is 2 (0, 1, 2)


24. How do you write a for-loop that prints every element of a vector?
```
for(int i = 0; i<v.size();++i){
    cout<<v[i]<<"\n";          
}
```


25. What does vector<char>alphabet(26); do?
+ This creates a character vector with a length of 26.
+ Each entry is intialized to ""


26. Describe what push_back() does to a vector?
+ push_back() pushes the argument entered to the back of the vector


27. What does vector's member size() do?
+ size() returns the length of the vector.


28. What makes vector so popular/useful?
+ Often we use a collection of data not just a singular value.


29. How do you sort the elements of a vector?
+ We can use the standard library's sort() function!