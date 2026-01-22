#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);   cin.tie(nullptr);

void merge(vector<int>& nums, int left, int right, int mid) {
    // first we compute the lengths for 2 sublists
    int n1 = mid-left+1;
    int n2 = right-mid;

    // now we create two arrays of n1 and n2 size
    vector<int> L(n1), R(n2);

    // now we fill the elements in them
    // fill the left sublist
    for(int i = 0; i < n1; ++i){
        L[i] = nums[left+i];
    }
    // fill the right sublist
    for(int j = 0; j < n2; ++j) {
        R[j] = nums[mid+1+j];
    }


    // now we need to sort the array
    int i = 0, j = 0, k = left; // indices for sorting

    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) {
            nums[k++] = L[i++];
        }
        else {
            nums[k++] = R[j++];
        }
    }

    while(i < n1) {
        nums[k++] = L[i++];
    }
    while(j < n2) {
        nums[k++] = R[j++];
    }
}


void mergeSort(vector<int>& nums, int left, int right) {
    // base condition for recursion
    if(left >= right) {
        return; 
    }

    // we will recurse now
    int mid = left + (right-left)/2;

    mergeSort(nums, left,mid);
    mergeSort(nums, mid+1, right);
    merge(nums,left, right, mid);
}


int main() {
    fastio;
    vector<int> arr = {5,4,1,3,-6,1};
    mergeSort(arr, 0, arr.size()-1);

    for(auto x: arr) {
        cout << x << ' ';
    }

    return 0;
}