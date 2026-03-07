// 자료구조 구현 공부 - 단방향 연결리스트
// 구현한 기능: 입력받은 노드 추가와 삭제, 노드 순서대로 출력, 노드 거꾸로 출력
// 노드를 거꾸로 출력할 때는 스택과 재귀 함수를 활용함.
#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int value;
    Node* next;
};
Node* node = NULL;


void addNode(int m)
{
    if (node == NULL)
    {
        node = new Node();
        node->value = m;
        node->next = NULL;
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
        end->next = newNode;
    }
}


void deleteNode(int d)
{
    Node* target = node;
    Node* prev = NULL;
    
    if (target == NULL) 
    {
        cout << "\n노드가 비어있습니다.\n";
        return;
    }
    
    while(target != NULL && target->value != d)
    {
        prev = target;
        target = target->next;
    }

    if (target == NULL) 
    {
        cout << "\n삭제할 값을 찾지 못했습니다.\n";
        return;
    }

    if (prev == NULL)
    {
        // 지울 값이 첫번째 노드였을 경우
        node = node->next;
    }
    else
    {
        prev->next = target->next;
    }

    delete target;
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


// 연결 리스트를 거꾸로 출력하는 방법 1. 스택 활용
void printReverse1()
{
    Node* print = node;
    stack<int> s;
    
    while(print != NULL)
    {
        s.push(print->value);
        print = print->next;
    }
    
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}


// 연결 리스트를 거꾸로 출력하는 방법 2. 재귀 활용
void printReverse2(Node* node)
{
    if (node ==  NULL) return;
    printReverse2(node->next);
    cout << node->value << " ";
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

    cout << "\n\n스택을 활용해 거꾸로 출력\n";
    printReverse1();
    cout << "\n\n재귀를 이용해 거꾸로 출력\n";
    printReverse2(node);
    
    return 0;
}
