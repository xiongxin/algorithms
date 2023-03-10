/**
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<ListNode*> tmp_cont{};

    while (head) {
      ListNode* next = head->next;
      tmp_cont.push_back(head);
      head->next = nullptr;
      head = next;
    }

    auto iterator = tmp_cont.begin();
    iterator += (tmp_cont.size() - n);

    ListNode* to_delete = *iterator;
    tmp_cont.erase(iterator);
    delete to_delete;

    ListNode* res = nullptr;
    ListNode** res_ptr = &res;
    for (auto iter = tmp_cont.begin(); iter != tmp_cont.end(); ++iter) {
      *res_ptr = *iter;
      res_ptr = &(*res_ptr)->next;
    }

    return res;
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
  ListNode* l5 = new ListNode(5);
  l4->next = l5;

  Solution s{};
  s.removeNthFromEnd(l1, 2);
  return 0;
}
