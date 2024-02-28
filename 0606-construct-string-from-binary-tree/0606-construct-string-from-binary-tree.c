/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char* tree2str(struct TreeNode* root) {
    if (root == NULL) {
        return strdup(""); // 노드가 NULL인 경우, 빈 문자열 반환
    }

    char* left = tree2str(root->left); // 왼쪽 서브트리를 문자열로 변환
    char* right = tree2str(root->right); // 오른쪽 서브트리를 문자열로 변환

    char* result = (char*)malloc(strlen(left) + strlen(right) + 20); // 결과 문자열을 저장할 메모리 할당
    sprintf(result, "%d", root->val); // 현재 노드의 값을 문자열에 추가

    if (root->left || root->right) {
        strcat(result, "(");
        strcat(result, left);
        strcat(result, ")");
    }
    if (root->right) {
        strcat(result, "(");
        strcat(result, right);
        strcat(result, ")");
    }

    free(left); // 재귀 호출로 생성된 문자열 메모리 해제
    free(right);

    return result; // 결과 문자열 반환
}