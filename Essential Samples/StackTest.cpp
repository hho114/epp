// Original copyrighted, source avaliable to instructors on request
// Modifications by M. Molodowitch

// Shows how a stack is used, and how to make it store integers in one case, and StudentInfo objects in another. 


#include <iostream>
#include <fstream>
#include "Patient.h"
#include "Stack.h"

using namespace std;

void instructions();


int main()
{

   Stack< int > intStack;
  
    cout << "Testing a Stack of integer values\n";

   int choice = 0;
   int value = -1;
 

   do {

      instructions();
      cin >> choice;

      switch ( choice ) {
         case 1:
            cout << "Enter an integer: ";
            cin >> value;
            if (intStack.push( value ))
				cout << value << " pushed on stack.\n";
			else
				cout << "Could not push on stack.\n";
            break;
         case 2:
            if ( intStack.top( value ) )
               cout << value << " is at the top of the stack\n";
			else
				cout << "Stack was empty.\n";

            break;
		 case 3:
			if ( intStack.pop() )
               cout <<  "The top value is popped off the stack\n";
			else
				cout << "Stack was empty.\n";

			break;
      }
   } while ( choice != 4 );

   cout << "End integer stack test\n\n";


   cout << "Testing a Stack of patient records\n";

   Stack< Patient> patientStack;

   Patient someOne;
	int ID;
	string lastName;

   do {

      instructions();
      cin >> choice;

      switch ( choice ) {
         case 1:
			 // 
           
			cout << "Please enter patient's last name:" << endl;
			cin >> lastName;
			cout << "Please enter patient's ID:" << endl;
			cin >> ID;
		
			someOne.setLastName(lastName);
			someOne.setID(ID);
            if (patientStack.push( someOne ))
				cout << "Patient pushed on stack.\n";
			else 
				cout << "Could not push on stack.\n";
           
            break;
         case 2:
            if ( patientStack.top( someOne ) )
               cout << someOne.getLastName() << " is at the top of the stack\n\n";
			else
				cout << "Stack was empty.\n";

            break;
		 case 3:
			 if ( patientStack.pop( ) )
               cout << "The top patient was popped off the stack\n";
			else
				cout << "Stack was empty.\n";

			break;
      }
   } while ( choice != 4 );

   cout << "End patient record stack test\n\n";

  
   return 0;
}

void instructions()
{
   cout << "Enter one of the following:\n"
        << "  1 to push on to the stack\n" 
        << "  2 to see what is at the top of the stack\n" 
		<< "  3 to pop the stack\n"
        << "  4 to end stack testing\n";
}


