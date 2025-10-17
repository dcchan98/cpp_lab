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

using namespace cpprint;
int main() {
    pprint("a");

    // 1D vector
    std::vector<int> v1 = {1, 2, 3, 4};
    pprint(v1);

    // 2D vector
    std::vector<std::vector<int>> v2 = {{1, 2}, {3, 4}};
    pprint(v2);

    // 3D vector
    std::vector<std::vector<std::vector<int>>> v3 = {{{1,2},{3,4}}, {{5,6},{7,8}}};
    pprint(v3);

    // Tuple containing vector
    std::tuple<int, std::vector<int>> t = {42, {10, 20, 30}};
    pprint(t);

    // Map
    std::map<std::string, int> m = {{"one", 1}, {"two", 2}, {"three", 3}};
    pprint(m);

    // Priority queue
    std::priority_queue<int> pq;
    pq.push(5); pq.push(2); pq.push(8);
    pprint(pq);

    // Nested tuple with map
    std::tuple<std::string, std::map<int, std::string>> t2 = {"numbers", {{1,"one"}, {2,"two"}}};
    pprint(t2);

    return 0;
}
```

**Sample Output:**

```
Line 12 : v ===
[ 1 2 3 ]
=========================
Line 15 : t ===
(5, [ 1 2 3 ])
=========================
Line 18 : m ===
{
  1: a
  2: b
}
=========================
Line 21 : pq ===
priority_queue#[ 3, 2, 1 ]
=========================
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