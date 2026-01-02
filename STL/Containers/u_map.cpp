/*
   an uordered_map is an associative container that stores the data in key:value pairs. where keys are unqiue, and elements are organized using a hashtable.

   at high level
   key->hashing_function(key)->index generated->store the value at that index.


   core characteristics
      no ordering of the elements.
      each key is unique.

*/

#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
   // create an empty map
   unordered_map<int, int> mp;
   // insert an element
   mp[0] = 20;

   // using insert method: it wont overwrite the key if it exists already,
   mp.insert({10, 20});

   // direct access
   int val = mp[0];

   // check existence of a key
   auto key = 0;
   if(mp.find(key) != mp.end()) {
      cout << "key found!" << '\n';
   }


   // find frequency of item 
   unordered_map<int, int> freq;
   int arr[4] = {1,2,3,3};
   for(auto x: arr) {

      // okay, so its like for the first time, it just starts at 0 for every value, and on each iteration the x is updated. so its a freqeuncy counting.
      freq[x]++;
   }
   // oww there are no indexes, so basically we are only storing values and frequencies.
   for(auto& x: freq) {
      cout << x.first << ' ' << x.second << '\n';
   }
   
   cout << "value 3 appeared on map: " << freq[3] << " times" << endl;


   // find method
   /*
      find() method searches for key in the map, and returns an iterator.
      if the key is not in the map, it returns end() which is iterator as well

      end() means one past the last element, used only for comparisons, never dereference it

      dont use freq[x] > 1 to check frequencies, it might insert the key


      the method is useful for detecting duplicates in the map
   */
   auto it = freq.find(3);
   if(it == freq.end()) {cout << "key not found in the map" << endl;}
   else {cout << "key found in the map!"<<endl;}

   if(it!=freq.end()) {
      cout << it->second;
   }


   

}