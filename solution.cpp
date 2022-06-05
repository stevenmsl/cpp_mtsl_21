#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol21;
using namespace std;

/*takeaways
  - use two pointers
    - the one with a smaller value will move ahead
  - don't forget to take care of the leftover
*/

Node *Solution::mergeTwoLists(Node *l1, Node *l2)
{
  auto dummyHead = new Node(-1);

  auto *tail = dummyHead;

  while (l1 != nullptr && l2 != nullptr)
  {
    if (l1->val < l2->val)
      tail->next = l1, l1 = l1->next;
    else
      tail->next = l2, l2 = l2->next;

    tail = tail->next;
  }

  /* handle the leftover */

  if (l1 != nullptr)
    tail->next = l1;
  else if (l2 != nullptr)
    tail->next = l2;

  return dummyHead->next;
}
