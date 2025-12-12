#include<iostream>
#include<vector>
#include<algorithm> // for sorting, finding and reversing

using namespace std; // bad practice

int main() {

   // initialization
   vector<int> a; // empty vector
   vector<int> b(5); // size is 5 , all zeros (Default)
   vector<int> c(5, -1); // size is 5, all -1
   vector<int> d {1,2,3,4,5}; // with values
   vector<int> e = {1,2,3,4,5}; // similar as above
   vector<int> f = e; // copy vector e to f

   // size and capacity
   int size = a.size(); // returns total number of elements in the vector
   int capacity = a.capacity(); // returns allocated space to vector
   a.reserve(10); // reserves space for 10 integers/elements
   a.shrink_to_fit(); // shrinks the vector to total elements size (not guaranteed)

   // adding/removing elements
   int x = 10;
   a.push_back(x); // append 
   a.emplace_back(x-5); // construct in place
   a.pop_back(); // removes last
   // a.insert(size-1, x); requires iterator
   // a.erase(pos); requires iterator
   a.clear(); // removes all elements

   // iterators, algorithmic patterns next 

   // iterators

   // forward iteration
   vector<int>::iterator pos;
   for(pos=d.begin(); pos<d.end(); ++pos) {
      cout << *pos << ' ';
   } cout << endl;

   // backward iteration
   for(pos=d.end()-1; pos>=d.begin(); --pos) {
      cout << *pos << ' '; 
   } cout << endl;


   // iterator invalidation
   vector<int> v;
   auto it = v.begin();
   v.push_back(1); // iterator invalidated, it becomes a dangling pointer which is unsafe
   // now re assign the it to be safe
   it = v.begin(); 

   // reverse iterators
   for(auto rit = v.rbegin(); rit != v.rend(); ++rit ) {
      cout << *rit << ' ';
   } cout << endl;

   // remove elements safely
   for (auto itr = v.begin(); itr < v.end(); ) {
      if(*itr%2 == 0) {
         itr = v.erase(itr);
      } else {
         ++itr;
      }
   }

   // important algorithms
   vector<int> v2 = {5,2,4,6,-1,0,-2};

   sort(v2.begin(), v2.end()); // ascending sort
   for(auto i = v2.begin(); i < v2.end(); ++i) {
      cout << *i << ' ';
   } cout << endl;

   sort(v2.rbegin(), v2.rend()); // reverse sort
   for(auto i = v2.begin(); i < v2.end(); ++i) {
      cout << *i << ' ';
   } cout << endl;

   // reverse 
   reverse(v2.begin(), v2.end());

   auto i = find(v2.begin(), v2.end(), 5);
   cout << &(*i);


   // find
   return 0;

}
