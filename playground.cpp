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

using namespace std;

static auto io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

int main(void){
    cout << "***Case 0: ***\n";
    bool b;
    cout << "Size of boolean type: " << sizeof(b) << "\n";

    cout << "***Case 1: ***\n";
    cout << std::stoi("01000101", nullptr, 2) << endl;
    cout << std::stoi("265", nullptr, 16) << endl;
    stringstream ss;
    bitset<8> byte_test("00010010");
    cout << "initial value: " << byte_test << '\n';
    cout << byte_test.count() << '\n';
    ss << hex << "265";
    int n;
    ss >> n;
    cout << n << endl;

    printf("***Case 2: ***\n");
    istringstream input("1 22 333");
    istream_iterator<int> begin(input);
    istream_iterator<int> end;

    vector<int> data;
    data.insert(data.begin(), begin, end);
    for (const auto &i : data)
      cout << i << endl;

    printf("***Case 3: ***\n");
    // void* memset( void* dest, int ch, std::size_t count );
    int a[10];
    auto uch = static_cast<unsigned char>(-1);
    cout << uch << '\n';
    memset(a, 1, sizeof a);
    for (int ai : a)
      std::cout << ai << " ";
}