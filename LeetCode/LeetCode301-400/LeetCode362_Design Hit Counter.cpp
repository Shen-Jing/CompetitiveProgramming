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
#include <memory>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class HitCounter {
public:
    HitCounter()
    {
        fill(counter.begin(), counter.end(), TimestampData{0, 0});
    }
    
    void hit(int timestamp)
    {
        int cnter_i = timestamp % 300;
        if (timestamp == counter[cnter_i].timestamp)
        {
            ++counter[cnter_i].counts;
            return;
        }
        counter[cnter_i] = TimestampData{timestamp, 1};
    }
    
    int getHits(int timestamp)
    {
        return accumulate(counter.begin(), counter.end(), 0, [timestamp](int sum, const TimestampData &d){
            return sum + ((timestamp - d.timestamp < 300) ? d.counts : 0);
        });
    }

private:
    struct TimestampData {
      int timestamp;
      int counts;
    };
    array<TimestampData, 300> counter;
};

int main(void)
{

    return 0;
}