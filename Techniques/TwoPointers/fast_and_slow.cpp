#include<iostream>
using namespace std;

/*
   fast and slow pointers are variation of two pointer technique where:
   
   - slow pointer acts as a write index, it moves conditionally.
   - fast pointer is readonly index, it moves forward only
   - by using fast and slow pointers we eliminate the unecessary use of nested loops and reduce time complexity significantly.

   - both pointer initially start at the same value
   int slow = 0;
   int fast = 0;


   usage:
      cycle detections
      compression/filtering
      position discovery
      subarray problems (k elements)

*/

// simple example for slow and fast pointer
int removeElement(int *arr, int size, int element) {
   int slow = 0;

   for(int fast = 0; fast < size; fast++) {
      if(arr[fast] != element) {
         arr[slow] = arr[fast];
         slow++;
      }
   }
   return slow;
}

int main() {
   int size = 5;
   int arr[size] = {1,2,5,3,1};

   int element = 5;
   int boundary = removeElement(arr, size, element);


   for(int i = 0; i < size; ++i) {
      cout << arr[i] << ' ';
   }

}