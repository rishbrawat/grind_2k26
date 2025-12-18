/*

   unordered_map is an associatvive container, that stores the data in a key - value pairs with unique keys, the data in the table is unsorted and it uses separate chaining method(lists).
   avg : O(1) for insert, search, erase.
 
   also does rehashing if max_load_factor (a) > 1 (O(1): amortized)

   the data is stored in a unsorted manner, for sorted data <map> is used which uses red-black tree.

   When NOT to Use unordered_map

    Need sorted order
    Small constraints (use array)
    Very tight memory
    Key range is small & fixed



*/

#include<unordered_map>
#include<iostream>
#include<string>
using namespace std;

int main() {
   // declare the map, keytype = string, valtype = int
   unordered_map<string, int> mp;
   // create a key "rishabh" if it does not exist and assign it a value of 25
   mp["rishabh"] = 25;

   // insert method takes key value pairs inside the brackets {}, will insert only if the key does not exist, will ignore if key exists
   mp.insert({"john", 20});

   // find() searches for a key, returns an iterator if found, otherwise returns mp.end()
   auto itr = mp.find("rishabh");
   // correct usage
   if(mp.find("rishabh") != mp.end()) {
      cout << "key exists" << endl;
   }

   // count method for finding the existence of a key, returns 1 if found 0 if not
   if(mp.count("rishabh")) {
      cout << "key exists!" << endl;
   }

   // update the existing key
   mp["john"] = 15;
   mp["sonia"] = 12;
   mp["ramesh"] = 17;
   // iterate the map

   for(auto& p: mp) {
      cout << p.first << " " << p.second << '\n';
   }
   // erase method: erases a key and value, takes key as param

   cout << endl;
   mp.erase("ramesh");
   for(auto& p: mp) {
      cout << p.first << " " << p.second << '\n';
   }

   return 0;
}
