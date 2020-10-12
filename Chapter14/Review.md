1. What is an application domain?
  + An application domain is an area in which we wish our program to be used.


2. What are ideals for naming?
  + Logically identical operations have the same name.
  

3. What can we name?
  + Not sure what this question is getting at? We can name practically everything objects, functions, classes.


4. What services does a Shape offer?
  + Ties graphical objects to our Window abstraction.
  + Deals with color, and style used to draw lines.
  + Holds a sequence of points and has a notion of how to draw them.
  + It's a framework for other shapes.


5. How does an abstract class differ from a class that is not abstract?
  + An abstract class is only allowed to be used as a base class. 
  + It represents a general case, but does not go into specific details. (ex: A shape is an abstract concepts, and a circle is a concrete example of a shape.)


6. How can you make a class abstract?
  + You can make a shape abstract by making its constructor **protected**, or including a **pure virtual functions**.


7. What is controlled by access control?
  + What can read/write data members, access member functions.


8. What good can it do to make a data member private?
  + This can ensure that only a class can alter its data members; that is the user cannot accidentally alter the data members directly).


9. What is a virtual function and how does it differ from a non-virtual function?
  + A virtual function is used to indicate that a derive class can define their own function to override the base class' function.


10. What is a base class?
  + A class that we wish to represent a more basic object that other objects can be built off of.

 
11. What makes a class derived?
  + It has a base class specified after the derived class name.


12. What do we mean by object layout?
  + We refer to how onjects are laid out in memory.
  

13. What can you do to make a class easier to test?
  + Use the same argument names and order when you have functions of the same name in different classes.

14. What is an inheritance diagram?
  + It shows how classes are related to others. (which classes are derived from others)


15. What is the difference between a protected member and a private one?
  + A protected member can only be called by a member of the class in which it is declared, and members of classes derived from that.


16. What members of a class can be accessed from a class derived from it?
  + Public and Protected members.


17. How does a pure virtual function differ from other virtual functions?
  + Pure virtual functions must be overridden in derived classes otherwise the derived class is an abstract class.


18. Why would you make a member function virtual?
  + When you have derived classes that need to use the same functionality as the base class but with slight tweaks.


19. Why would you make a virtual member function pure?
  + In the instance we have a class with no data members, that is, the class acts soley as an interface.


20. What does overriding mean?
  + A derived function overrides base functions indicates when an instance of the derived class is called we use the overridden function.


21. How does interface inheritance differ from implementation inheritance?
  + Interface implementation says that an object of a derived class can be used as an object of the base class.
  + Implementation inheritance says we can take advantage of the facilities offered by shape.


22. What is object-oriented programming?
  + The combination of inheritance, run-time polymorphism, and encapsulation. 