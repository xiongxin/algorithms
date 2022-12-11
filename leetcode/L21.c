#include <stdint.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *L1, struct ListNode *L2) {
  struct ListNode *head;
  struct ListNode **indirect = &head;

  while (L1 && L2) {
    if (L1->val < L2->val) {
      *indirect = L1;
      L1 = L1->next;
    } else {
      *indirect = L2;
      L2 = L2->next;
    }

    indirect = &(*indirect)->next;
  }
  *indirect = (struct ListNode *)((uintptr_t)L1 | (uintptr_t)L2);
  return head;
}
