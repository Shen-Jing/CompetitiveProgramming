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
#include <stdexcept>
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

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 */

class Iterator {
    struct Data;
    Data* data;
 public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums)
  {
      // Initialize any member here.
      // **DO NOT** save a copy of nums and manipulate it directly.
      // You should only use the Iterator interface methods.
      has_next = Iterator::hasNext();
      if (has_next)
      {
          next_value = Iterator::next();
      }
  }
  
  // Returns the next element in the iteration without advancing the iterator.
  int peek()
  {
      return next_value;
  }
  
  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next()
  {
      if (!has_next)
      {
          throw std::invalid_argument("test");
          return -1;
      }
      else
      {
          int result = next_value;
          has_next = Iterator::hasNext();
          if (has_next)
          {
              next_value = Iterator::next();
          }
          return result;
      }
  }
  
  bool hasNext() const
  {
      return has_next;
  }

private:
  bool has_next = false;
  int next_value;
};

int main(void)
{
    // PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]);
    PeekingIterator peekingIterator = PeekingIterator({1, 2, 3}); // [1,2,3]
    peekingIterator.next();    // return 1, the pointer moves to the next element [1,2,3].
    peekingIterator.peek();    // return 2, the pointer does not move [1,2,3].
    peekingIterator.next();    // return 2, the pointer moves to the next element [1,2,3]
    peekingIterator.next();    // return 3, the pointer moves to the next element [1,2,3]
    peekingIterator.hasNext(); // return False
    return 0;
}