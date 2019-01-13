#ifndef UNIQUEVECTOR_CPP
#define UNIQUEVECTOR_CPP

#include "UniqueVector.h"
#include <iostream>
#include <ostream>

template<typename T>
UniqueVector<T> :: UniqueVector(){
    univecCap=3; //initialize cap to 3
    univecSize=0; //initialize cap to 0
    uniVector = new T[3]; // default constructor 
}
template<typename T>
bool UniqueVector<T> :: empty()
{ 
    if(univecSize==0){ // if "empty" return true 
       return true;
    }
    return false;     
}
template<typename T>
bool UniqueVector<T>::contains(const T& data) 
{
    for(unsigned int i=0; i<univecSize; i++){ //go thru uniVector for data
       if(uniVector[i]==data){ 
          return true; //found
       }            
    }; 
    return false; //otherwise return false
}
template<typename T>
bool UniqueVector<T>::at(unsigned int pos, T& data){
    if(pos>=univecSize){ //invalid indexes
       return false;
    }
    else { //get data 
       data=uniVector[pos];
       return true; 
    }               
}
template<typename T>
bool UniqueVector<T>::doubleSizeCap(){
    if (univecSize == univecCap){   
       unsigned int doubleCap= univecCap*2;        
       T* doubleuniVector=NULL;
       doubleuniVector= new T[doubleCap]; // create new array with x2 size
       for(unsigned int i=0; i<univecSize; i++){
          doubleuniVector[i]=uniVector[i]; //transfer the data
       };
       univecCap= doubleCap; //update cap
       delete []uniVector; //delete old
       uniVector=doubleuniVector; //set pointer to double 
       return true;
    }
    else{
       return false;
    }
}
template<typename T>
bool UniqueVector<T>::insert(const T& data){
    if(this->contains(data)){ //use to reuse contain function
       return false;
    }  
    if (univecSize <= univecCap){ //if valid indexes
       doubleSizeCap();
       uniVector[(univecSize)]=data; //put in data
       univecSize++;   
    }          
    return true;
}
template<typename T>
bool UniqueVector<T>::insert(const T& data, unsigned int pos){
    if(this->contains(data)){ //use to reuse contain function
       return false;
    }
    if(pos>univecSize){
       return false;
    }
    if(pos<=univecSize){
       if(doubleSizeCap()){}//check if Size/Cap can be double
       T* shiftedVector=NULL;
       unsigned int newSize=univecSize+1;
       shiftedVector= new T[newSize]; // create new array for everything + data
       for(unsigned int i=0; i<pos; i++){
          shiftedVector[i]=uniVector[i]; //transfer the everything before pos index
       };
       shiftedVector[pos]=data; //put in data in pos index
       for(unsigned int i=0; i<univecSize-pos; i++){
           shiftedVector[pos+i+1]=uniVector[pos+i]; //transfer the everything after pos index
       };
       univecSize= newSize; //update cap
       delete []uniVector; //delete old
       uniVector=shiftedVector; //set pointer to double	
    }
    return true;
}
template<typename T>
bool UniqueVector<T>::push_front(const T& data){
    if(this->contains(data)){ //use to reuse contain function
       return false;
    }  
    else{
       doubleSizeCap();
       T* shiftedVector=NULL;
       unsigned int newSize=univecSize+1;
       shiftedVector= new T[newSize]; // create new array for everything + data
       for(unsigned int i=0; i<univecSize; i++){
           shiftedVector[i+1]=uniVector[i]; //transfer the old data to corresponding indexes after the first one
       };
       shiftedVector[0]=data; //put in data at first
       univecSize= newSize; //update cap
       delete []uniVector; //delete old
       uniVector=shiftedVector; //set pointer to double
    }             
    return true;
}    
template<typename T>
void UniqueVector<T>::removeShift(int pos) 
{
    for(unsigned int j=0; j<univecSize-pos-1; j++){
        uniVector[pos+j]=uniVector[pos+j+1]; // data is removed and everything is shifted
    };
    univecSize--;//decrease size
}
template<typename T>
bool UniqueVector<T>::remove(const T& data) {
    for(unsigned int i=0; i<univecSize; i++){
       if(uniVector[i]==data){ // find i
          if(i==univecSize-1){ //if data is the last index
             univecSize--; // decrease size
             return true;
          }
          removeShift(i); //everything after i is shifted to the left replacing uniVector[i] and decreased size
          return true;
       }          
    };
  return false;   
}

template<typename T>
bool UniqueVector<T>:: remove(unsigned int pos, T& data){
    if(pos==univecSize-1){ //if data is the last index
	data=uniVector[pos]; //retrieve data
        univecSize--; // decrease size
        return true;
    }
    else if(pos<univecSize){
	data=uniVector[pos]; //otherwise data is retrieved	
        removeShift(pos); //everything after pos is shifted to the left replacing uniVector[pos] and decreased size
        return true;
    }
    else{ //if pos is greater than univecSize it is invalid
	return false;
    }
}
template<typename T>
bool UniqueVector<T>:: pop_back(T& data){
    if(univecSize!=0){ 
        data=uniVector[univecSize-1]; //get data from last index
        univecSize--;// decrease size
        return true;
    }
    else{ //if ==0 obviously return false
        return false;
    }
}
template<typename T>
void UniqueVector<T>:: clear() {
    uniVector = new T[3]; //recreate
    univecSize=0; //reset values
    univecCap=3;
}
template<typename T>
bool UniqueVector<T>:: operator==(const UniqueVector<T>& rightVector) const  {	
    if(this->size() == rightVector.size() &&  this->capacity() ==  rightVector.capacity() ){ // if both size and cap are the same
	for(unsigned int i=0; i<this->size(); i++){
	    if(this->uniVector[i]==rightVector.uniVector[i]){}// if all elements are the same
	    else{
		    return false; //If anything found isnt the same return false and exit
	    }
	};
	return true;//Finished traversing, thefore all elements are the same 
    }
    else{
	return false;// if the size and cap is different return false
    }
}
#endif
