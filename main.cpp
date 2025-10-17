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