/*
exponential or gallop search implemented in c++
this search is typically used for when list is infinite/unbounded
can beat binary search for bounded lists when element is close to beginning
runtime: O(log(n))
written by: dannyallover
date: 08/05/2018
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> eles, int target, int bound, int &numComparisons) {
  int low = 0;
  int high = bound;
  while(low <= high) {
    numComparisons++;
    int mid = low + (high - low) / 2;
    if(eles[mid] == target)
      return mid;
    else if(eles[mid] < target)
      low = mid + 1;
    else if(eles[mid] > target)
      high = mid - 1;
  }
  return -1;
}

int exponentialSearch(vector<int> eles, int target, int &numComparisons) {
  numComparisons = 1;
  int i = 1;
  while(i <= eles.size() && eles[i] <= target) {
    i = i * 2;
    numComparisons++;
  }
  int pos = binarySearch(eles, target, min(i, (int)eles.size()), numComparisons);
  return pos;
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
  int pos;

  pos = exponentialSearch(eles, target, numComparisons);
  cout << "Found at pos: " << pos << endl;
  cout << "The number of comparisons was: " << numComparisons << endl;
}
