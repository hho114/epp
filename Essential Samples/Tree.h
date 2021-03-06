//
// Original is copyrighted, source avaliable to instructors on request
// Modifications by M. Molodowitch


// Template Tree class definition
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cassert>
#include "TreeNode.h"

using namespace std;

enum TraversalOrderType {preorder, inorder, postorder};  

template< class ItemType >
class Tree {
public:
   Tree();      // constructor
   ~Tree();     // destructor
   bool insert( const ItemType & );
   bool retrieve( const ItemType &, ItemType & );
   bool deleteInfo( const ItemType & );
   bool isEmpty() const;
   void makeEmpty();
   void print(ostream & Outstream, TraversalOrderType order );   

private:

   TreeNode< ItemType > *treePtr;  // pointer to the root

   //utility functions 
   void printHelper( TreeNode< ItemType > *, ostream &, TraversalOrderType );
   bool insertHelper( TreeNode< ItemType >* & , const ItemType & );
   bool deleteHelper( TreeNode< ItemType >* & , const ItemType & );
   void deleteNode( TreeNode<ItemType >*& );
   bool retrieveHelper( TreeNode< ItemType >* & , const ItemType &, ItemType & );
   void makeEmptyHelper ( TreeNode< ItemType >* &);
};

// utility function to delete node pointed to by ptr
template< class ItemType >   
void Tree< ItemType >::deleteNode( TreeNode<ItemType >*& ptr )
{
	if (ptr != NULL)
	{
		if (ptr->leftPtr == NULL )
		{
			TreeNode<ItemType >* temp = ptr;
			ptr = ptr->rightPtr;
			temp->rightPtr = NULL;
			delete temp;
		}
		else if (ptr->rightPtr == NULL )
		{
			TreeNode< ItemType >* temp = ptr;
			ptr = ptr->leftPtr;
			temp->leftPtr = NULL;
			delete temp;
		}
		else
		{
			TreeNode< ItemType >* temp = ptr->leftPtr;

			if (temp->rightPtr == NULL)
			{
				ptr->info = temp->info;
				ptr->leftPtr = temp->leftPtr;
				temp->leftPtr = NULL;
				delete temp;
			}
			else
			{
				while ( (temp->rightPtr)->rightPtr != NULL )
					temp = temp->rightPtr;

				ptr->info = (temp->rightPtr)->info;

				TreeNode< ItemType >* delePtr = temp->rightPtr;
				temp->rightPtr = (temp->rightPtr)->leftPtr;
				delePtr->leftPtr = 0;
				delete delePtr;
			}
			
		}
	}
cout <<"finishing deleteNode..\n";
}


// Default constructor
template< class ItemType >
Tree< ItemType >::Tree() 
{
	treePtr = NULL;
}

// empties tree of all nodes
template< class ItemType >
void Tree< ItemType >::makeEmpty()
{
	makeEmptyHelper(treePtr);
}

template< class ItemType >
void Tree< ItemType >::makeEmptyHelper ( TreeNode< ItemType >* & ptr)
{
	if ( ptr != NULL )
	{
		makeEmptyHelper(ptr->leftPtr);
		makeEmptyHelper(ptr->rightPtr);
		
		delete ptr;
		ptr = NULL;
	}
}


// Destructor
template< class ItemType >
Tree< ItemType >::~Tree()
{
   makeEmpty();
}

// Insert a node into the Tree
template< class ItemType >
bool Tree< ItemType >::insert( const ItemType & value )
{
	return insertHelper( treePtr, value );
}

//recursive helper function for insertion
template< class ItemType >
bool Tree< ItemType >::insertHelper( TreeNode< ItemType >*& ptr, const ItemType & value)
{
	TreeNode<ItemType> * newPtr = new TreeNode<ItemType >( value );

    if (newPtr == 0)		//failure to allocate new node
	   return false;
   
   else 
   {
	   if ( ptr == NULL )  { // Tree is empty, so insert new node
         ptr = newPtr;
		 return true;
	   }
	   else if ( value == ptr->info) // value already in tree
	   {
		   cout << "value is already in the tree.\n\n";
		   return false;
	   }
	   else if ( value < ptr->info)   // insert in left subtree
	   {
		   return insertHelper( ptr->leftPtr, value);

	   }
	   else  // value > treePtr->info , insert in right subtree 
	   {						
		  return insertHelper( ptr->rightPtr,value);
	   }
   }
}

// Delete a value from the Tree
template< class ItemType >
bool Tree< ItemType >::deleteInfo( const ItemType & value )
{
	return deleteHelper( treePtr, value );
}
 
//recursive helper function for deletion 	
template< class ItemType >
bool Tree< ItemType >::deleteHelper( TreeNode< ItemType >* & ptr, const ItemType & value)
{
	if ( ptr == NULL )  { // Tree is empty
       cout << "Value not found.\n\n";
	   return false;
	}
	else if ( value == ptr->info) // value found in tree
	{
	   deleteNode( ptr );
	   return true;
	}
	else if ( value < ptr->info ) 
	{
	   return deleteHelper(ptr->leftPtr, value);
	   
	}
	else	//  value > ptr->info
	{
	   return deleteHelper(ptr->rightPtr, value);
	   
	}
}


// Retrieve info from tree
template< class ItemType >
bool Tree< ItemType >::retrieve( const ItemType & searchValue, ItemType & retrievedValue )
{
	return retrieveHelper( treePtr, searchValue, retrievedValue );
}

template< class ItemType >
bool Tree< ItemType >::retrieveHelper( TreeNode< ItemType >* & ptr, const ItemType & searchValue, ItemType & retrievedValue)
{
   if ( ptr == NULL )             // Tree is empty
      return false;             // Retrieve unsuccessful
   else {
   
	   if ( searchValue < ptr->info ) 
	   {
		  return retrieveHelper( ptr->leftPtr, searchValue, retrievedValue );
	   }
	   else if ( searchValue > ptr->info ) 
	   {
		  return retrieveHelper( ptr->rightPtr, searchValue, retrievedValue);
	   }
	   else				// searchValue == ptr->info
	   {
		  retrievedValue = ptr->info;	//retrieve successful			
		  return true;
	   }
 
   }
}


// Is the Tree empty?
template< class ItemType > 
bool Tree< ItemType >::isEmpty() const
{ 
	return (treePtr == NULL); 
}


// recursive helper function for printing contents of tree in given order
template< class ItemType > 
void Tree< ItemType >::print(ostream & Outstream, TraversalOrderType order )  
{
   if ( NULL == treePtr )
	   Outstream << "Tree is empty." << endl;
   else
	   printHelper( treePtr, Outstream, order );

}


// recursive helper function for printing to any ostream
template< class ItemType >
void Tree< ItemType >::printHelper( TreeNode< ItemType > * ptr, ostream & Outstream, TraversalOrderType order)
{					   
   if ( ptr != NULL ) 
   {
	   switch (order){
		  case preorder:
			  Outstream << ptr->info << endl;
			  printHelper ( ptr->leftPtr, Outstream, preorder);
			  printHelper ( ptr->rightPtr, Outstream, preorder);
			  break;
		  case inorder:
			  printHelper ( ptr->leftPtr, Outstream, inorder);
			  Outstream << ptr->info << endl;
			  printHelper ( ptr->rightPtr, Outstream, inorder);
			  break;
		  case postorder:
			  printHelper ( ptr->leftPtr, Outstream, postorder);
			  printHelper ( ptr->rightPtr, Outstream, postorder);
			  Outstream << ptr->info << endl;
			  break;
	   }

	}

}

#endif


