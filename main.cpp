#include <iostream>

using namespace std;

void insertionSort(int *arr, int size) {
  for (int i = 0; i < size; i++) {

    if (i == 0) {
      continue;
    }

    int currentNum = *(arr + i);
    int j = 1;

    while ((i - j >= 0) && currentNum < *(arr + i - j)) {
      int secondNum = *(arr + i - j);

      int *currentPosition = arr + i - j;
      *currentPosition = currentNum;

      int *secondPosition = arr + i - j + 1;
      *secondPosition = secondNum;

      j++;
    }
  }

  for (int i = 0; i < size; i++) {
    cout << "Position " << i << ": " << *(arr + i) << endl;
  }
}

int main() {

  int stdArr[10] = {12, -5, 100, 0, 12, 7, 3, 55, 1, -9};

  // Insertion Sort
  insertionSort(stdArr, sizeof(stdArr) / sizeof(stdArr[0])); // Standard Array


  return 0;
}
