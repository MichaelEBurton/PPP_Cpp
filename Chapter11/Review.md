1. Why is I/O tricky for a programmer?
  - I/O is trixky because programmers we need to balance program complexity with accomodation of users' personal tastes. We would love to treat everything uniformly, but know humans have strong preferences.
  - ex: an accountant may have a different number of decimal places required than a scientist.


2. What does the notation <<\hex do?
  - This implies that for all the following integers we wish to output them in hexadecimal form.


3. What are hexadecimal numbers used for in computer science? Why?
  - Hexadecimal is popular for outputting hardware-related information since a hexadecimal digit exactly represents a 4-bit value.


4. Name some of the options you may want to implement for formatting integer output?
  - hex
  - oct
  - dec
  - showbase
  - noshowbase


5. What is a manipulator?
  - A manipulator is a term used to change the behavior of a stream.


6. What is the prefix for decimal? For octal? For hexadecimal?
  - Nothing for decimal.
  - 0 for octal.
  - 0x for hexadecimal.



7. What is the default output format for floating-point values?
  - The default is six total digits (_defaultfloat_).


8. What is a field?
  - A field controls how much space an integer value takes up on output.


9. Explain what setprecision() and setw() do.
  - setprecision() allows you to chose how many digits you want to include.
  - setw() allows you to set the field width.


10. What is the purpose of file open modes?
  - File open modes are useful when we want to do more with a file than read or write to a file.


11. Which of the following manipulators does not "stick": hex, scientific, setprecision(), showbase, setw()?
  - setw() do not stick.


12. What is the difference between character I/O and binary I/O?
  - Character I/O takes a sequence of characters and converts them into objects of a specified type, and vice versa.
  - Binary I/O simply copies bytes to and from files.


13. Give an exampled of when it would probably be beneficial to use a binary file instead of a text file?
  - When we are not working with something that has no reasonable character representation; for example, images, videos, and music files.


14. Give two examples where a stringstream can be useful.
  - When we want to process our text; remove undesirable characters from our input. 
  - Formatting output for a system requiring a simple string argument.


15. What is a file position?
  - A file position is the location in a file that you are currently looking at; it can be used to select a specific place ina file for reading or writing.
  - Every file that is open for reading has a "read/get position" **seekg()**.
  - Every file that is open for writing has a "write/put position" **seekp()**.


16. What happens if you position a file position beyond the end of file?
  - It is undefined what happens if you try to seek beyond the end of a file, and operating systems really do differ in what happens then.


17. When would you prefer line-oriented input to type-specific input?
  - You would prefer line-oriented input when you want to do something that can't be done by type-specific input.


18. What does isalnum(c) do?
  - Returns true if c is a letter or decimal digit.
