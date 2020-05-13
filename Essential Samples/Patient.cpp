// Revised by M. Molodowitch 9/2/13
// uses set member functions in constructor
// Member function definitions for class Patient
#include <iostream>
#include <string>
#include <cassert>
#include "Patient.h"

using namespace std;


// Constructor dynamically allocates space for the
// description and uses strcpy to copy
// into the object
Patient::Patient( const string first, const string last, const int id )
{
   setFirstName (first);
   setLastName(last); 
   setID ( id );
}


// Destructor can be overloaded to deallocate 
// any dynamically allocated memory.
// No dynamically allocated memory here, so nothing in body
Patient::~Patient()
{
}

bool Patient::operator<(const Patient & right) const 
{
	   return (ID < right.ID);
}
   
bool Patient::operator>(const Patient & right)const 
{
	   return (ID > right.ID);
}
    
bool Patient::operator==(const Patient & right)const 
{
	   return (ID == right.ID);
   
}

Patient & Patient::setFirstName( const string first )
{

	firstName = first;

	return (*this);
}

Patient & Patient::setLastName( const string last ){

	lastName = last;

	return (*this);
}

Patient & Patient::setID( const int idNumber )
{

	ID = idNumber;

	return (*this);

}




const string Patient::getFirstName() const
{
   // Const before return type prevents client from modifying
   // private data. Client should copy returned string before
   // destructor deletes storage to prevent undefined pointer.
   return firstName;
}

const string Patient::getLastName() const
{
   // Const before return type prevents client from modifying
   // private data. Client should copy returned string before
   // destructor deletes storage to prevent undefined pointer.
   return lastName;
}
const int Patient::getID() const
{
	return ID;
}

ostream & operator<<( ostream & output, const Patient aPatient)
{
	output << "Patient ID:  " << aPatient.getID()<< endl;
	output << "Patient First name:  " << aPatient.getFirstName() << endl;
	output << "Patient Last name:  " << aPatient.getLastName() << endl;

	return output;
}

istream & operator>> (istream & input, Patient & aPatient)
{
	int newID;
	string first;
	string last;

	cout << "\nPatient ID: " ;
	input >> newID;
	aPatient.setID(newID);

	cout << "\nPatient First Name: ";
	input >> first;
	aPatient.setFirstName( first );

	cout << "\nPatient Last Name: ";
	input >> last;
	aPatient.setLastName( last );

	return input;
}