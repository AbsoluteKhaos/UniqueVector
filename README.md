## Assignment 1 - UniqueVector and Classroom

Class UniqueVector:
UniqueVector is a class using dynamic arrays as the data structure containing only unique elements. It's data is stored within the array and in order to make sure the elements are unique, it must not be already within the array, made sure by the use of functions such as contains(). Initially it starts off with nothing inside with a size of 0 and a capactiy of 3 and is eventually increased/decreased by insert()/remove() . The size and capacity the array can be changed since this is a dynamic array.

Class Classroom: 
Classroom contains strings of names of students by UniqueVector as a data structure storing those strings into the dynamic array of UniqueVector and in turn uses its functions such as:
-addStudent/ removeStudent in order to dynamically change its array and insert/remove data
-containsStudents to retrieve data from the underlaying dynamic array of UniqueVector

UniqueVector.cpp+.h && Classroom.cpp+.h:
Both compile and pass every test

Compiling:
Make file is already set up in order to run the program as long as all the files are in the correct directory.
1. In linux, in the terminal get to the directory of which the file is in
2. Type make (exe will be generated)
3. Run ./UniqueVector (if desired individual test can be run)
4. All test completed
5. ????
6. Profit

Bugs fixed:
-Finally figured out, why program was seg faulting. It was due to doubleSizeCap() not allocating a properly sized array, causing access to invalid indexes and it was called in the incorrect order
- This was also run into in removeShift() where it would access the incorrect index 

Comments:
-Everything compiles and runs smoothly, however ClassroomTester [student] takes a little longer to complete. All the other test seem to finish immediately.


