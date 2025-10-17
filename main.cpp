// Cp utils
#include "cp_util/dc_constants.hpp"
#include "cp_util/dc_classes.hpp"
#include "cp_util/dc_funcs.hpp"

// cpprint library
#include "cpprint/print.hpp"
#define print(x) \
do { \
std::cout << "Line " << __LINE__ << " : " << #x << " =============================================================\n"; \
std::cout << generate_container_string_recursively(x) << "\n"; \
std::cout << "=====================================================================================================\n"; \
} while(0)

// ********************** Modify Code Below ***********************************************************************

#include <bits/stdc++.h>

using namespace std;

// Modify code below

int main(){
    print("hello");
}