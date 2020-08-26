1. When dealing with the input and output, how is the variety of devices dealt with in most modern computers?
  - Because of the ever growing number of input/output devices modern computers use device drivers which tell them how to interact with these devices.


2. What, fundamentally, does an istream do?
    - An istream (input streams) turns a sequence of characters into values of various types.


3. What, fundamentally, does an ostream do?
    - An ostream (output stream) turns values of various types into a sequence of characters.


4. What, fundamentally, is a file?
    - A file, fundamentally, is a sequence of bytes numbered from 0 upward.


5. What is a file format?
    - A file format is a set of rules that determines what the bytes mean.


6. Name four different types of devices that can require I/O for a program.
    1. Streams of data items (recording devices, network connections, display devices...)
    2. Interactions with a user and a keyboard
    3. Fuel injector
    4. Digital Camera



7. What are the four steps for reading a file?
    1. Know the file's name.
    2. Open the file.
    3. Read in the characters.
    4. Close it (usually implicit)


8. What are the four steps for writing a file?
    1. Name it.
    2. Open the file.
    3. Write out our objects.
    4. Close it (usually implicit)


9. Name and define the four stream states.
    1. good()
        > Indicates the operations succeeded.
    2. eof()
        > We hit the end of input ("end of file")
    3. fail()
        > Something unexpected happened (e.g., we looked for a digit and found x)
    4. bad()
        > Something unexpected and serious happened (e.g., a disk read error)



10. Discuss how the following input problems can be resolved:
  a. The user typing an out-of-range value.
    >  We can use a while loop and check that the value is in our range. If the value is out of range then we can print a statement asking the user to try again.

  b. Getting no value (end of file).
    > Just stop reading input.

  c. The user typing something of the wrong type.
    > Let them try again.


11. In what way is input usually harder than output?
  - Input is much more difficult since it can come in a variety of shapes and forms that one might not expect. That being said you need to write a program that can account for this. Output on the other hand isn't as difficult because you are specifying the format (you have the control).


12. In what way is output usually harder than input?
  - Deciding the format.


13. Why do we (often) want to separate input and output from computation?
  - It makes for cleaner code and less area for bugs to hide in.


14. What are the two most common uses of the istream member function clear()?
  - clear() is used to make the input stream ready to read more values.
  - It can also be used to change the stream state to fail.


15. What are the usual function declarations for << and >> for a user-defined type x?
```
ostream& operator<<(ostream& os, Type& t);  // output operator

istream& operator>>(istream& is, Type & t); // input operator
```
