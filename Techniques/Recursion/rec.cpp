#include<iostream>
using namespace std;

/*
    recursion is a technique where function calls  itself untill the base condition is met .

    base conditon: termination condition of recursion
    recurse condition: that will compute the value for base condition
*/

int factorial(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    else {
        return (n * factorial(n-1));
    }
}

int main() {
    cout << factorial(5);
}