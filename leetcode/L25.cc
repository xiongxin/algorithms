/**
 * Definition for singly-linked list.
 * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 输入：head = [1,2,3,4,5], k = 3
 * 输出：[3,2,1,4,5]
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[2,1,4,3,5]
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {}

  // 递归版本
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
  }
};
