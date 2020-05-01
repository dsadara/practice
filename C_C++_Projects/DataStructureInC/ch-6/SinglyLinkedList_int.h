// 원소가 정수인 단순 연결 리스트 헤더 파일

typedef int element;

typedef struct ListNode {   // 노드 타입을 구조체로 정의
    element data;
    struct ListNode *link;  // 자기 참조 구조체
} ListNode;

// 오류 처리 함수
void error(char *message)
{   
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 리스트의 첫 부분에 새로운 노드를 추가하는 삽입함수
ListNode* insert_first(ListNode *head_inside, int value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head_inside; // 새로운 노드의 link에 현재의 head 값을 저장 후
    head_inside = p;  // 헤드 포인터가 새로운 노드를 가리키게 함
    return head_inside;    // 변경된 헤드 포인터 반환 
}

// 노드 pre 뒤에 새로운 노드삽입
ListNode* insert(ListNode *head, ListNode *pre, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); // 노드 한개의 크기만큼 동적 할당
    p->data = value;    // 데이터 필드에 value 저장
    p->link = pre->link; // 노드 pre 가 가리키고 있는걸 링크 p 가 가리키게 함
    pre->link = p;  // 노드 pre 가 p 를 가리키게 함
    return head; // 변경된 헤드 포인터 반환
}

// 첫번째 노드를 삭제하는 함수
ListNode* delete_first(ListNode *head)
{
    ListNode *removed;  // 삭제할 노드의 주소를 저장할 노드 포인터 생성
    if (head == NULL) return NULL;  // 비어있는 연결 리스트이면 NULL 을 반환
    removed = head; // removed 에 첫번째 노드의 주소값이 있는 head 를 대입
    head = removed->link; // head가 두번째 노드를 가리키게 함
    free(removed);  // removed 가 가리키는 동적 메모리를 반환
    return head; // 변경된 헤드 포인터 반환 
}

// pre가 가리키는 노드의 다음 노드를 삭제
ListNode* delete_node(ListNode *head, ListNode *pre)
{
    ListNode *removed; //삭제할 노드를 저장할 노드 포인터 생성
    removed = pre->link;    // pre 가 가리키는 노드의 다음 노드를 저장
    pre->link = removed->link; // 삭제 할 노드의 다음 노드를 pre 가 가리키게 함
    free(removed);  // removed가 가리키는 동적 메모리 반환
    return head; // 변경된 헤드 포인터 반환
}

// 연결 리스트 안에 모든 노드의 데이터를 출력하는 함수
void print_list(ListNode *head)
{
    for (ListNode *p = head ; p != NULL ; p = p->link)  // NULL 도달할 때까지(노드 끝까지 도달할 때까지) 반복
        printf("%d=>", p->data);    // 각 노드의 데이터를 출력
    printf("NULL \n");
}


// index 번째의 데이터를 찾아서 반환
element get_entry(ListNode *head, int index)
{
    ListNode *p = head;
    for(int i = 0 ; i < index ; i++)    // 인덱스의 수 만큼 계산 하는 반복문 
    {
        p = p->link; // 다음노드를 가리키게 하는 연산
    }
    return p->data;
}

// 단순 연결 리스트에 존재하는 노드의 수를 계산하는 함수
int get_length(ListNode *head)
{
    int length = 0;
    for (ListNode *p = head ; p != NULL ; p = p->link)
    {
        length++;
    }   
    return length;
}