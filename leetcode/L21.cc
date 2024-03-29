/**
 * 将两个升序链表合并为一个新的 升序
 * 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 * Definition for
 * singly-linked list. struct ListNode { int val; ListNode *next; ListNode() :
 * val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
};
