1. What are the two parts of a class, as described in the chapter?
    + Interface
    + Implementation


2. What is the difference between the interface and the implementation in a class?
    + The _interface_ is the part of the class declaration that its users access directly.
    + The _implementation_ is the part of the class declaration that its users access indirectly through the interface.


3. What are the limitiations and problems of the original Date struct that is created in the chapter?
    + The original date struct is quite simple, however, this simplicity comes at the cost of a poor interface.
    + The data members have to be accessed using the member object dot notation (this is the only way to read and write them), and helper functions for this struct our global helper functions.


4. Why is a constructor used for the Date type instead of an init_day() function?
    + A constructor is used instead of an init_day() function so that the computer doesn't produce garbage; let me elaborate.
      + If we forgot to initialize an object of type Date and then called add_day() what would we expect the results to be? It wouldn't be anything coherent. 
      + By including a constructor if we declare a Date object but do not initalize it then an error will be thrown.


5. What is an invariant? Give examples.
    + An invariant is a rule for what constitutes a valid value.
    + An invariant of a date (simply put) is that it must be a date in the past, present, or future.

6. When should functions be put in the class definition, and when should they be defined outside the class? Why?
    + A function should be put in the class definition when you need the performance boost of _inlining_ functions.
    + Otherwise the functions can take up to much space and make it difficult for users to read the interface.
    + Additionally, if we make a change to an inlined function then all cases of the class will need to be recompiled.


7. When should operator overloading be used in a program? Give a list of operators that you might want to overload (each with a reason).
    + You should use operator overloading when you want to provide conventional notation for a type we design.
    + Operators you may want to overload
      + \+ 
      + \-
      + \*
      + \
      + +=
      + -=
      + <<
      + \>>
      + see page 323 for more


8. Why should the public interface to a class be as small as possible?
    + We want the public interface to be small so that it is easy to use and easy to remember, and the implementer doesn't waste time implementing unecessary features.


9. What does adding const to a member function do?
    + Adding const to a member function tells the fuction that it is not allowed to modify the object.

10. Why are "helper functions" best placed outside the class defintion?
    + If the function can be implemented as a freestanding function than we put it outside the class definition so if it has a bug it cannot corrupt the object by accidentally modifying it.