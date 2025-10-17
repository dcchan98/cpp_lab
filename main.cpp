// Cp utils
#include "cp_util/dc_constants.hpp"
#include "cp_util/dc_classes.hpp"
#include "cp_util/dc_funcs.hpp"
#include "cpprint/print.hpp"
#define print(x) \
do { \
std::cout << "Line " << __LINE__ << " : " << #x << " =============================================================\n"; \
std::cout << generate_container_string_recursively(x) << "\n"; \
std::cout << "=====================================================================================================\n"; \
} while(0)

#include <bits/stdc++.h>
using namespace std;
// ********************** Modify Code Below ***********************************************************************

int main(){
    print("hello");
}