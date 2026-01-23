#include<queue>
#include<iostream>
using namespace std;


int main() {
    queue<int> q;
    q.push(10);
    q.push(20);

    q.pop();

    // the first element
    q.front();

    // last element
    q.back();
}

