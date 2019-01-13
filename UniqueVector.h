#ifndef UNIQUEVECTOR_H
#define UNIQUEVECTOR_H

/* UniqueVector is a class using dynamic arrays as the data structure containing only unique elements. 
  It's data is stored within the array and in order to make sure the elements are unique, it must not be already
  within the array, made sure by the use of functions such as contains(). Initially it starts off with nothing inside 
  with a size of 0 and a capactiy of 3 and is eventually increased/decreased by insert()/remove() . The size and capacity 
  the array can be changed since this is a dynamic array */
template<typename T>
class UniqueVector {
public:
    //Initialize UniqueVector with size 0 and capacity 3 
    UniqueVector();
    //Returns the size of the space currently allocated for the vector.
    unsigned int capacity() const{       
       return (univecCap); // return univecCap
    } 
    //- Returns the current number of elements in the vector.
    unsigned int size() const{ 
       return (univecSize); // return univecSize
    }
    // If the vector contains zero elements, returns true; otherwise, returns false.
    bool empty(); 
    //- If the vector contains data, returns true; otherwise, returns; false.
    bool contains(const T& data); 
    //- If pos is a valid position, retrieves the element in position pos in the array, stores it in data, and returns true; otherwise, returns false.
    bool at(unsigned int pos, T& data); 
    /*- If the vector does not already contain data, adds a new element,
    data, to the back of the vector, increases the container size by one, and returns true; otherwise,
    returns false. If the underlying array is full, creates a new array with double the capacity and
    copies all of the elements over. */
    bool insert(const T& data);
     /*- If the vector does not already contain data,
    adds a new element, data, to the vector at position pos, increases the container size by one,
    returns true; otherwise, returns false. If the underlying array is full, creates a new array with
    double the capacity and copies all of the elements over.*/
    bool insert(const T& data, unsigned int pos);
    /*- If the vector contains data, removes data from the vector,
    reduces the container size by one, leaves the capacity unchanged, and returns true; otherwise,
    returns false.*/
    bool remove(const T& data) ;
    /*- If pos is a valid position, removes the element in
    position pos, stores it in data, reduces the container size by one, leaves the capacity unchanged,
    and returns true; otherwise, returns false.*/
    bool remove(unsigned int pos, T& data);
    /*- If the vector is not empty, removes the last element in the vector,
    stores it in data, reduces the container size by one, leaves the capacity unchanged, and returns
    true; otherwise, returns false.*/
    bool pop_back(T& data) ;
    /*- Empties the vector of its elements and resets the capacity to 3:*/
    void clear();
    /*- If the vector on the left hand side has the same elements in the same
    order as the vector on the right hand side, returns true; otherwise, returns false.*/
    bool operator==(const UniqueVector<T>& first) const ;
    /* If the vector does not already contain data, adds a new
    element, data, to the front of the vector, increases the container size by one, and returns true;
    otherwise, returns false. If the underlying array is full, creates a new array with double the
    capacity and copies all of the elements over.*/
    bool push_front(const T& data);
private:
    T* uniVector; //pointer to uniVector that is allocated
    unsigned int univecCap; //values to keep track of array Capacity
    unsigned int univecSize; //values to keep track of array Size
    /* If the vector size is at max capacity, double the capacity, and copies all the elements over*/
    bool doubleSizeCap();
    /*- Takes everything after uniVector[pos] and shifts it to the left replacing uniVector[pos] and decreases array size*/
    void removeShift(int pos) ;
};
#include "UniqueVector.cpp"
#endif
