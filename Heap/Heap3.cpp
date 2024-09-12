#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void insert(deque<int>& numbers, const int number)
{
    for(unsigned int i = 0; i < numbers.size(); ++i)
    {
        if(numbers[i] <= number)
        {
            continue;
        }

        numbers.emplace(numbers.begin() + i, number);
        return;
    }

    numbers.emplace(numbers.begin() + static_cast<int>(numbers.size()), number);
}

vector<int> solution(vector<string> operations)
{
    deque<int> numbers;

    for(const string& operation : operations)
    {
        const string delimiter = " ";
        const size_t delimiterLocation = operation.find(delimiter);
        
        const string flag = operation.substr(0, delimiterLocation);
        const string numberString = operation.substr(delimiterLocation + 1, operation.length() - delimiterLocation - 1);
        const int number = stoi(numberString);

        if(flag == "I")
        {
            insert(numbers, number);
        }
        else if(flag == "D")
        {
            if(numbers.empty())
            {
                continue;
            }
            
            if(number > 0)
            {
                numbers.pop_back();
            }
            else
            {
                numbers.pop_front();
            }
        }
    }

    vector<int> answer;
    answer.emplace_back(numbers.empty() ? 0 : numbers.back());
    answer.emplace_back(numbers.empty() ? 0 : numbers.front());

    return answer;
}

// int main()
// {
//     const vector<int> answer = solution({"D 1", "I 5", "D -1", "D -1"});
//     for(const int a : answer)
//     {
//         cout << a << ", ";
//     }
// }

/*문제 설명
이중 우선순위 큐는 다음 연산을 할 수 있는 자료구조를 말합니다.

명령어	동작
I 숫자	큐에 주어진 숫자를 삽입합니다.
D 1	    큐에서 최댓값을 삭제합니다.
D -1	큐에서 최솟값을 삭제합니다.

이중 우선순위 큐가 할 연산 operations가 매개변수로 주어질 때,
모든 연산을 처리한 후 큐가 비어있으면 [0,0] 비어있지 않으면 [최댓값, 최솟값]을 return 하도록 solution 함수를 구현해주세요.

제한사항
- operations는 길이가 1 이상 1,000,000 이하인 문자열 배열입니다.
- operations의 원소는 큐가 수행할 연산을 나타냅니다.
- 원소는 “명령어 데이터” 형식으로 주어집니다.- 최댓값/최솟값을 삭제하는 연산에서 최댓값/최솟값이 둘 이상인 경우, 하나만 삭제합니다.
- 빈 큐에 데이터를 삭제하라는 연산이 주어질 경우, 해당 연산은 무시합니다.

입출력 예
operations	                                                                    return
["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]	                    [0,0]
["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]	    [333, -45]
*/