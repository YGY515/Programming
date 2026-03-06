// 자료구조 구현 공부 - 단방향 연결리스트
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};
Node* node = NULL;


void addNode(int m)
{
    // 처음으로 값을 넣는 경우
    if (node == NULL)
    {
        node = new Node();
        node->value = m;
        node->next = NULL;
    }
    else
    {
        // 노드 마지막에 추가로 넣는 경우
        Node* end = node;
        while(end->next != NULL)
        {
            end = end->next;
        }

        // 이제 end는 마지막 노드가 된다.
        // 따라서 입력 받은 값을 새 노드로 만들어 end 노드 뒤에 이어 붙인다.
        Node* newNode = new Node();
        newNode->value = m;
        newNode->next = NULL;
        end->next = newNode;
    }
}

void deleteNode(int d)
{
    if (node == NULL) 
    {
        cout << "node가 비어있습니다.\n";
        return;
    }
    
    Node* target = node;
    Node* prev = NULL;
    while(target != NULL && target->value != d)
    {
        prev = target;
        target = target->next;
    }

    if (target == NULL)
    {
        cout << "\nnode에서 지우려는 " << d << " 값을 찾지 못했습니다.\n";
        return;
    }
    
    if (prev == NULL)
    {
        // target이 첫 번째 노드였을 경우, 노드의 head를 다음 노드로 옮긴다.
        node = node->next;
    }
    else
    {
        // target이 중간이나 마지막이었을 경우, 이전 노드를 target 다음 노드에 이어붙인다.
        prev->next = target->next;
    }  

    delete target;
}

void printNode()
{
    Node* print = node;
    cout << "현재 노드: ";
    while(print != NULL)
    {
        cout << print->value << " ";
        print = print->next;
    }
}

int main() 
{
    int N;
    cin >> N;
    while(N--)
    {
        int M;
        cin >> M;
        addNode(M);
    }

    printNode();

    int D;
    cin >> D;
    deleteNode(D);
    
    printNode();
    return 0;
}
