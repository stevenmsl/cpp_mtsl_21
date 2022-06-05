#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol21;

/*
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

tuple<Node *, Node *, string>
testFixture1()
{

  auto l1 = new Node(1);
  l1->next = new Node(2);
  l1->next->next = new Node(4);

  auto l2 = new Node(1);
  l2->next = new Node(3);
  l2->next->next = new Node(4);

  return make_tuple(l1, l2, "1->1->2->3->4->4");
}

void test1()
{
  auto f = testFixture1();
  Solution sol;

  cout << "Expect to see : " << get<2>(f) << endl;

  auto l = sol.mergeTwoLists(get<0>(f), get<1>(f));
  string s;

  while (l != nullptr)
  {
    s += to_string(l->val) + "->";
    l = l->next;
  }

  if (s.back() == '>')
    s.pop_back(), s.pop_back();

  cout << s << endl;
}

main()
{
  test1();

  return 0;
}