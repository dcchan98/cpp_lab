# C++ Lab

- Custom python print like function for stl 

# To Implement print
- Sequence Containers
  ~~- vector~~
  ~~- deque~~

- Associative Containers
  - set
  - multiset
  - map
  - multimap
  
- Unordered Associative Containers
    - unordered_set
    - unordered_multiset
    - unordered_map
    - unordered_multimap
    
- Container adaptors
  - Priority queue
  
- Tuple 
  

## Why this print function?

### For vectors
Printing nested containers is usually messy and unreadable.  
Humans can comfortably visualize **1D and 2D structures** (like arrays and matrices).

- **1D vectors** → printed inline, e.g. `[1, 2, 3]`

```cpp
vec<int> dp1(5, 3);
PRINT(dp1);
```
**Output:**
```
dp1 : Line  172
[3, 3, 3, 3, 3]
```

- **2D vectors** → printed as matrices, e.g.
```cpp
vec<vec<int>> dp2(3, vec<int>(4));
fill_running_numbers(dp2);
PRINT(dp2);
```
**Output:**
```
dp2 : Line  173
[
  [1, 2, 3, 4]
  [5, 6, 7, 8]
  [9, 10, 11, 12]
]
```

- **3D+ vectors** → printed slice by slice with labels (`Matrix 0`, `Matrix 1`, …) so you can follow along layer by layer instead of staring at deeply nested brackets.

```cpp
vec<vec<vec<vec<int>>>> dp4d(2, vec<vec<vec<int>>>(3, vec<vec<int>>(4, vec<int>(5))));
fill_running_numbers(dp4d);
PRINT(dp4d);
```
**Output:**
```
dp4d : Line  170
-- Matrix [0, 0] --
[
  [1, 2, 3, 4, 5]
  [6, 7, 8, 9, 10]
  [11, 12, 13, 14, 15]
  [16, 17, 18, 19, 20]
]
-- Matrix [0, 1] --
[
  [21, 22, 23, 24, 25]
  [26, 27, 28, 29, 30]
  [31, 32, 33, 34, 35]
  [36, 37, 38, 39, 40]
]
-- Matrix [0, 2] --
[
  [41, 42, 43, 44, 45]
  [46, 47, 48, 49, 50]
  [51, 52, 53, 54, 55]
  [56, 57, 58, 59, 60]
]
-- Matrix [1, 0] --
[
  [61, 62, 63, 64, 65]
  [66, 67, 68, 69, 70]
  [71, 72, 73, 74, 75]
  [76, 77, 78, 79, 80]
]
-- Matrix [1, 1] --
[
  [81, 82, 83, 84, 85]
  [86, 87, 88, 89, 90]
  [91, 92, 93, 94, 95]
  [96, 97, 98, 99, 100]
]
-- Matrix [1, 2] --
[
  [101, 102, 103, 104, 105]
  [106, 107, 108, 109, 110]
  [111, 112, 113, 114, 115]
  [116, 117, 118, 119, 120]
]
```
### other containers 
not yet implemented

## Compile and Run

```bash
g++-15 -std=c++23 -O2 -g -o build/main main.cpp
./build/main
```

- `-std=c++23` : Use the latest C++ standard
- `-O2` : Optimization for speed
- `-g` : Include debug symbols for debugging

## Usage

1. Clone the repository:

```bash
git clone <your-repo-url>
cd cpp-lab
```

2. Edit `main.cpp` or add new files for testing algorithms.
3. Compile and run as shown above.

## Notes

- This repository is meant for **C++ experimentation**.
- Not intended as a production library.

##
