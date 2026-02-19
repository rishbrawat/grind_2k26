/*
    two sets are called disjoint sets if they don't have any element in common. the disjoint set is used to store such sets.

    - merging two disjoint sets to single set using union operation.
    - finding representative of a disjoint set using find op.
    - check if two elements are same or not.


*/

#include<iostream>
#include<vector>
using namespace std;

class UnionFind {
    vector<int> parent;
    vector<int> rank;

    public:
        UnionFind(int size) {
            parent.resize(size);
            rank.resize(size, 0);


            // initialize the parent array with element as its own representative
            for(int i = 0; i < size; ++i) {
                parent[i] = i;
            }
        }

        // core operations
        
        // find
        int find(int i) {
            if(parent[i] == i) {
                return i;
            }

            return parent[i] = find(parent[i]);

        }

        // unite/merge/union
        void unite(int i, int j) {
            int rootI = find(i);
            int rootJ = find(j);

            if(rootI != rootJ) {
                if(rank[rootI] < rank[rootJ]) {
                    parent[rootI] = rootJ;
                }

                else if(rank[rootI] > rootJ) {
                    parent[rootJ] = rootJ;
                }

                else {
                    parent[rootI] = rootJ;
                    rank[rootJ]++; 
                }
            } 
        }
};

int main() {
    int size = 5;

    UnionFind uf(size);

    uf.unite(1, 2);
    uf.unite(3, 4);

    bool inSameSet = (uf.find(1) == uf.find(2));
    cout << "are 1 and 2 in the same set? " << (inSameSet ? "yes":"no");

    return 0;
}