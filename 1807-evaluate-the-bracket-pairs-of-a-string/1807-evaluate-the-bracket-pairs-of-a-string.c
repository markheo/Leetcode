#define HASH_SIZE 101  // 소수를 사용하여 해시 충돌 최소화

// 해시 테이블의 노드 구조체
typedef struct Node {
    char* key;
    char* value;
    struct Node* next;
} Node;

// 해시 함수
unsigned int hash(char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash % HASH_SIZE;
}

// 해시 테이블에 노드 추가
void insert(Node** table, char* key, char* value) {
    unsigned int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = table[index];
    table[index] = newNode;
}

// 키에 해당하는 값을 해시 테이블에서 찾기
char* search(Node** table, char* key) {
    unsigned int index = hash(key);
    Node* temp = table[index];
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0)
            return temp->value;
        temp = temp->next;
    }
    return "?";  // 키를 찾지 못한 경우
}

// 주어진 지식 배열을 해시 테이블로 변환
Node** buildHashTable(char*** knowledge, int knowledgeSize, int* knowledgeColSize) {
    Node** table = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    for (int i = 0; i < knowledgeSize; i++) {
        insert(table, knowledge[i][0], knowledge[i][1]);
    }
    return table;
}

// 괄호 안의 키를 해당하는 값으로 치환
char* evaluate(char* s, char*** knowledge, int knowledgeSize, int* knowledgeColSize) {
    // 해시 테이블 구성
    Node** table = buildHashTable(knowledge, knowledgeSize, knowledgeColSize);
    char* result = (char*)malloc(strlen(s) * 2 + 1);
    int resultIndex = 0;

    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '(') {
            char key[101]; // 키를 저장할 임시 배열
            int keyIndex = 0;
            ++i; // '(' 다음 문자로 이동
            while (s[i] != ')' && s[i] != '\0') {
                key[keyIndex++] = s[i++];
            }
            key[keyIndex] = '\0';

            // 키에 해당하는 값을 찾아 치환
            char* value = search(table, key);
            if (value != NULL) {
                strcpy(&result[resultIndex], value);
                resultIndex += strlen(value);
            } else {
                result[resultIndex++] = '?';
            }
        } else {
            result[resultIndex++] = s[i];
        }
    }
    result[resultIndex] = '\0'; // 문자열 종료

    // 메모리 해제 코드는 생략됨
    return result;
}