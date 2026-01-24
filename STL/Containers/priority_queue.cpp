#include<queue>
#include<iostream>
using namespace std;

int main() {
    priority_queue<int> q;
    q.push(10);
    q.push(20);

    q.pop();
    cout << q.top() << ' ' << q.empty() << ' ' << q.size();

    return 0;
}