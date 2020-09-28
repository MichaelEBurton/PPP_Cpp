1. Why don't we "just" use a commercial or open-source graphics library directly?
  - A commercial/open-source graphics library can have hundreds of classes with dozens of functions applying to each. Rather than using those facilities directly we want to reduce the complexity by providing an interface with a smaller number of classes that are easier for our users to manage.


2. About how many classes from our graphics interface library do you need to do simple graphics output?
  - Around two dozen.


3. What are the header files needed to use the graphics interface library?
  - Point.h
  - Graph.h
  - Window.h
  - Simple_window.h
  - GUI.h


4. What classes define closed shapes?
  - Closed_polyline
  - Polygon
  - Rectangle
  - Circle
  - Ellipse


5. Why don't we just use Line for every shape?
  - We could use line for every shape, but that would become rather tedious for the user. Secondly we want to "think in terms of objects." That is, all the lines of a rectangle should correspond to the object rectangle. 


6. What do the arguments to Point indicate?
  - They indicate the x coordinate and y coordinate on the screen.


7. What are the components of Line_style?
  - An enumeration of the different styles offered in FLTK
  - Constructors
    + One with the enumeration 
    + One with the enumeration, and an integer specifying line width
    + One with an integer for the enumeration


8. What are the components of Color?
  - An enumeration for FLTK colors.
  - An enumeration for transparency.
  - Multiple constructors.
  - Function to return integer representation of color.
  - Function to return whether the color is visible.
  - Function to set visibility.


9. What is RGB?
  - A way to represent color (red, green, blue).


10. What are the differences between two Lines and a Lines containing two lines?
  - A Lines containing two lines is thought of as one object whereas, the two Lines are separate objects that act independently of each other.


11. What properties can you set for every shape?
  - Color


12. How many sides does a Closed_polyline defined by five Points have?
  - Five


13. What do you see if you define a Shape but don't attach it to a Window?
  - A blank window.


14. How does a Rectangle differ from a Polygon with four Points (corners)?
  - It's corners have 90 degree angles.


15. How does a Polygon differ from a closed_polyline?
  - A closed_polyline can have lines that intersect whereas, a polgon cannot.


16. What's on top: fill or outline?
  - outline


17. Why didn't we bother defining a Triangle class (after all, we did define Rectangle)?
  - Culturally we seem to encounter rectangles a lot more often than triangles.


18. How do you move a Shape to another place in a Window?
  - You can use the move() method.


19. How do you label a Shape with a line of text?
  - With a Text object.


20. What properties can you set for a text string in a Text?
  - Font
  - Font size
  - Color


21. What is a font and why do we care?
  - The style of the letters that are written. Some fonts are more professional than others, and some are easier to read.


22. What is Vector_ref for and how do we use it?
  - An interface that makes it convenient for holding unamed elements.
  

23. What is the difference between a Circle and an Ellipse?
  - A circle is defined by its center point and radius; an ellipse is defined by its center point and a major and minor axis.


24. What happens if you try to display an Image given a file name that doesn't refer to a file containing an image?
  - If it cannot be displayed the program will write "cannot open file.file_extension"


25. How do you display part of an image?
  - Use the set_mask method to select a sub-picture of the image to be displayed.
  