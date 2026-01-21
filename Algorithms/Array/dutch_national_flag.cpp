/*
    dutch national flag algorithm works specifically when we need to sort an array of 3 distinct elements, it uses three pointers to partition the array into four sections, 0s 1s 2s and unsorted

    pointers:
        low : tracks where next 0 should go
        mid : iterates through the array
        high : tracks where next 2 should go

*/
#include<vector>
#include<iostream>
using namespace std;


void dnf(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size()-1;

    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } 
        else if(nums[mid] == 1) { mid++;}
        else {
            swap(nums[mid], nums[high]);
            high--;
        } 
    }
}