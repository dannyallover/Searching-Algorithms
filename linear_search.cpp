/*
linear search implemented in c++
runtime: O(n)
written by: dannyallover
date: 08/05/2018
*/
#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int> eles, int target, int &numComparisons) {
  for(int i = 0; i < eles.size(); i++) {
    numComparisons++;
    if(eles[i] == target)
      return i;
  }
  return -1;
}

int main() {
  cout << "Enter the number of elements in your list: ";
  int numElements;
  cin >> numElements;

  vector<int> eles;
  int num = 0;
  cout << "Enter the numbers in your list now: " << endl;
  for(int i = 0; i < numElements; i++) {
    cin >> num;
    eles.push_back(num);
  }

  int target = 0;
  cout << "Enter your target value " << endl;
  cin >> target;

  int numComparisons = 0;
  int pos = linearSearch(eles, target, numComparisons);

  cout << "Found at pos: " << pos << endl;
  cout << "The number of comparisons was: " << numComparisons << endl;
}
