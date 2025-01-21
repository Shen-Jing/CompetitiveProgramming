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
#include <optional>
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
    struct Data {
        const vector<int> *nums;
        size_t index;
    };
    Data* data;
 public:
    Iterator(const vector<int> &nums)
    {
        data = new Data{&nums, 0};
    }

    Iterator(const vector<int> &&nums) = delete;

    Iterator(const Iterator& iter)
    {
        data = new Data{iter.data->nums, iter.data->index};
    }

    // Returns the next element in the iteration.
    int next()
    {
        return (*data->nums)[++data->index];
    }

    // Returns true if the iteration has more elements.
    bool hasNext() const
    {
        return data->index + 1 < data->nums->size();
    }
};

/// Modern Cpp
class PeekingIterator2 : public Iterator {
public:
  PeekingIterator2(const vector<int>& nums) : Iterator(nums)
  {
      // Initialize any member here.
      // **DO NOT** save a copy of nums and manipulate it directly.
      // You should only use the Iterator interface methods.
      if (Iterator::hasNext())
      {
          next_value = Iterator::next();
      }
  }

  PeekingIterator2(const vector<int> &&nums) = delete;
  
  // Returns the next element in the iteration without advancing the iterator.
  int peek()
  {
      return next_value.value();
  }
  
  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next()
  {
      int result = next_value.value();
      if (Iterator::hasNext())
      {
          next_value = Iterator::next();
      }
      else
      {
          next_value.reset();
      }
      return result;
  }
  
  bool hasNext() const
  {
      return next_value.has_value();
  }

private:
  optional<int> next_value;
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

  PeekingIterator(const vector<int> &&nums) = delete;

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
          throw out_of_range("No more elements");
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
    vector<int> nums = {1, 2, 3};
    // PeekingIterator peekingIterator = PeekingIterator({1, 2, 3}); // [1,2,3]
    PeekingIterator peekingIterator = PeekingIterator(nums); // [1,2,3]
    peekingIterator.next();    // return 1, the pointer moves to the next element [1,2,3].
    peekingIterator.peek();    // return 2, the pointer does not move [1,2,3].
    peekingIterator.next();    // return 2, the pointer moves to the next element [1,2,3]
    peekingIterator.next();    // return 3, the pointer moves to the next element [1,2,3]
    peekingIterator.hasNext(); // return False

    /// Test Modern C++ version
    PeekingIterator2 peekingIterator2 = PeekingIterator2(nums); // [1,2,3]
    peekingIterator2.next();    // return 1, the pointer moves to the next element [1,2,3].
    peekingIterator2.peek();    // return 2, the pointer does not move [1,2,3].
    peekingIterator2.next();    // return 2, the pointer moves to the next element [1,2,3]
    peekingIterator2.next();    // return 3, the pointer moves to the next element [1,2,3]
    peekingIterator2.hasNext(); // return False
    return 0;
}