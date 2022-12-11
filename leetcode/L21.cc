struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *head = nullptr;
    ListNode **indirect = &head;

    while (list1 && list2) {
      if (list1->val < list2->val) {
        *indirect = list1;
        list1 = list1->next;
      } else {
        *indirect = list2;
        list2 = list2->next;
      }

      indirect = &(*indirect)->next;
    }

    *indirect = list1 ? list1 : list2;

    return head;
  }
};
