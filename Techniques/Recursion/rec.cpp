#include<iostream>
using namespace std;

/*
    recursion is a technique where function calls  itself untill the base condition is met .

    base conditon: termination condition of recursion
    recurse condition: that will compute the value for base condition
*/

int factorial(int n) {
    if(n <= 1) {
        return 1;
    }
    return (n * factorial(n-1));
}


// tail recursion: is a special type of recursion where the recusive call is the last thing the function does.

int tailFact(int n, int accumulator = 1) {
    if(n <= 1) {return accumulator;}
    return tailFact(n - 1, n * accumulator);
}


int main() {
    cout << factorial(5) << ' ' << tailFact(5);
}