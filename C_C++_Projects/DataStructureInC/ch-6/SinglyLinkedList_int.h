// ���Ұ� ������ �ܼ� ���� ����Ʈ ��� ����

typedef int element;

typedef struct ListNode {   // ��� Ÿ���� ����ü�� ����
    element data;
    struct ListNode *link;  // �ڱ� ���� ����ü
} ListNode;

// ���� ó�� �Լ�
void error(char *message)
{   
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// ����Ʈ�� ù �κп� ���ο� ��带 �߰��ϴ� �����Լ�
ListNode* insert_first(ListNode *head_inside, int value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head_inside; // ���ο� ����� link�� ������ head ���� ���� ��
    head_inside = p;  // ��� �����Ͱ� ���ο� ��带 ����Ű�� ��
    return head_inside;    // ����� ��� ������ ��ȯ 
}

// ��� pre �ڿ� ���ο� ������
ListNode* insert(ListNode *head, ListNode *pre, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); // ��� �Ѱ��� ũ�⸸ŭ ���� �Ҵ�
    p->data = value;    // ������ �ʵ忡 value ����
    p->link = pre->link; // ��� pre �� ����Ű�� �ִ°� ��ũ p �� ����Ű�� ��
    pre->link = p;  // ��� pre �� p �� ����Ű�� ��
    return head; // ����� ��� ������ ��ȯ
}

// ù��° ��带 �����ϴ� �Լ�
ListNode* delete_first(ListNode *head)
{
    ListNode *removed;  // ������ ����� �ּҸ� ������ ��� ������ ����
    if (head == NULL) return NULL;  // ����ִ� ���� ����Ʈ�̸� NULL �� ��ȯ
    removed = head; // removed �� ù��° ����� �ּҰ��� �ִ� head �� ����
    head = removed->link; // head�� �ι�° ��带 ����Ű�� ��
    free(removed);  // removed �� ����Ű�� ���� �޸𸮸� ��ȯ
    return head; // ����� ��� ������ ��ȯ 
}

// pre�� ����Ű�� ����� ���� ��带 ����
ListNode* delete_node(ListNode *head, ListNode *pre)
{
    ListNode *removed; //������ ��带 ������ ��� ������ ����
    removed = pre->link;    // pre �� ����Ű�� ����� ���� ��带 ����
    pre->link = removed->link; // ���� �� ����� ���� ��带 pre �� ����Ű�� ��
    free(removed);  // removed�� ����Ű�� ���� �޸� ��ȯ
    return head; // ����� ��� ������ ��ȯ
}

// ���� ����Ʈ �ȿ� ��� ����� �����͸� ����ϴ� �Լ�
void print_list(ListNode *head)
{
    for (ListNode *p = head ; p != NULL ; p = p->link)  // NULL ������ ������(��� ������ ������ ������) �ݺ�
        printf("%d=>", p->data);    // �� ����� �����͸� ���
    printf("NULL \n");
}


// index ��°�� �����͸� ã�Ƽ� ��ȯ
element get_entry(ListNode *head, int index)
{
    ListNode *p = head;
    for(int i = 0 ; i < index ; i++)    // �ε����� �� ��ŭ ��� �ϴ� �ݺ��� 
    {
        p = p->link; // ������带 ����Ű�� �ϴ� ����
    }
    return p->data;
}

// �ܼ� ���� ����Ʈ�� �����ϴ� ����� ���� ����ϴ� �Լ�
int get_length(ListNode *head)
{
    int length = 0;
    for (ListNode *p = head ; p != NULL ; p = p->link)
    {
        length++;
    }   
    return length;
}