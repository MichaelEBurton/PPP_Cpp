1. What is the purpose of working on the program after the first version works? Give a list of reasons.
  + After you get the first version of a program "that's where the fun begins." You can start to experiment with adding new features

2. Why does 1+2; q typed into the calculator not quit after it receives an error?
  + I am unsure, my version of calculator quits after entering this and no errors are thrown.

3. Why did we choose to make a constant character called number?
  + We make a constant called number so that we can define the character indicating that a token is a number.
  + This allows more flexibility in our programming if we want to change the character later we just change it in the constant definition.

4. We split main() into two separate functions. What does the new function do and why did we split main()?
  + We split main into two functions because ideally each fragment of code should only be responsible for one action. This allows the code to be more easily read.
  + The new function handles the calculation loop.

5. Why do we split code into multiple functions? State principles.
  + Functions should identify logically separate parts of code.
  + A function should perform a single logical action

6. What is the purpose of commenting and how should it be done?
  + Comments are for things that code expresses poorly
  + Sometimes we come back to code and need to be reminded what are code does, it also helps someone who has never seen the code before.
  + Comments should be:
    + Valid (make sure if you changed something that you change the comments)
    + Adequate for a reader
    + Not so verbose

7. What does narrow_cast do?
  + It throws an error if an assignment or initialization leads to a change of value.

8. What is the use of symbolic constants?
  + They make code easier to read.
  + If we want to change a constant later on it is simple.

9. Why do we care about code layout?
  + Code that is hard to read (has a poor layout) has more areas for bugs to hide in.

10. How do we handle % (remainder) of floating-point numbers?
  + We can either throw an error saying the operation cannot be performed or we can use the fmod() function.

11. What does is_declared() do and how does it work?
  + is_declared checks to see if a variable has previously been declared.
  + It searches the var_table for a variable name equal to the same string being passed to it. If it finds one it returns true.

12. The input representation for let is more than one character. How is it accepted as a single token in the modified code?
  + If the program finds a string "let" than it returns a token with kind = 'L' indicating a declaration.

13. What are the rules for what names can and cannot be in the calculator program?
  + The first letter must be a character.
  + The remaining letters must be a character or digit.

14. Why is it a good idea to build a program incrementally?
  + Instead of testing one big program we can build slowly, then test after each new feature is added.
  + This will allow us to find bugs more easily.

15. When do you start to test?
  + After your have a program that "basically works."

16. When do you start to retest?
  + I think you want to retest the program everytime you make a change to the program, especially when adding a new feature.

17. How do you decide what should be a separate function?
  + If the code contains more than one logically separate idea, and would improve the readability of the program.

18. How do you choose names for variables and functions? List possible reasons.
  + The names should make sense, but not be too verbose.
  + Names should not be really similar to other names in your program otherwise you may mistype and the compiler won't catch it.

19. Why do you add comments?
  + So you and others can more easily read your code.

20. What should be in comments and what should not?
  + Descriptions of code that are best expressed in words.
  + If it's better expressed in code don't comment on it. e.g. Don't put a comment on what 2 + 3; does.

21. When do we consider a program finished?
  + I don't know if a program is ever truly finished, but if it is it must be after intensive testing.