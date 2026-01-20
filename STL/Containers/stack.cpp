#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
    // stack has lifo policy
    // jo last aya wo phle jaega

    stack<string> s;
    s.push("one");
    s.push("two");
    s.push("three");
    s.push("four");
    s.push("five");

    // get the top element
    cout << s.top() << '\n';
    // remove the top element
    s.pop();
    cout << s.top() << '\n';

    cout << boolalpha << s.empty() << '\n';

    // swap two stacks
    stack<string> s2;
    s2.swap(s);

    cout << s.empty();
}