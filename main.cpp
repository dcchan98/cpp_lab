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