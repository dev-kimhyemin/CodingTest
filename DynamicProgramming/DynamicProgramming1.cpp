﻿#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;


int GetRepeatedNumber(const int n, const int digit)
{
    int result = n;

    for(int i = 1; i < digit; ++i)
    {
        result = result * 10 + n;
    }

    return result;
}

int solution(int N, int number)
{
    if(N == number)
    {
        return 1;
    }

    vector<unordered_set<int>> operationResults(8);
    operationResults[0].emplace(N);

    // 문제로부터 부분 문제를 정의하자면 N 사용 횟수마다의 사칙연산 결과는 아래와 같다.
    // Sn을 n개의 N으로 만들 수 있는 결과값들이라고 할 때
    // * S1: N
    // * S2: NN, S1과 S1 연산
    //   - N이 5인 경우 S2는 {(55), (5 + 5), (5 - 5), (5 * 5), (5 / 5)}이다.
    //   - 사칙연산을 사용하는 식에서의 5를 숫자 5가 아니라 S1의 요소로써 사용하는 것이라고 할 때 하위 문제를 도출할 수 있다.
    // * S3: NNN, S1과 S2 연산, S2와 S1 연산
    // ...
    // 이전 결과값들을 이용해 연산을 할 때 중요한 것은 두 개의 집합 Sn에서 n 값들의 합이 현재 n값과 같아야 한다는 것이다.
    for(int i = 1; i < 8; ++i)
    {
        const int repeatedNumber = GetRepeatedNumber(N, i + 1);
        
        if(repeatedNumber == number)
        {
            return i + 1;
        }

        operationResults[i].emplace(repeatedNumber);

        
        for(int j = 0; j < i; ++j)
        {
            for(int k = 0; k < i; ++k)
            {
                if(j + k + 1 != i)
                {
                    continue;
                }

                for(const int x : operationResults[j])
                {
                    for(const int y : operationResults[k])
                    {
                        operationResults[i].emplace(x + y);

                        if(x - y > 0)
                        {
                            operationResults[i].emplace(x - y);
                        }

                        operationResults[i].emplace(x * y);

                        if(x / y > 0)
                        {
                            operationResults[i].emplace(x / y);
                        }
                    }
                }

                if(operationResults[i].find(number) != operationResults[i].end())
                {
                    return i + 1;
                }
            }
        }
    }

    return -1;
}

// int main()
// {
//     cout << solution(5, 12);
// }



/*
아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.
12 = 5 + 5 + (5 / 5) + (5 / 5)
12 = 55 / 5 + 5 / 5
12 = (55 + 5) / 5

5를 사용한 횟수는 각각 6,5,4 입니다. 그리고 이중 가장 작은 경우는 4입니다.
이처럼 숫자 N과 number가 주어질 때,
N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 N 사용횟수의 최솟값을 return 하도록 solution 함수를 작성하세요.

제한사항
- N은 1 이상 9 이하입니다.
- number는 1 이상 32,000 이하입니다.
- 수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
- 최솟값이 8보다 크면 -1을 return 합니다.

입출력 예
N	number	return
5	12	    4
2	11	    3
*/