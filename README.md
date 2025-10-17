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
#include "cpprint.hpp"
#include <vector>
#include <tuple>
#include <queue>
#include <map>

int main() {
    std::vector<int> v = {1, 2, 3};
    print(v);  // prints variable name, line number, and contents

    std::tuple<int, std::vector<int>> t = {5, {1,2,3}};
    print(t);

    std::map<int, std::string> m = {{1,"a"}, {2,"b"}};
    print(m);

    std::priority_queue<int> pq;
    pq.push(1); pq.push(3); pq.push(2);
    print(pq);
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