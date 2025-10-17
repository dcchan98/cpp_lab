#pragma once
#include <bits/stdc++.h>

using namespace std;

class ufds {
    vector<int> rank, parent;

public:
    // Constructor to initialize sets
    ufds(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        // Initially, each element is in its own set
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        int root = parent[i];
        if (parent[root] != root) {
            return parent[i] = find(root);
        }
        return root;
    }

    // Union of sets containing x and y
    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        // If they are in the same set, no need to union
        if (xRoot == yRoot) return;
        // Union by rank
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        }
        else if (rank[yRoot] < rank[xRoot]) {
            parent[yRoot] = xRoot;
        }
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};
