/**
 * Definition for singly-linked list.
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* res = new ListNode();
    ListNode* tmp = res;
    while (list1 && list2) {
      if (list1->val > list2->val) {
        tmp->next = list2;
        list2 = list2->next;
      } else {
        tmp->next = list1;
        list1 = list1->next;
      }

      tmp = tmp->next;
    }

    tmp->next = list1 ? list1 : list2;
    return res->next;
  }

 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return nullptr;
    for (int i = 1; i < lists.size(); ++i) {
      lists[i] = mergeTwoLists(lists[i - 1], lists[i]);
    }

    return lists.back();
  }
};
