// Original source attribution available
// Modified by M. Molodowitch

// An Patient class
#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

using namespace std;

class Patient {
	friend ostream & operator<<( ostream &, const Patient );
	friend istream & operator>>( istream &, Patient & );

public:
   Patient( const string = " ", const string = " ",  const int = -1);  // constructor
   ~Patient();                       // destructor
   Patient & setFirstName(const string );
   Patient & setLastName(const string );
   Patient & setID( const int );
   const string getFirstName() const;  
   const string getLastName() const;  
   const int getID() const;

   // Overloaded comparison operators <, >, ==,  only the ID value will be looked at
   bool operator<(const Patient & right) const;   
   bool operator>(const Patient & right) const;
   bool operator==(const Patient & right) const;
	
private:
   string firstName;
   string lastName;
   int ID;

};

#endif



