1. What is the difference between a declaration and a defintion?
    + A _declaration_ is a a statement that introduces a name into a scope.
      + You specify a type for what is named, and may optionally specify an intializer
      + A declaration is required before you can use a name in a program
      + You may declare something as often as you want as long as you're consistent.
      ```
        int a = 7;
        double sqrt(double);  //declared but not defined
        vector<Token>v;
      ```
    + A _defintion_ is a declaration that fully specifies the entity declared.
      + Required for programs to link?
      + Specifies exactly what a name refers to, and sets aside memory for your object.
      ```
        double sqrt(double) {/*...*/} //defintion (also a delcaration)
      ```

2. How do we syntactically distinguish between a function declaration and a function definition?
  ```
  double sqrt(double);          //Function declaration

  double sqrt(double) {/*...*/} //Function definition
  ```

3. How do we syntacticaly distinguish between a variable declaration and a variable defintion?
```
extern int a; //declaration

int a;        //defintion 

int a = 7;    //also a defintion
```

4. Why can't you use the functions in the calculator program from chapter 6 without declaring them first?
  + Because a declaration is required before using a name in a program we must declare at least one of our functions before defining the rest.
  + In our case we needed to define expression() before we use primary() since its defintion calls expression().


5. Is int a; a definiton or just a declaration?
  + It is a definition because we specify the type integer and the computer sets aside memory(32 bits) for the variable a. 
  + To specify a declration for a variable we would use the extern keyword.

6. Why is it a good idea to intialize variables as they are delcared?
  + It's a good idea because it can help avoid obscure bugs.
  + As shown in the text if we declare an integer x, then compare it to z (z > x) we have no idea how this will react (undefined behavior). 

7. What can function delcaration consist of?
  + A function declaration consists of specifying a return type, arguments if the function requires them, and ends in a semicolon.
    + It is not necessary to name arguments in a function declaration, but may be helpful for writing good comments.

8. What good does indentation do?
  + Good indentation can improve the readability of your code; you can see what blocks of code go together.
  + Without it nested structures become unreadable.

9. What are header files used for?
  + Header files are used to manage a collection of declarations that we intend to use in our source file.
  + They allow our program to feel less cluttered, in my opinion.

10. What is the scope of a declaration?
  + A _scope_ is a region of program text in which a name is valid.


11. What kinds of scope are there? Give an example of each?
  + _global scope_: the area of text outside any other scope.
  + _namespace scope_: a named scope nested in the global scope or in another namespace.
  + _class scope_: the area of text within a class.
  + _local scope_: between {...} braces of a block or in a function argument list.
  + _statement scope_: e.g. in a for-statement.

  ```
  void f(int x)        // f is global; x is local to f
  {
      int z = x + 7;   // z is local to f
  }

  
  namespace TextLib {
      class Text {/*...*/};   //namespace scope
      class Glyph {/*...*/};
      class Line {/*...*/};
      //...
  }
  
  TextLib::Text();


  class My_vecotr {
      vector<int> v;   // v is in class scope
  };

  for(int i = 0; i < 9; ++i){
      cout<<i <<'\n';   //statment scope
  }
  ```

12. What is the difference between a class scope and local scope?
  + A name in a class scope can be used anywhere in the class, but a variable defined in one of the member functions would be local to that function and cannot be used outside its local scope.


13. Why should a programmer minimize the number of global variables?
  + The main reason is it is hard to kow which functons modify them, especially in larger programs.
  

14. What is the difference between pass-by-value and pass-by-reference?
  + Pass-by-value just lets the function use the value of whatever you are passing it.
  + Pass-by-reference allows the function to access the object itself, so it could make changes to it.
    + We explored this in drill2 of this chapter.
    + Passing a reference is also advantageous because it does not create a copy of what we reference (passing a valu does)


15. What is the difference between pass-by-reference and pass-by-const-reference?
  + pass-by-reference allows you to reference an object and make changes to it.
  + pass-by-const-reference allows you to reference an object and you are not allowed to make changes to it.


16. What is swap()?
  + A function that swaps the values of its arguments.


17. Would you ever define a function with a vector\<double\>-by-value parameter?
  + You can but if the vector is very large it can take a long time for your program to execute.


18. Give an example of undefined order of evaluation. Why can undefined order of evaluation be a problem?
```
v[i] = ++i;
v[++i] = i;
int x = ++i + ++i;
```
  + Undefined order of evaluation can be a problem because we read/write a variable twice in our expression. We do not know whether to evaluate the i in v[i] before or after we increment it.


19. What do x&&y and x||y, respectively mean?
  + && Is a logical and, it evaluates to true if x and y are both true.
  + || is a logical or, it evaluates to true if one argument is true.


20. Which of the following is standard-confroming C++: functions within function, functions within classes, classes within classes, classes within functions?
  + Functions within functions.


21. What goes into an activation record?
  + Parameters, local variables, and implementation stuff.


22. What is a call stack and why do we need one?
  + A call stack is a stack of activation records of functions we have called. 
  + Each time a function is called it grows by one record.
  + When a function returns it removes a record.
  + We need one because we need to keep track of a function's call in case we call it multiple times?


23. What is the purpose of a namespace?
  + A namespace allows you to avoid clashes in names by using fully qualified names.


24. How does a namespace differ from a class?
  + Unlike a class, they allow us to organize classes, functions, data, and types into an identifiable and named part of a program without defining a type. 

25. What is a using declaration?
  + A using declaration says that when we refer to a name we are referring to that name from a given namespace. 
    + i.e. using std::string

26. Why should you avoid using directives in a header?
  + You can start to lose track of where a name came from leading to clashes.


27. What is namespace std?
  + The standard library!