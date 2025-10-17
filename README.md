# cpprint

`cpprint` is a **header-only C++ library** for beautiful, recursive printing of STL containers, tuples, maps, and even priority queues. Designed for **quick debugging**, it prints variables with **line numbers, variable names, and readable formatting**.

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

MIT License – free to use and modify.