/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    // 리스트에 노드가 없거나, 하나만 있는 경우, NULL을 반환합니다.
    if (head == NULL || head->next == NULL) {
        free(head); // 메모리 해제
        return NULL;
    }

    struct ListNode *slow = head, *fast = head;
    struct ListNode *prev = NULL; // 중간 노드의 바로 이전 노드를 추적합니다.

    // fast 포인터가 리스트의 끝에 도달할 때까지 리스트를 순회합니다.
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // slow가 중간 노드를 가리키므로, 이 노드를 리스트에서 제거합니다.
    if (prev != NULL) {
        prev->next = slow->next; // 중간 노드를 건너뛰어 연결합니다.
    }
    free(slow); // 중간 노드의 메모리를 해제합니다.

    return head; // 수정된 리스트의 head를 반환합니다.
}