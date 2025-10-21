#include "generated/cpprint.hpp"
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace cpprint;

int main() {
    // Single string
    pprint("a");

    // 1D vector
    std::vector<int> v1 = {1, 2, 3, 4};
    pprint("1D vector:", v1);

    // 2D vector
    std::vector<std::vector<int>> v2 = {{1, 2}, {3, 4}};
    pprint("2D vector:", v2);

    // 3D vector
    std::vector<std::vector<std::vector<int>>> v3 = {{{1,2},{3,4}}, {{5,6},{7,8}}};
    pprint("3D vector:", v3);

    // Tuple containing a vector
    std::tuple<int, std::vector<int>> t = {42, {10, 20, 30}};
    pprint("Tuple with vector:", t);

    // Map
    std::map<std::string, int> m = {{"one", 1}, {"two", 2}, {"three", 3}};
    pprint("Map:", m);

    // Priority queue
    std::priority_queue<int> pq;
    pq.push(5); pq.push(2); pq.push(8);
    pprint("Priority queue:", pq);

    // Nested tuple with map
    std::tuple<std::string, std::map<int, std::string>> t2 = {"numbers", {{1,"one"}, {2,"two"}}};
    pprint("Nested tuple with map:", t2);

    // Inline flattened examples
    pprint_inline("Inline 1D vector:", v1);
    pprint_inline("Inline 2D vector:", v2);
    pprint_inline("Inline tuple:", t);


    return 0;
}