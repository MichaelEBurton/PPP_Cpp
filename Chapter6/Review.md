1. What do we mean by "Programming is Understanding"?
+ When we say "Programming is understanding" we are saying that in order to fully express our ideas (programs), we must first understand what we are trying to solve.
+ This is similar to (statistical) consulting where we first need to spend time gathering our clients basic requirements, create a simple analysis to see if we are on the right track, and then create a more advanced program.


2. The chapter details the creation of a calculator program. Write a short analysis of what the calculator should be able to do.
+ Our calculator program should be able to evaluate complex expressions consiting of parentheses, addition, subtraction, multiplication, and division. Our calculator should follow the conventional PEMDAS order of operations. Expressions should be read in, evaluated and results should be printed to the standard output until the user enters an exit character; thus terminating the program. All expressions should have an end of expression character.


3. How do you break a problem up into smaller manageable parts?
+ You can break a program into smaller parts by using existing code libraries, creating functions to handle repetive tasks, and creating user-defined types using class statements.
+ To make our calculator program manageable we created the Token and Token_stream classes, and then separate functions for implementing a grammar.


4. Why is creating a small, limited version of a program a good idea?
+ It helps show problems that exist in our understanding, ideas, and tools.
    - Did we formulate the problem correctly?
    - Do we have the right ideas to solve it?
    - Are we using the best tools?
+ It also allows us to determine if the problem statement needs changing; maybe we made it too complicated?


5. Why is feature creep a bad idea?
+ Feature creep can make a project seem unmanageable and may wear out your patience.
+ It is best to just create a simple program, implementing the essential features only. Once this is up and running, you can begin adding more ambitious features.


6. What are the three main phases of software development?
+ Analysis: Figure out what should be done and write a description of your understanding of that.
+ Design: Create an overall structure for the system, deciding which parts the implementation should have and how those parts should communicate.
+ Implementation: Write the code, debug it, and test that it actually does what is is supposed to do.


7. What is a "use case"?
+ A _use case_ is a sketch of how we expect a user to use our program. For example when sketching out the calculator program we had to make the decision on how we prompt the user for an expression, and return the result; do we output "Expression:" or "Please enter an expression followed by a newline.


8. What is the purpose of testing?
+ It's important to make sure that our software works as it should. 
+ Testing can accomplish this by identifying bugs for us to fix.


9. According to the outline in the chapter, describe the difference between a Term, an Expression, a Number, and a Primary.
+ An expression either is a Term or ends with a Term.
+ A Term either is a Primary or ends with a Primary.
+ A Primary starts with a '(' or is a number.
+ A number is a floating-point number.


10. In the chapter, an input was broken down into its component Terms, Expressions, Primarys, and Numbers. Do this for (17+4)/(5-1)
+ 17 is a number which from the logic followed in the book is a term, which is an expression; the same is true for 4. Since 17 is an expression which is followed by '+' and 4 which is a term, the whole thing is an expression. An expression contained within '(' and ')' is a primary.
+ Similary (5 - 1) is also a primary.
+ Since a primary is also a term, a term followed by '/' and a primary is a term. Hence (17 +4) / (5 - 1) is a term which is an expresion!


11. Why does the program not have a function called number()?
+ number() is not a necessary function since C++ already has an understanding of what a number is?
  - Maybe since this is implemented in the token stream class which identifies a number as having a value '8'?

12. What is a token?
+ A token is a sequence of characters that represents something we consider a unit, such as a number or an operator.


13. What is a grammar? A grammar rule?
+ A grammar defines the syntax of our input. A grammar rule defines how a stream of tokens should be read.


14. What is a class? What do we use classes for?
+ A class is simply a user defined type.
+ It indicates that a member with zero or more members is being defined. 


15. How can we provide a default value for a member of a class?
+ I suppose you could just define it within the class definition.


16. In the expression function, why is the default for the switch-statement to "put back" the token?
+ If the token is neither a '+' or a '-' then we have arrived at the final solution and return whatever token we've arrived at to the token stream. It might be important later?
+ **REVIEW** this!

17. What is "look-ahead"?
+ Look-ahead is to look at the future tokens in a token stream?


18. What does putback() do and why is it useful?
+ Putback returns an object back to the stream it came from.


19. Why is the remainder (modulus) operation, %, difficult to implement in the term()?
+ It is difficult to implement because we would need to ensure it was being used only with integers.


20. What do we use the two data members of the Token class for?
+ We use kind to determine what token we are dealing with ';', '+',...'/', etc, or '8'.
+ Value holds the value of the token; in the case '8' it is a number.


21. Why do we (sometimes) split a class' members into **private** and **public** members?
+ We use private when we do not want the user to see all the details of our implementation.
+ Public is where we store what we want the user to use.


22. What happens in the Token_stream class when there is a token in the buffer and the get() function is called?
+ If the get() function is called while the buffer is full, the buffer is returned while full is set to false.


23. Why were the ';' and 'q' characters added to the switch-statement in the get() function of the Token_stream class?
+ They were added because we defined both as key features in our program.
  - ';' indicates that the expression has ended.
  - 'q' indicates we wouldl ike to exit our program. 


24. When should we start testing our program?
+ We should test our program after our initial minimal working program?


25. What is a "user-defined type"? Why would we want one?
+ A user-defined type is one you specify in  a class statement.
+ It can be useful when we want to package code that will be used many times, for instance when we implement the Token and Token_stream classes.


26. What is the interface to a C++ "user-defined type"?
+ A class


27. Why do we want to rely on libraries of code?
+ Because we don't want to reinvent the wheel everytime we code.