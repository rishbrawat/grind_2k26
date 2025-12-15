/* 
      Hashing is a technique to convert a key into an index of an array using a hash function so that data can be accessed quickly.      key ──> hash function ──> index ──> stored in hash table

      ex. we want to store numbers 0-99 in an array
         hash(key) = num % 10

      - key components:
         1. hash table: an array that stores our data
         2. hash function: convert key to array index
         3: collision handling: what to do when two key maps to same index

         the map is actually a array of buckets
         the bucket contains just one element
         if two keys hash the same index value, they form a linked list in that bucket


      key is passed to a hash function
      hash function converts the key into an index
      value is stored in the array

      index = hash(key) % total elements in the array
*/ 


/*
   unordered_map: is a hash table associative container, which stores key-value pairs.
      used for fast-lookups, insertion, deletion at O(1) tc.
      no ordering of the elements


      basic syntax
      unordered_map<key_type, value_type>name;



*/

// include the library
#include<unordered_map>
#include<iostream>
#include<string>
using namespace std;


int main() {
   unordered_map<int, string> students;

   // create and insert elements
   students[0] = "alice";
   students[1] = "john";

   // method 2, insert(): insert only if key does not exist, does not overwrite existing value.  its more safer than direct access map[index], returns a bool true if the value is inserted and false if not.
   students.insert({3, "charles"});

   // method 3, faster
   students.emplace(4, "david");

   // access elements, at() throws exception if the key is not present.
   auto firstStudent = students.at(0);
   cout << "first student in the map: " << firstStudent;


   // checking if a key exist, returns an iterator to element if found, safe for checking existence
   if(students.find(3) != students.end()) {
      cout << "\nkey found";
   }

   // returs 0 or 1
   if(students.count(3)) {
      cout << "\nkey exists";
   }

   // remove a single key
   students.erase(1);

   // remove all
   // students.clear()

   // size and empty check
   int size = students.size();
   cout << "\nsize of the student map: " << size;

   // check if map is empty or not
   cout << "\n" << students.empty();

   // iterate the map
   for(auto &p: students) {
      cout << p.first << " : " << p.second << endl; 
   }

   // How many buckets (slots) does the map currently have?
    cout << "Total Buckets: " << students.bucket_count() << endl;

    // Which bucket is key 3 sitting in?
    cout << "Key 3 is in bucket index: " << students.bucket(3) << endl;
    
    // How many elements are crowded in that specific bucket?
    // (If this is > 1, a collision happened!)
    cout << "Elements in bucket " << students.bucket(3) << ": " 
         << students.bucket_size(students.bucket(3)) << endl;

   // Only works in C++20 and above
    // Much cleaner than find() != end()
   //  if (students.contains(3)) {
   //      cout << "Key found using contains!";
   //  }
   return 0;
}  