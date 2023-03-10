/**
 * Definition for singly-linked list.
 * 输入：head = [1,2,3,4] 输出：[2,1,4,3]
 * 输入：head = []        输出：[]
 * 输入：head = [1]       输出：[1]
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  // 迭代版本
  ListNode* swapPairs(ListNode* head) {
    ListNode** tmp = &head;
    ListNode* iter = head;
    while (iter) {
      ListNode* tmp1 = iter;
      ListNode* tmp2 = iter->next;

      if (tmp2) {
        iter = tmp2->next;

        tmp1->next = nullptr;
        tmp2->next = tmp1;

        *tmp = tmp2;
        tmp = &tmp1->next;
      } else {
        *tmp = tmp1;
        iter = nullptr;
      }
    }

    return head;
  }

  // 递归版本
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
  }
};

int main(int argc, char const* argv[]) {
  ListNode* l1 = new ListNode(1);
  ListNode* l2 = new ListNode(2);
  l1->next = l2;
  ListNode* l3 = new ListNode(3);
  l2->next = l3;
  ListNode* l4 = new ListNode(4);
  l3->next = l4;

  Solution s{};
  s.swapPairs(l1);
  return 0;
}
