# cpprint

`cpprint` is a **header-only C++ library** that makes printing STL containers, tuples, maps, and even priority queues actually enjoyable. Think of it as Python’s `print()` for C++—but with **line numbers, variable names, and nice formatting**, so you can actually read what’s going on.

I made `cpprint` because I wanted to practice C++ and solve some LeetCode problems—but every time I had to print a vector, I found myself writing:

```cpp
for (int v : myVec) std::cout << v << std::endl;
```

…and then another loop for another vector, and another loop for a tuple… and before I knew it, I had completely lost my **programming flow**. It was soul-crushing. 😅

`cpprint` solves this problem. Now I can just:

```cpp
std::vector<int> v = {1,2,3,4};
cpprint::pprint(v);
```

…and instantly see the contents, beautifully formatted, without breaking my concentration.

### Who is this for?

1. **New programmers** – Especially if you’re coming from a type-safe language like Python, where `print()` magically prints everything. Welcome to C++… let `cpprint` be your bridge.
2. **Competitive programmers & LeetCoders** – Fast debugging without breaking your coding flow. Save time and sanity when testing your algorithm.
3. **C++ explorers** – If you just want to poke around in C++ without constantly writing loops for printing, this makes life a lot more convenient.

In short: `cpprint` keeps you **focused, sane, and slightly happier** while you code in C++.
---

## Features

- **Supported types:**
    - `std::vector`
    - `std::queue` / `std::priority_queue`
    - `std::map` / `std::unordered_map`
    - `std::set` / `std::unordered_set`
    - `std::tuple`
    - `std::pair
---

## Installation

1. **Download the single header** from [generated/cpprint.hpp](generated/cpprint.hpp)
2. Place it in your project folder or an `include/` directory:

```
my_project/
├─ include/
│  └─ cpprint.hpp
├─ src/
│  └─ main.cpp
```

---

## Usage

```cpp
#include "generated/cpprint.hpp"
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace cpprint;

int main() {
    std::cout << "Printing a string:\n";
    pprint("a");
    std::cout << "\n";

    std::cout << "Printing 1D vector:\n";
    std::vector<int> v1 = {1, 2, 3, 4};
    pprint(v1);
    std::cout << "\n";

    std::cout << "Printing 2D vector:\n";
    std::vector<std::vector<int>> v2 = {{1, 2}, {3, 4}};
    pprint(v2);
    std::cout << "\n";

    std::cout << "Printing 3D vector:\n";
    std::vector<std::vector<std::vector<int>>> v3 = {{{1,2},{3,4}}, {{5,6},{7,8}}};
    pprint(v3);
    std::cout << "\n";

    std::cout << "Printing tuple containing vector:\n";
    std::tuple<int, std::vector<int>> t = {42, {10, 20, 30}};
    pprint(t);
    std::cout << "\n";

    std::cout << "Printing map:\n";
    std::map<std::string, int> m = {{"one", 1}, {"two", 2}, {"three", 3}};
    pprint(m);
    std::cout << "\n";

    std::cout << "Printing priority queue:\n";
    std::priority_queue<int> pq;
    pq.push(5); pq.push(2); pq.push(8);
    pprint(pq);
    std::cout << "\n";

    std::cout << "Printing nested tuple with map:\n";
    std::tuple<std::string, std::map<int, std::string>> t2 = {"numbers", {{1,"one"}, {2,"two"}}};
    pprint(t2);
    std::cout << "\n";

    return 0;
}
```

**Sample Output:**

```
Printing a string:
a

Printing 1D vector:
[ 1 2 3 4  ]

Printing 2D vector:
[
  [ 1 2  ]
  [ 3 4  ]
]

Printing 3D vector:
[
  [
    [ 1 2  ]
    [ 3 4  ]
]
  [
    [ 5 6  ]
    [ 7 8  ]
]
]

Printing tuple containing vector:
(42, [ 10 20 30  ])

Printing map:
{
  one: 1
  three: 3
  two: 2
}

Printing priority queue:
priority_queue#[ 8, 5, 2 ]

Printing nested tuple with map:
(numbers, {
  1: one
  2: two
})
```

---

## Requirements

- **C++20** (concepts are used)

## Notes

- This is a **header-only library**. No `.cpp` compilation is needed.
- Designed for **debugging and logging**, not optimized for production performance.

---

## License

## Dev Notes
When maintaining this libray, change python script below to include correct files, and regenerate the single file
```bash
python generate_single_header.py
```

MIT License – free to use and modify.