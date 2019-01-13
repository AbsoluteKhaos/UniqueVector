#include <iostream>
#include <ostream>
#include <string>

#include "Classroom.h"
using namespace std;
bool Classroom::addStudent(const string& name){ 
    if(classRoom.insert(name)){ //Calls function inserts the name
       return true;
    }
    return false; //If name already exists 
}
bool Classroom::removeStudent(const string& name)
{ 
    if(classRoom.remove(name)){//Calls function removes the name
       return true;
    } 
    return false;
}
bool Classroom::containsStudent(const string& name)
{ 
    if(classRoom.contains(name)){ //Calls function finds the name
       return true;
    } 
    return false;
}
string Classroom::listAllStudents()
{ 
    string allName; 
    string data;
    unsigned int i;
    for (i=0;i<classRoom.size()-1; i++){ //Goes thru classRoom size-1
        if (classRoom.at(i,data)){ //Retrieves the name
            allName += data; //Add to the string 
            allName += ",";  // adds comma
        }      
    }
    if (i<classRoom.size()){ //Gets last name in classRoom
        if (classRoom.at(i,data)){ 
            allName += data; //Add to the string 
        }    
    }
    return (allName);
}
string Classroom::removeAlphabeticallyFirst()
{ 
    string firstName;
    string tempName;
    classRoom.at(0, tempName); //initialize data in order to compare for the first time
    classRoom.at(0, firstName); 
    unsigned int size = classRoom.size(); 
    for (unsigned int i=0; i<size; i++){
	    classRoom.at(i, tempName); //change tempName data
	    if (tempName < firstName){ //if the tempName comes before firstName
	        firstName= tempName; //it is changed and now the new AlphabeticallyFirst
	    }
    }
    classRoom.remove(firstName); //find and remove firstName from the array
    return firstName;
}
string Classroom::removeAlphabeticallyLast()
{ 
    string lastName;
    string tempName;
    classRoom.at(0, tempName);//initialize data in order to compare for the first time
    classRoom.at(0, lastName);
    unsigned int size = classRoom.size();
    for (unsigned int i=0; i<size; i++){
	classRoom.at(i, tempName);//change tempName data
        if(tempName > lastName){//if the tempName comes after lastName
            lastName= tempName; //it is changed and now the new AlphabeticallyLast
        }
    }
    classRoom.remove(lastName); //find and remove lastName from the array
    return lastName;
}
void Classroom::combineClasses(Classroom& otherClass)
{ 
    string insertName; //variable for the strings to be inserted into the array
    unsigned int size = otherClass.classRoom.size(); //Go through otherClass
    for (unsigned int i=0; i<size; i++){
	 otherClass.classRoom.at(i, insertName); //Get data at i from otherClass
	 classRoom.insert(insertName); //If data isnt inside the array it is added, otherwise it is ignored
    }
}
