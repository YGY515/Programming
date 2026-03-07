// 자료구조 구현 공부 - 양방향 연결리스트
// 구현한 기능: 입력받은 노드 추가와 삭제, 노드 순서대로 출력, 원형 리스트로 이어주기
#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node* prev;
};
Node* node = NULL;


void addNode(int m)
{
    if (node == NULL)
    {
        node = new Node();
        node->value = m;
        node->next = NULL;
        node->prev = NULL;
    }
    else
    {
        Node* end = node;
        while(end->next != NULL)
        {
            end = end->next;
        }

        Node* newNode = new Node();
        newNode->value = m;
        newNode->next = NULL;
        newNode->prev = end;
        end->next = newNode;
    }
}

void deleteNode(int d)
{
    Node* target = node;
    
    if (target == NULL) 
    {
        cout << "\n노드가 비어있습니다.\n";
        return;
    }
    
    while(target != NULL && target->value != d)
    {
        target = target->next;
    }

    if (target == NULL) 
    {
        cout << "\n삭제할 값을 찾지 못했습니다.\n";
        return;
    }

    else
    {
        target->next->prev = target->prev;
        target->prev->next = target->next;
    }

    delete target;
}


void makeCircular()
{
    Node* start = node;
    Node* end = node;
    while(end->next != NULL)
    {
        end = end->next;
    }

    start->prev = end;
    end->next = start;
}


void print()
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
    for(int i = 0; i < N; i++)
    {
        int M;
        cin >> M;
        addNode(M);
    }

    cout << "완성된 노드\n";
    print();
    
    int D;
    cout << "\n\n어떤 요소를 지우시겠습니까? ";
    cin >> D;
    deleteNode(D);

    cout << "\n지우고 난 후의 노드\n";
    print();
    makeCircular();
    
    return 0;
}
