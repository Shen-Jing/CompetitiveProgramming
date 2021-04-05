#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <type_traits>
#include <utility>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <vector>

static auto io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

int main(void){
    std::cout << "***Case 0: ***\n";
    bool b;
    std::cout << "Size of boolean type: " << sizeof(b) << "\n";

    std::cout << "***Case 1: ***\n";
    std::cout << std::stoi("01000101", nullptr, 2) << "\n";
    std::cout << std::stoi("265", nullptr, 16) << "\n";
    std::stringstream ss;
    std::bitset<8> byte_test("00010010");
    std::cout << "initial value: " << byte_test << '\n';
    std::cout << byte_test.count() << '\n';
    ss << std::hex << "265";
    int n;
    ss >> n;
    std::cout << n << "\n";

    printf("***Case 2: ***\n");
    std::istringstream input("1 22 333");
    std::istream_iterator<int> begin(input);
    std::istream_iterator<int> end;

    std::vector<int> data;
    data.insert(data.begin(), begin, end);
    for (const auto &i : data)
      std::cout << i << std::endl;

    printf("***Case 3: ***\n");
    // void* memset( void* dest, int ch, std::size_t count );
    int a[10];
    auto uch = static_cast<unsigned char>(-1);
    std::cout << uch << '\n';
    memset(a, 1, sizeof a);
    for (int ai : a)
      std::cout << ai << " ";
    
    printf("***Case 4: Striping suffix #***\n");
    std::vector<std::string> headers
    {
      ">Read=10000;length=16492bp;startpos=3486810;chromosome=NC_000913.3_Escherichia_coli_K-12_MG1655,_complete_genome;numberOfErrors=3554;totalErrorProb=0.2056;passes=1.5688284802086048;passesLeft=1;passesRight=2;cutPosition=7111#0",
      ">Read=10000;length=16492bp;startpos=3486810;chromosome=NC_000913.3_Escherichia_coli_K-12_MG1655,_complete_genome;numberOfErrors=3554;totalErrorProb=0.2056;passes=1.5688284802086048;passesLeft=1;passesRight=2;cutPosition=7111#2"
    };

    for (auto &header : headers)
    {
        auto pos = header.rfind("#");
        header = header.substr(0, header.rfind("#"));
    }

    printf("***Case 5: Lower bound***\n");
    std::string target{"applepen"};
    auto lower = std::lower_bound(target.begin(), target.end(), std::string("apple"));

    return 0;
}