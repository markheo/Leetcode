/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode *head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    while (curr != NULL) {
        struct ListNode *curNext = curr->next; // 현재 노드의 다음 노드를 저장
        curr->next = prev; // 현재 노드의 다음을 이전 노드로 설정
        prev = curr; // 이전 노드를 현재 노드로 업데이트
        curr = curNext; // 현재 노드를 다음 노드로 이동
    }
    return prev; // 새로운 head 반환
}

int pairSum(struct ListNode* head) {
    // 1. 중앙 찾기
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. 후반부 리스트 역순으로 만들기
    struct ListNode *secondHalf = reverseList(slow);
    struct ListNode *firstHalf = head;

    // 3. 두 리스트를 동시에 순회하면서 최대 합 갱신
    int maxSum = 0;
    while (secondHalf != NULL) {
        int currentSum = firstHalf->val + secondHalf->val;
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // 4. 최대 합 반환
    return maxSum;
}