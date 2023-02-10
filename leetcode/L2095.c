#include <stdlib.h>
// 题解：
// https://hackmd.io/@sysprog/c-linked-list#%E6%A1%88%E4%BE%8B%E6%8E%A2%E8%A8%8E-Leetcode-2095-Delete-the-Middle-Node-of-a-Linked-List
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *deleteMiddle(struct ListNode *head) {

  struct ListNode **indir = &head;
  struct ListNode *fast;

  for (fast = head; fast && fast->next; fast = fast->next->next)
    indir = &(*indir)->next;

  struct ListNode *del = *indir;
  *indir = del->next;
  free(del);

  return head;
}
