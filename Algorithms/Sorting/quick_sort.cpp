#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);   cin.tie(nullptr);


/*
    quicksort algorithm is another divide and conquer algorithm, division or partition works differently then merge sort.

    - pick one element called the pivot
    - rearrange the array so
        elements <= pivot goes to the left
        elements >= pivot goes to the right
    - now pivot is in the final sorted position
    - recursively do for remaining elements

    if the pivot is picked, it will be sorted and we don't touch it again
*/

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left;

    for(int j = left; j < right; ++j) {
        if(nums[j] <= pivot) {
            swap(nums[i], nums[j]);
            i++;
        }
    }

    swap(nums[i], nums[right]);
    return i;
}

void quickSort(vector<int>& nums, int left, int right) {
    if(left >= right) return;

    int p = partition(nums, left, right);
    quickSort(nums, left, p-1);
    quickSort(nums, p+1, right);
}


int main() {
    fastio;
    vector<int>nums = {5,-5,1,6,-8,7,0};
    quickSort(nums, 0, nums.size()-1);

    for(auto& x: nums) {
        cout << x << ' ';
    }

    return 0;
}