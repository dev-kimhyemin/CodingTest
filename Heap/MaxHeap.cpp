
#include <iostream>
#include <map>
#include <vector>

using namespace std;


int Arr[1000];
int ArrayIndex = -1;

int ParentNodeIndex(const int childIndex)
{
    return (childIndex + 1) / 2 - 1;
}

int ChildNodeIndex(const int parentIndex)
{
    return (parentIndex + 1) * 2 - 1;
}

// 1. 데이터를 배열의 가장 마지막에 삽입한다.
// 2. 삽입된 데이터를 부모 노드와 비교한 후 새로운 데이터가 더 크면 부모 노드와 swap한다.
// 3. 부모 노드가 더 큰 값이거나 루트 노드가 될 때까지 반복한다.
void HeapPush(const int data)
{
    int index = ++ArrayIndex;
    int parentIndex = ParentNodeIndex(index);
    
    Arr[index] = data;

    while(index > 0 && data > Arr[parentIndex])
    {
        swap(Arr[index], Arr[parentIndex]);
        
        index = parentIndex;
        parentIndex = ParentNodeIndex(index);
    }
}

// 1. 루트 노드의 값(최대값)를 저장한다.
// 2. 마지막 노드의 값과 루트 노드의 값을 swap한다.
// 3. 자식 노드 중 큰 값과 비교한 후 자식 노드의 값이 더 작으면 swap한다.
// 4. 자식 노드가 더 작은 값이거나 마지막 레벨이 될 때까지 반복한다.
// 5. 힙의 크기를 1 감소시키고 최대값을 반환한다.
int HeapPop()
{
    if(ArrayIndex < 0)
    {
        return -1;
    }

    const int result = Arr[0];
    
    Arr[0] = Arr[ArrayIndex--];

    int parentIndex = 0;

    while(true)
    {
        int childIndex = ChildNodeIndex(parentIndex);

        if(childIndex + 1 <= ArrayIndex && Arr[childIndex] < Arr[childIndex + 1])
        {
            ++childIndex;
        }

        if(childIndex > ArrayIndex || Arr[childIndex] < Arr[parentIndex])
        {
            break;
        }

        swap(Arr[childIndex], Arr[parentIndex]);
        parentIndex = childIndex;
    }

    return result;
}

void PrintArray()
{
    cout << "Array elements: ";
    
    for(int i = 0; i <= ArrayIndex; ++i)
    {
        cout << Arr[i] << ", ";
    }
    
    cout << "\n";
}

// int main()
// {
//     const vector<int> numbers({41, 67, 34, 0, 69, 78, 62, 64});
//
//     cout << "Push Start" << '\n';
//     for(const int number : numbers)
//     {
//         HeapPush(number);
//         PrintArray();
//     }
//
//     cout << "\nPop Start" << '\n';
//     for(unsigned int i = 0; i < numbers.size(); ++i)
//     {
//         cout << "Popped element: " << HeapPop() << '\n';
//         PrintArray();
//     }
// }