/*
Epp Exam
Huy Ho
Cs 301

August 23, 2017
*/

#include <iostream>
#include <string>

using namespace std;


struct Node
{
	int data;
	Node * next;
};

// implementation of rotateLeft declaration
Node * rotateLeft(Node *& header);
// implementation of print declaration
void print(Node* &head);
// implementation of product declaration
int product(Node * head);


void insertFront(Node *&head, int data);
int main()
{
	// create linked list by reading (say, 6) integers from the user
		// declare headRotated
	Node *headRotated = nullptr;
	
	// implementation of linked list
		for (int i = 5; i > 1; i--)
		{
			cout << i << endl;
			insertFront(headRotated, i);
		}


		headRotated = rotateLeft(headRotated);

		print(headRotated);
	
		cout <<"Product of link list: " <<product(headRotated) << endl;

	system("pause");
	return 0;
}


// implementation of rotateLeft definition
Node * rotateLeft(Node *& header)
{
	Node *previous = header;
	Node *ptr = header;
	
	while(ptr != nullptr)
	{
		previous = ptr;
		ptr = ptr->next;
		if (ptr == nullptr)
		{
			Node * newNode = new Node;
			newNode->data = header->data;
			newNode->next = nullptr;
			previous->next = newNode;
			ptr = header;
			header = header->next;
			delete ptr;
			ptr = nullptr;

		}
		
	}

	return header;
}

// implementation of print definition
void print(Node *& head)
{
	Node * ptr = head;
	while (ptr != nullptr)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}
// implementation of product definition
int product(Node * ptr)
{
	if (ptr == nullptr)
	{
		return 1;
	}
	return ptr->data *product(ptr->next);
}
// implementation of insertFront definition
void insertFront(Node *& head, int data)
{
		Node * newNode = new Node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
}
