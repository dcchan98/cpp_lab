#pragma once
#include <bits/stdc++.h>

using namespace std;
// TODO DC change combinations and permutations to generic

inline vector<vector<int> > combinations(vector<int> vec) {
    int n = vec.size();
    ranges::sort(vec);
    // recursively modified states
    vector<vector<int> > res;
    vector<int> taken;
    auto recurse = [&](this auto func, int startIndex = 0)-> void {
        res.push_back(taken);
        for (int i = startIndex; i < n; i++) {
            if (i > startIndex && vec[i] == vec[i - 1]) continue; // prune for unique elements
            taken.push_back(vec[i]);
            func(i + 1); // populate next element recursively, limited by index
            taken.pop_back();
        }
    };
    recurse();
    return res;
}

/// generate permutations
inline vector<vector<int> > permutations(vector<int> vec) {
    int n = vec.size();
    ranges::sort(vec);
    // recursively modified states
    vector<int> visited(n); // marks if index has been visited
    vector<vector<int> > res;
    vector<int> taken;
    auto recurse = [&](this auto func)-> void {
        if (taken.size() == n) {
            res.push_back(taken);
            return;
        };
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            if (i > 0 && vec[i] == vec[i - 1] && !visited[i - 1]) continue; // prune for unique elements
            visited[i] = true;
            taken.push_back(vec[i]);
            func(); // populate next element recursively
            visited[i] = false;
            taken.pop_back();
        }
    };
    recurse();
    return res;
}
