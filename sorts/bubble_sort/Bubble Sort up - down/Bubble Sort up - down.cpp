#include <iostream>
#include <random>

const int arraySize = 5;

void outputArray(int* ptrArray);
void randomArrayFilling(int* ptrArray, int A, int B);
void bubbleSort(int* ptrArray, bool sort);

int main()
{
	int array[arraySize]{};
	int a = 2;
	int b = 10;
	bool sortUpDown = false; // true - sort up, false - sort down

	randomArrayFilling(array, a, b);
	outputArray(array);
	bubbleSort(array, sortUpDown);

	return 0;
}

// Output Array to the Console
void static outputArray(int* ptrArray) {
	for (int i = 0; i < arraySize; i++) {
		std::cout << *(ptrArray + i) << "\t";
	}
	std::cout << std::endl;
}

// Filling an array with random numbers in [A, B] diap
void static randomArrayFilling(int* ptrArray, int A, int B) {
	srand(time(0));
	for (int i = 0; i < arraySize; i++) {
		*(ptrArray + i) = rand() % (B - A + 1) + A;
	}
}

// Bubble Sort
void static bubbleSort(int* ptrArray, bool sort) {
	int tmp{};

	for (int i = 0; i < arraySize; i++) {
		bool swapped = false;

		// In each iteration we have +1 sorted number. We don't need them next, so " - i". 
		for (int j = 0; j < arraySize - 1 - i; j++) {
			if (!sort) {
				if (*(ptrArray + j) < *(ptrArray + j + 1)) {
					tmp = *(ptrArray + j);
					*(ptrArray + j) = *(ptrArray + j + 1);
					*(ptrArray + j + 1) = tmp;
					swapped = true;
				}
			}
			else {
				if (*(ptrArray + j) > *(ptrArray + j + 1)) {
					tmp = *(ptrArray + j);
					*(ptrArray + j) = *(ptrArray + j + 1);
					*(ptrArray + j + 1) = tmp;
					swapped = true;
				}
			}
		}
		outputArray(ptrArray);
		// If there were no manipulations - array is sorted
		if (!swapped) break;
	}
}