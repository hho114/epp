/*
Epp Exam
Huy Ho
Cs 301

August 23, 2017
*/

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(char *arr, int length);


int main()
{
	char arr[] = { 'r','a','c','e','c','a','r' };
	char arr2[] = { 'c','b','c' };
	
	if (isPalindrome(arr, 7))
	{
		cout << "Palind" << endl;
	}
	else
	{
		cout << "Not Palind" << endl;
	}

	system("pause");
	return 0;
}

bool isPalindrome(char * arr, int length)
{
	//Check if array is empty
	if (length <= 0)
	{
		return false;
	}

	int half = length / 2;
	int index = 0;

	while (index < half)
	{

		if (arr[index] != arr[(length - 1) - index])
		{
			return false;
		}
		else
		{
			index++;
		}
	}

	return true;
}
