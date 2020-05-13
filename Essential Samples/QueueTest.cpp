// Original copyrighted, source avaliable to instructors on request
// Modifications by M. Molodowitch

// Shows how a queue is used, and how to make it store integers in one case, and Patient objects in another. 

#include <iostream>
#include <fstream>
#include "Patient.h"
#include "Queue.h"

using namespace std;

void instructions();


int main()
{
   

   Queue< int > intQueue; 

   cout << "Testing a Queue of integer values\n";

   int choice;
   int value;
 

   do    {
	  instructions();

      cin >> choice;

      switch ( choice ) {
         case 1:
            cout << "Enter an integer: ";
            cin >> value;
            if (intQueue.enqueue( value ) )
				cout << value << "placed in queue\n";
			else
				cout << "Could not put in queue\n";
            break;
         case 2:
            if ( intQueue.front( value ) )
               cout << value << " is at the front of the queue\n";
			else
				cout << "Queue was empty.\n";
            break;
		 case 3:
			if (intQueue.dequeue())
				cout << "Front item removed from the queue\n";
			else
				cout << "Queue was empty.\n";
			break;
      }
   } while ( choice != 4 );

   cout << "End integer queue test\n\n";


  
   Queue<Patient>  patientQueue;

   cout << "Testing a Queue of Patient records\n";

	Patient someOne;
	string lastName;
	int ID;
  
   do 
   {
	  instructions();

      cin >> choice;

      switch ( choice ) {
         case 1:
			// Only ID and last name entered
          
			cout << "Please enter patient's last name:" << endl;
			cin >> lastName;
			
			cout << "Please enter patient's ID:" << endl;
			cin >> ID;
		
			someOne.setLastName(lastName);
			someOne.setID(ID);
           
            if (patientQueue.enqueue( someOne ))
				cout << "Patient placed in queue\n\n";
			else
				cout << "Could not put in queue\n\n";
            
            break;
         case 2:
            if ( patientQueue.front( someOne ) )
               cout << someOne.getLastName() << " is at the front of the queue\n\n";
			else
				cout << "Queue was empty.\n\n";

            
            break;
		 case 3:
           if ( patientQueue.dequeue( ) )
               cout << "The first patient in the queue was removed.\n\n";
			else
				cout << "Queue was empty.\n\n";
			break;
      }
   } while ( choice != 4 );

   cout << "End patient records queue test\n\n";


   return 0;
}


void instructions()
{
   cout << "Enter one of the following:\n"
        << "  1 to enqueue\n" 
        << "  2 to see the front item in the queue\n" 
		<< "  3 to remove the front item from the queue\n"
        << "  4 to end queue testing\n";
}
