#include<iostream>
using namespace std;


/*
   boundary pointers is a technique where to pointers are at opposite boundaries and they move inwards.
      ex arch. 
         - [left..................................right]

   left pointer: the starting index of the array
   right pointer: the last most index of the array


   please remember that the array must be sorted before using two pointers.

   useful when:

   finding pairs
   swapping element
*/
bool hasPair(int *arr, int size, int target) {
   // initialize two boundaries

   // left boundary for the starting index
   int left = 0;

   // right boundary for the end index
   int right = size-1;

   // make sure the boundaries dont cross
   while(left < right) {

      int sum = arr[left] + arr[right];

      if(sum == target) { 
         return true;
      }
      else if(sum < target){
         // move the starting index by 1 so we get higher values} 
         left++; 
      } 

      else {
         right--;
      }
   }

   return false;
}

void bubbleSort(int *arr, int size) {
   for(int i = 0;i < size; ++i) {
      bool swapped = false;

      for(int j = 0; j < size-i-1; ++j) {
         if(arr[j] > arr[j+1]) {

            // swap j with j+1
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;

            swapped = true;
         }
      }

      if(swapped==false) {
         break;
      }
   }
   return;
}


int main() {
   int size = 5;
   int arr[size] = {1,3,45,7,8};
   int target = 48;

   // must sort the array
   bubbleSort(arr, size);

   // now use the function
   bool isFound = hasPair(arr, size, target);

   cout << isFound;

   return 0;
}