/**********************************
* Author: Professor Matt Bell - And LJ Benson
*
* Purpose: Challenge students with a fun learning exercise, as a test
*
* Instructions: Just as you can dynamically allocate a single dimensional
*               using pointers, you can dynamically allocate a 2D array
*               using pointers to pointers! Below is some partially completed
*               code that should generate a 2D array of integers, fill it
*               with integers, print out that array in a nice table, then
*               delete it. Your job: follow the comments to complete the code.
*
*               Hint: This may sound hard because it asks you to use pointers in
*               a way we haven't explicitly talked about in class, but, if you
*               follow the principles we've talked about to their logical end,
*               it's actually a breeze! Trust what you've learned, make good
*               use of the textbook and slides and your previous work, and
*               learn the true power of the dark side, er, I mean pointers.
***********************************/


#include<iostream>
using namespace std;

//This function takes a number of rows as a first parameter and
//a number of columns as its second parameter. It then returns
//a pointer to a pointer to an int that holds a two-dimensional
//array of integers.
int** fillArray(unsigned int, unsigned int);


//This function takes a dynamically allocated 2D array and sends
//it to the bit bucket in the sky, er, I mean deletes it.
//The first parameter will be the two dimensional array, viewed
//as a pointer to a pointer to an int. The second parameter is
//the number of rows in that array.
void deleteArray(int**, int);


//Don't change main()! It tests your code.
int main()
{
	int nR, nC; //Number of rows and columns
	cout << "How many rows? ";
	cin >> nR;
	cout << "How many cols? ";
	cin >> nC;

	//Create the array!
	int** myArray = fillArray(nR, nC);

	//Print the array to the screen!
	for (int i = 0; i < nR; i++) {
		for (int j = 0; j < nC; j++)
			cout << myArray[i][j] << " ";
		cout << endl;
	}

	//DESTROY!!!!
	deleteArray(myArray, nR);

	//The end! Ta da!
	return 0;
}


//This function takes a number of rows as a first parameter and
//a number of columns as its second parameter. It then returns
//a pointer to a pointer to an int that holds a two-dimensional
//array of integers.
int** fillArray(unsigned int numRows, unsigned int numCols)
{
	int** My2DArray; // This will hold the array! Don't change this line.

	//Dynamically allocate an array of pointers to ints. Hint: You can dynamically
	//allocate the array by saying you want a new int*[<size>], where
	//<size> is the number of rows in this case.

	My2DArray = new int*[numRows]; 



	//Allocates an array of integers to each row. (This creates the columns!)
	//You fill in the blanks.
	for (int i = 0; i < numRows; i++) {
		//Under this comment put a line of code to 1) allocate the array of ints
		//and 2) assign it to the current row of your array.
		My2DArray[i] = new int [numCols];

		//The code below reads a number into each location in the 2D array.
		for (int j = 0; j < numCols; j++) {
			cout << "Number at position " << i << "," << j << "? ";
			cin >> My2DArray[i][j];
		}
	}
	return My2DArray;
}


//This function takes a dynamically allocated 2D array and sends
//it to the bit bucket in the sky, er, I mean deletes it.
//The first parameter will be the two dimensional array, viewed
//as a pointer to a pointer to an int. The second parameter is
//the number of rows in that array.
void deleteArray(int** A, int size)
{
	//This function is all you! Hint: first delete every row,
	//then you can delete the whole.
	
	for (int i = 0; i < size; i++) 
	{
		delete[] A[i];
	}
	delete[] A;
}