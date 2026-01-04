/*
    sliding window is technique where we have to find a state or a result in a subarray of an array.
    there are two types of sw techniques:
        fixed size: where the size of the window is given explicitly, every subarray size is constant throughout the algorithm.
        common things asked in fixed size window is: maximum, minimum, average, sum of size k, or count the window size k based on a condition.

        window size(k) = right-left+1

        we use two pointers
            left: is used for expanding the window
            right: goes from 0 ot n-1 and moves only when window size exceeds k

        or
        we can use single pointer `right` who goes from 0 to n-1 and window becomes invalid if right>=k-1, we remove right-k

*/

// ex solution
#include<bits/stdc++.h>
using namespace std;

// using single pointer
int maxSubArrSumSinglePointer(vector<int>& nums, int k) {
    int sum = 0;
    int maxSum = INT_MIN;
    int size = nums.size();

    for(int i = 0; i < size; i++) {
        sum += nums[i];

        if(i >= k-1) {
            maxSum = max(maxSum, sum);
            sum -= nums[i- (k-1)];

        }
    }
    return maxSum;
}

// using two pointers, for me this is more understandable
int maxSubArrSumTwoPointer(vector<int>& nums, int k) {
    int left = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    int size = nums.size();

    for(int right = 0; right < size; right++) {
        sum += nums[right];

        if(right-left+1 == k) {
            maxSum = max(sum, maxSum);
            sum -= nums[left];
            left++;
        }
    }

    return maxSum;
} 

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int k = 3;
    
    int ans1 = maxSubArrSumSinglePointer(nums, k);
    cout << "ans using single pointer: " << ans1 << endl;

    int ans2 = maxSubArrSumTwoPointer(nums, k);
    cout << "ans using two pointer: " << ans2 << endl;

    return 0;
}