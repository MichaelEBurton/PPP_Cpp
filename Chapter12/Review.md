1. Why do we use graphics?
  - Graphics are useful for conveying information, teaching interesting programming concepts, and fun!


2. When do we try not to use graphics?
  - When we have nothing that needs to be displayed graphically.


3. Why is graphics interesting for a programmer?
  - It can provide interesting code to read.
  - Demonstrates the idea of object-oriented code.
  - "Fertile source design examples"
  

4. What is a window?
  - A window defines a rectangle of pixels on screen to be used for a graphic.


5. In which namespace do we keep our graphics interface classes (our graphics library)?
  - The Graph_lib namespace.


6. What header files do you need to do basic graphics using our graphics library?
    - Point.h
    - Window.h
    - Simple_window.h
    - Graph.h
    - GUI.h


7. What is the simplest window to use?
  - Simple_window, which takes a point for the upper left corner,  the length and width, and the window label.


8. What is the minimal window?
  - I think this refers to a regular window that does not include a "next" button.


9. What's a window label?
  - A window label is at the upper left of the window and gives the user an idea of what the window is for.


10. How do you label a window?
  - You pass a string to the fourth argument of the window/simple window functions.


11. How do screen coordinates work? Window coordinates? Mathematical coordinates?
  - Screen coordinates have an origin at the upper left corner of your computer's display, and the x-axis increases from left to right, the y-axis from top to bottom.
  - Window coordinates, the origin is the upper left corner of the window. Rules for axes are the same except they are bounded by the length and width of the window.
  - Mathematical coordinates: um... it depends. Polar, cartesian, spherical, etc.


12. What are examples of simple "shapes" that we can display?
  - Line
  - Lines
  - Polygon
  - Axis
  - Rectangle
  - Text
  - Image


13. What command attaches a shape to a window?
  - the attach method; i.e. window.attach(shape)


14. Which basic shape would you use to draw a hexagon?
  - Polygon


15. How do you write text somewhere in a window?
  - Use a Text object.


16. How would you put a photo of your best friend in a window (using a program you wrote yourself)?
  - Use an image object.


17. You made a Window object, but nothing appears on your screen. What are some possible reasons for that?
  - We forgot to give control to the GUI system, or our GUI library was not installed properly.


18. You have made a shape, but it doesn't appear in the window. What are some possible reasons for that?
  - We didn't attach it.