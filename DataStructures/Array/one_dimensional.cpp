#include<iostream>
using namespace std;

// not writing any theory, wrote enough theory on notebook


int main() {

   // static array with defined size
   int arr1[5] = {}; // size is 5, all zeros

   int size = 5;
   int arr2[size];


   cout << "size of the arr1: " << sizeof(arr1) << " bytes" << endl; // 20 bytes

   // accessing elements

   // first element
   int first_element = arr1[0];


   // get total elements or array size
   int size_of_array = sizeof(arr1)/sizeof(arr1[0]); // sizeof arr1 = 20 bytes divided by sizeof arr1[0] = 4 bytes = 20/4 = 5
   cout << "total elements in the array: " << size_of_array << endl;


   // array traversal
   for (int i = 0; i < size_of_array; ++i) {
      arr1[i+1] = arr1[i] + 10;
      cout << "index: " << i << " element: " << arr1[i] << '\n';
   } cout << endl;


   // finding minimum, maximum, sum of the elements
   
   int nums[size_of_array] = {1,10,-245,34,-11};
   int min = nums[0],max = nums[0],sum = 0;
   
   for(int i = 0; i < size_of_array; ++i) {
      sum += nums[i];
      if(nums[i] < min) min = nums[i];
      if(nums[i] > max) max = nums[i];
   }

   cout << min << '\n' << max << '\n' << sum << '\n';


   // dynamic array
   int* darr = new int[size_of_array]();

   for(int i = 1; i < size_of_array; i++) {
      *(darr+i) = *(darr+ (i-1))+10;
      cout << "index: " << i << " element: " << *(darr + i) << '\n';
   }

   delete[] darr;

}