// filename: Program2
// Authors: Carter Mooring & Tarik Alauddin
// Date: Sept. 10th, 2018
// description:This program will allow the user to create a dynamic array for a list of integers.
// It will fill the array with random numbers from 0 to 99. It will then sort the array.
//Gonzaga University, CPSC 122, Dr. Yerion

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// creates a array called list with random numbers
// pre: the size of the list has been determined in getListSize();
//      Example: "Enter the size of your list -> ";
// post: createList contains the random array values based on the list size and will use passby reference.
void createList(int*& list, int sizeOfList);

// finds the largest value in the array and holds onto its spot
// pre: the array (list) has to have been created to be read.
//      Example: list[4] = 7
// post: findIndexOfLargest reads through each value in the array (list) and compares them until it finds the largest value, returning index of the number.
int findIndexOfLargest(int*& list, int sizeOfList, int currentItem);

// finds the largest value in the array and holds onto its spot
// pre: the array (list) has to have been created to be read.
//      Example: list[4] = 7
// post: findLargest reads through each value in the array (list) and compares them until it finds the largest value.
int findLargest(int*& list, int sizeOfList);

// finds the smallest value in the array and holds onto its spot
// pre: the array (list) has to have been created to be read.
//      Example: list[4] = 7
// post: findSmallest reads through each value in the array (list) and compares them until it finds the smallest value.
int findSmallest(int*& list, int sizeOfList);

// sums up all the values in the array.
// pre: the array (list) has to have been created to be read.
//      Example: list[4] = 7
// post: sumThem returns the sum of the numbers found in the array.
int sumThem(int* list, int sizeOfList);

// Prints the array using a loop.
// pre: the array (list) has to have been created to be read.
//      Example: list[4] = 7
// post: printList prints out all the values in the created array
//      Example: 4 6 8 9
void printList(int* list, int sizeOfList);

// Gets the desired array(list) size from the user
// pre: function has to be created and called in main to work.
//      Example: main()
// post: getListSize asks the user for a desired list size which is used in the create list function.
int getListSize();

// serves the same purpose as endl but in the form of a function.
// pre: the function for printNewLines has to be completed
// post: printNewLines will leave blank spaces down the screen in the desired amount.
void printNewLines(int desiredNumber);

// prints the largest value in the array(list).
// pre: findLargest has to have been executed.
//      Example: largest = i;
// post: pintLargestOne couts what the largest value in the array is.
void printLargestOne(int number);

// prints the smallest value in the array(list).
// pre: findSmallest has to have been executed.
//      Example: smallest = i;
// post: printSmallestOne couts what the smallest value in the array is.
void printSmallestOne(int number);

// prints the sum of the values in the array.
// pre: sumThem has to have been executed.
//      Example: sum += contents;
// post: printSum prints out the sum of values to the screen.
void printSum(int number);

// searches the array(list) for the value wanted by the user.
// pre: the users has delcared a wanted value.
// post: search now will know if the array contains the number or not.
void search(int list[], int listSize, int& target);

// outputs the result of the search function
// pre: input must be declared by search() and number must be chosen
// post: will output to the screen if the search function successfully found the target or not
void printSearchOutput(int intput, int number);

// asks the user for a value they want to search for in the array (list)
// pre: array(list) has been created.
// post: getTargetValue now contains the value that will be searched for.
void getTargetValue(int& target);

// deletes array in the heap
// pre: list must contain integers that are stored in the heap
// post: heap memory containg lists contents will be deleted
void deleteList(int*& list);

// sorts the values in the array from lowest to greatest by comparing values to one another and making
//    decisions based on if values are greater than one another if they are next to one another.
// pre: the array (list) has to have been created to be read.
//      Example: list[4] = 7
// post: insertionSort now contains the array(list) in order from lowest to greatest
void insertionSort(int*& list, int listSize);

// searches the whole array for the largest number. When it is found it holds it unitl a larger number is found.
//      If no larger number is found then that number is placed at the end of the array and the process starts again.
// pre: the array (list) has to have been created to be read.
//      Example: list[4] = 7
// post: selectionSort will now contain an array(list) that is in order from smallest to largest.
void selectionSort(int*& list, int listSize);

// swaps two desired items with one another by using other variables to hold their values.
// pre: an item to swap has to have been determined
//      Example: itemToSwap = i;
// post: swap switches the item wanted to be swapped with the other item that was desired to be swapped.
void swap(int*& list, int i, int itemToSwap);

// shows step by step how the selectionSort function is working
// pre: list needs to be filled with values, listSize must contain number of items in list[], i must be passed from selectionSort function containing one index to swap, itemToSwap must contain second index for swapping
// post: displays each step to the screen
void visualizationSelectionSort(int*& list, int listSize, int i, int itemToSwap);

// shows step by step how the insertionSort function is working
// pre: list needs to be filled with values, listSize must contain number of items in list[], must also have values from insertion sort.
// post: displays each step to the screen
void visualizationInsertionSort(int*& list, int listSize, int j, int nextItem);

int main()
{
  int* listptr;
	int listSize;
  int largestGuy;
  int smallestGuy;
  int sum;

	printNewLines(3);

	int seed = time(0);
	srand(seed);

	listSize = getListSize();
	createList(listptr, listSize);
	printNewLines(2);
	printList(listptr, listSize);

	printNewLines(3);

  smallestGuy = findSmallest(listptr, listSize);
  printSmallestOne(smallestGuy);
  largestGuy = findLargest(listptr, listSize);
  printLargestOne(largestGuy);
  sum = sumThem(listptr, listSize);
  printSum(sum);

  printNewLines(3);

  //selectionSort(listptr, listSize);
  printNewLines(3);
  //printList(listptr, listSize);


  insertionSort(listptr, listSize);
  printList(listptr, listSize);
  deleteList(listptr);
	return 0;
}

// creates a array called list with random numbers
// pre: the size of the list has been determined in getListSize();
//      Example: "Enter the size of your list -> ";
// post: createList contains the random array values based on the list size and will use passby reference.
void createList(int*& list, int sizeOfList)
{
	list = new int[sizeOfList];
	for (int k = 0; k < sizeOfList; k++)
	{
		*(list + k) = rand() & 90;
	}
}

// finds the largest value in the array and holds onto its spot
// pre: the array (list) has to have been created to be read.
//      Example: list[4] = 7
// post: findIndexOfLargest reads through each value in the array (list) and compares them until it finds the largest value, returning index of the number.
int findIndexOfLargest(int*& list, int sizeOfList, int currentItem)
{
  int temp = currentItem;
	for (int k = currentItem; k >= 0; k--)
  {
      if (*(list + k) > *(list + temp))
      {
        temp = k;
      }
  }
  return temp;
}

// finds the largest value in the array and holds onto its spot
// pre: the array (list) has to have been created to be read.
//      Example: list[4] = 7
// post: findLargest reads through each value in the array (list) and compares them until it finds the largest value.
int findLargest(int*& list, int sizeOfList)
{
  int largest = list[0];

  for (int i = 1; i < sizeOfList; i++)
  {
    if(list[i] > largest)
    {
      largest = list[i];
    }
  }
  return largest;
}

// finds the smallest value in the array and holds onto its spot
// pre: the array (list) has to have been created to be read.
//      Example: list[4] = 7
// post: findSmallest reads through each value in the array (list) and compares them until it finds the smallest value.
int findSmallest(int*& list, int sizeOfList)
{
  int smallest = list[0];

  for (int k = 1; k < sizeOfList; k++)
  {
    if (list[k] < smallest)
    {
      smallest = list[k];
    }
  }
  return smallest;
}

// Prints the array using a loop.
// pre: the array (list) has to have been created to be read.
//      Example: list[4] = 7
// post: printList prints out all the values in the created array
//      Example: 4 6 8 9
void printList(int* list, int sizeOfList)
{
	cout << "The list: " << endl;

	for (int k = 0; k < sizeOfList; k++)
	{
        cout << list[k] << endl;
	}
}

// Gets the desired array(list) size from the user
// pre: function has to be created and called in main to work.
//      Example: main()
// post: getListSize asks the user for a desired list size which is used in the create list function.
int getListSize()
{
	int size;
	cout << "Enter the size of your list -> ";
	cin >> size;
	return size;
}

// serves the same purpose as endl but in the form of a function.
// pre: the function for printNewLines has to be completed
// post: printNewLines will leave blank spaces down the screen in the desired amount.
void printNewLines(int desiredNumber)
{
	for (int k = 0; k < desiredNumber; k++)
	{
		cout << endl;
	}
}

// prints the largest value in the array(list).
// pre: findLargest has to have been executed.
//      Example: largest = i;
// post: pintLargestOne couts what the largest value in the array is.
void printLargestOne(int number)
{
	cout << "Largest value is: " << number << endl;
}

// prints the smallest value in the array(list).
// pre: findSmallest has to have been executed.
//      Example: smallest = i;
// post: printSmallestOne couts what the smallest value in the array is.
void printSmallestOne(int number)
{
	cout << "Smallest value is: " << number << endl;
}

// prints the sum of the values in the array.
// pre: sumThem has to have been executed.
//      Example: sum += contents;
// post: printSum prints out the sum of values to the screen.
void printSum(int number)
{
	cout << "The sum of the array is: " << number << endl;
}

// sums up all the values in the array.
// pre: the array (list) has to have been created to be read.
//      Example: list[4] = 7
// post: sumThem returns the sum of the numbers found in the array.
int sumThem(int* list, int sizeOfList)
{
  int sum = 0;
  for (int k = 0; k < sizeOfList; k++)
  {
    sum += list[k];
  }
  return sum;
}

// searches the array(list) for the value wanted by the user.
// pre: the users has delcared a wanted value.
// post: search now will know if the array contains the number or not.
void search(int list[], int listSize, int& target)
{
  for (int k = 0; k < listSize; k++)
  {
    if (*(list + k) == target) {
      printSearchOutput(1, target);
    }
  }
  printSearchOutput(0, target);
}

// outputs the result of the search function
// pre: input must be declared by search() and number must be chosen
// post: will output to the screen if the search function successfully found the target or not
void printSearchOutput(int intput, int number)
{
  if (input == 1)
  {
    cout << number << " was successfully found in the array."
  } else if (input == 0)
  {
    cout << number << " was not found in the array."
  }
}

// asks the user for a value they want to search for in the array (list)
// pre: array(list) has been created.
// post: getTargetValue now contains the value that will be searched for.
void getTargetValue(int& target)
{
  cout << "Please insert the number you are searching for: " << endl;
  cin >> target;
}

// deletes array in the heap
// pre: list must contain integers that are stored in the heap
// post: heap memory containg lists contents will be deleted
void deleteList(int*& list)
{
  delete [] list;
}

// sorts the values in the array from lowest to greatest by comparing values to one another and making
//    decisions based on if values are greater than one another if they are next to one another.
// pre: the array (list) has to have been created to be read.
//      Example: list[4] = 7
// post: insertionSort now contains the array(list) in order from lowest to greatest
void insertionSort(int*& list, int listSize)
{
  for (int i = 1; i < listSize; i++)
  {
    int nextItem = list[i]; //the next value being checked
    int j = i; //sets another value equal to i's place

    while ((j > 0) && (list[j-1] > nextItem))
    { //checks to see if the last item is greater than the one being checked
      list[j] = list[j-1]; //j now holds the place of the greater value (the last one)
      j--; //now that the greater number is in the next value spot, go back to last item spot
    }
    list[j] = nextItem; //because we went back to last item spot, now we can put the smaller number in it
    visualizationInsertionSort(list, listSize, j, nextItem);
  }
}

// searches the whole array for the largest number. When it is found it holds it unitl a larger number is found.
//      If no larger number is found then that number is placed at the end of the array and the process starts again.
// pre: the array (list) has to have been created to be read.
//      Example: list[4] = 7
// post: selectionSort will now contain an array(list) that is in order from smallest to largest.
void selectionSort(int*& list, int listSize)
{
  int itemToSwap;
  for (int i = listSize - 1; i >= 0; i--)
  {
    itemToSwap = findIndexOfLargest(list, listSize, i);
    swap(list, i, itemToSwap);
    visualizationSelectionSort(list, listSize, i, itemToSwap);
  }
}

// swaps two desired items with one another by using other variables to hold their values.
// pre: an item to swap has to have been determined
//      Example: itemToSwap = i;
// post: swap switches the item wanted to be swapped with the other item that was desired to be swapped.
void swap(int*& list, int i, int itemToSwap)
{
  int first = list[i];
  list[i] = list[itemToSwap];
  list[itemToSwap] = first;
}

// shows step by step how the selectionSort function is working
// pre: list needs to be filled with values, listSize must contain number of items in list[], i must be passed from selectionSort function containing one index to swap, itemToSwap must contain second index for swapping
// post: displays each step to the screen
void visualizationSelectionSort(int*& list, int listSize, int i, int itemToSwap)
{
  for (int k = 0; k < listSize; k++)
  {
    if (k == i || k == itemToSwap)
    {
      cout << " | *" <<  list[k];
    } else
    {
      cout << " | " << list[k];
    }
  }
  cout << " |" << endl;
  cout << "Swapped: list[" << i << "] : " << list[i] << " with list[" << itemToSwap << "] : " << list[itemToSwap] <<;
  printNewLines(2);
}

// shows step by step how the insertionSort function is working
// pre: list needs to be filled with values, listSize must contain number of items in list[], must also have values from insertion sort.
// post: displays each step to the screen
void visualizationInsertionSort(int*& list, int listSize, int j, int nextItem)
{
  for (int i = 0; i < listSize; i++)
  {
    if ((i == j) || (i == nextItem))
      {
        cout << " | " << list[i];
      } else
      {
        cout << " | " << list[i];
      }
  }
  cout << " |" <<;
  printNewLines(2);
}
