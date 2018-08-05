/*
binary search implimented in c++
binary search for finding any occurence of target
binary search for finding first occourence of target
binary search for finding last occurence of target
runtime: O(log(n))
written by: dannyallover
date: 08/05/2018
*/
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> eles, int target, int &numComparisons) {
  numComparisons = 0;
  int low = 0;
  int high = eles.size() - 1;
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

int binarySearchFirst(vector<int> eles, int target, int &numComparisons) {
  numComparisons = 0;
  int low = 0;
  int high = eles.size() - 1;
  while(low <= high) {
    numComparisons++;
    int mid = low + (high - low) / 2;
    if(eles[mid] == target) {
      while(eles[mid] == target) {
        mid--;
        numComparisons++;
      }
      return mid + 1;
    }
    else if(eles[mid] < target)
      low = mid + 1;
    else if(eles[mid] > target)
      high = mid - 1;
  }
  return -1;
}

int binarySearchLast(vector<int> eles, int target, int &numComparisons) {
  numComparisons = 0;
  int low = 0;
  int high = eles.size() - 1;
  while(low <= high) {
    numComparisons++;
    int mid = low + (high - low) / 2;
    if(eles[mid] == target) {
      while(eles[mid] == target) {
        mid++;
        numComparisons++;
      }
      return mid - 1;
    }
    else if(eles[mid] < target)
      low = mid + 1;
    else if(eles[mid] > target)
      high = mid - 1;
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
  int pos;

  pos = binarySearch(eles, target, numComparisons);
  cout << "For generic binary search:" << endl;
  cout << "\t Found at pos: " << pos << endl;
  cout << "\t The number of comparisons was: " << numComparisons << endl;

  pos = binarySearchFirst(eles, target, numComparisons);
  cout << "For binary search of first occurence of target:" << endl;
  cout << "\t Found at pos: " << pos << endl;
  cout << "\t The number of comparisons was: " << numComparisons << endl;

  pos = binarySearchLast(eles, target, numComparisons);
  cout << "For binary search of last occurence of target:" << endl;
  cout << "\t Found at pos: " << pos << endl;
  cout << "\t The number of comparisons was: " << numComparisons << endl;
}
