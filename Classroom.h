#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "UniqueVector.h"
using namespace std;
/* Classroom contains strings of names of students by UniqueVector as a data structure 
   storing those strings into the dynamic array of UniqueVector and in turn uses its functions such as:
  -addStudent/ removeStudent in order to dynamically change its array and insert/remove data
  -containsStudents to retrieve data from the underlaying dynamic array of UniqueVector
  -etc
*/
class Classroom{
public:
    /*— If a student named name is not already on the
    classroom roster, adds a new student named name to the classroom roster and returns true;
    otherwise, returns false.*/
    bool addStudent(const string& name); 
    /* — If a student named name is on the classroom
    roster, removes the student named name from the classroom roster and returns true; otherwise,
    returns false.*/
    bool removeStudent(const string& name);
    /* — If a student named name is on the classroom
    roster, returns true; otherwise, returns false. */
    bool containsStudent(const string& name);
    /*— Returns a string containing the names of the students in the
    classroom, separated by commas.*/
    string listAllStudents(); 
    /*— Removes and returns the student whose name comes
    lexicographically first on the classroom roster.*/
    string removeAlphabeticallyFirst();
    /*— Removes and returns the student whose name comes
    lexicographically last on the classroom roster.*/
    string removeAlphabeticallyLast();
    /* — Adds all of the student names on otherClass’
    roster onto the roster of the Classroom calling this function and leaves otherClass unchanged.*/
    void combineClasses(Classroom& otherClass);

private:
    UniqueVector<string> classRoom;
};

#endif
