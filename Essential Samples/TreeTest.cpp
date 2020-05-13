// By M. Molodowitch revised 12/11/2014
// Shows how a binary search tree is used, and how to make it store integers in one case, and Patient objects in another. 


#include <iostream>
#include <fstream>
#include "Tree.h"
#include "Patient.h"

using namespace std;

// Function to test the class Tree



void instructions();


int main()
{

   Tree< int > intTree;

   cout << "Testing a Tree of integer values\n";

   char choice;
   int value;
   int keyValue;
   int retrievedValue= -1;
   int screenOrFile = 1;
   int traversalChoice;

   ofstream outStream;
   string fileName;


 
     instructions();
	 cin >> choice;

     while ( (choice != 'q')&& (choice != 'Q')) 
	 {

	   switch ( choice ) {
         case 'a':
		 case 'A':
            cout << "\nEnter an integer: ";
            cin >> value;
			intTree.insert( value );
            break;
         case 'd':
		 case 'D':
            cout << "\nEnter an integer to delete: " << endl;
            cin >> value;
            if ( intTree.deleteInfo( value ) )
               cout << "\nValue removed from tree\n";
			else
				cout<< "Value not found in tree.\n";
             break;
		 case 'p':
		 case 'P':
			cout << "Enter 1 to print to screen, 2 to print to a file\n";
			cin >> screenOrFile;
			if (2 == screenOrFile)
			{
				cout << "Enter file name\n";
				cin >> fileName;

				outStream.open (fileName.c_str());
			}

			cout << "Enter 0 for preorder, 1 for inorder, and 2 for postorder.\n";
			cin >> traversalChoice;

			switch (traversalChoice)
			{
			case 0: 
				if (2 == screenOrFile)
					intTree.print(outStream, preorder);
				else 
					intTree.print( cout, preorder);
				break;

			case 1:
				if (2 == screenOrFile)
					intTree.print(outStream, inorder);
				else 
					intTree.print (cout, inorder);
				break;

			case 2: 
				if (2 == screenOrFile)
					intTree.print(outStream, postorder);
				else 
					intTree.print(cout, postorder);
				break;
			default:
				cout << "must choose 0, 1, or 2.\n";
			}
			break;

		 case 'f':
		 case 'F':
			 cout << "Enter an integer to find: " << endl;
             cin >> value;
			 if (intTree.retrieve (value, retrievedValue))
				cout << "retrieved " << retrievedValue << endl;
			 else
				 cout << value << " not found." << endl;
			 break;
		 
		 default:
			 cout << "Please enter a letter from {a, d, p, f, q}.\n\n";

			 break;
      }
	   
	  instructions();
	  cin >> choice;

   } // end while 
	
	
	intTree.makeEmpty( );
	intTree.print(cout, inorder);
	
   cout << "End tree test\n\n";

   
   Tree< Patient > patientTree;

   cout << "Testing a Tree of patient records\n";

	 Patient someOne;
	 Patient retrievedPatient;
	 
	 string lastName;
	 int ID;

     instructions();
	 cin >> choice;

     while ((choice != 'q')&& (choice != 'Q') ) 
	 {

	   switch ( choice ) {
         case 'a':
		 case 'A':
            // Only ID and last name entered
           
			cout << "Please enter patient's last Nmae:" << endl;
			cin >> lastName;
			
			cout << "Please enter patient's ID:" << endl;
			cin >> ID;
		
			someOne.setLastName(lastName);
			someOne.setID(ID);

			if (patientTree.insert( someOne ))
				cout << "Patient's record inserted.\n";
			else 
				cout << "Patient's record not inserted.\n";
            break;
         case 'd':
		 case 'D':
            cout << "Enter the ID of the patient to delete: " << endl;
            cin >> ID;
			someOne.setID(ID);
            if ( patientTree.deleteInfo( someOne ) )
               cout << "Patient with ID " << ID << " deleted." << endl;
			else
				cout << "Patient with ID " << ID << " not found.\n";
		    break;
		 case 'p':
		 case 'P':
			cout << "Enter 1 to print to screen, 2 to print to a file\n";
			cin >> screenOrFile;
			if (2 == screenOrFile)
			{
				cout << "Enter file name\n";
				cin >> fileName;

				outStream.open (fileName.c_str());
			}

			cout << "Enter 0 for preorder, 1 for inorder, and 2 for postorder.\n";
			cin >> traversalChoice;

			switch (traversalChoice)
			{
			case 0: 
				if (2 == screenOrFile)
					patientTree.print(outStream, preorder);
				else 
					patientTree.print( cout, preorder);
				break;

			case 1:
				if (2 == screenOrFile)
					patientTree.print(outStream, inorder);
				else 
					patientTree.print (cout, inorder);
				break;

			case 2: 
				if (2 == screenOrFile)
					patientTree.print(outStream, postorder);
				else 
					patientTree.print(cout, postorder);
				break;
			default:
				cout << "must choose 0, 1, or 2.\n";
			}
			break;

		 case 'f':
		 case 'F':
			 cout << "Enter the ID of the patient to find: " << endl;
             cin >> ID;
			 someOne.setID(ID);

			 if (patientTree.retrieve (someOne, retrievedPatient))
				 cout << "retrieved - Last Name: " << retrievedPatient.getLastName() << " ID: " << retrievedPatient.getID()<< endl;
			 else
				 cout << "Patient with ID " << ID << " not found." << endl;
			 break;
		 
		 default:
			 cout << "Please enter a letter from {a, d, p, f, q}.\n\n";

			 break;
      }
	   
	  instructions();
	  cin >> choice;

   } // end while 
	
	
	patientTree.makeEmpty( );
	patientTree.print(cout, inorder);
	
   cout << "End tree test\n\n";

   return 0;
}

void instructions()
{
   cout << "Enter one of the following:\n"
	   << "  a: to insert into tree\n" 
	   << "  d: to delete from tree\n" 
	   << "  p: to print the tree to ostream\n"
	   << "  f: to retrieve from the tree\n"
		<< "  q: end tree processing\n";
}

