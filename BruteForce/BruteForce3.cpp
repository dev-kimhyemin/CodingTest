#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


bool isPrimeNumber(const int number)
{
    if(number <= 1)
    {
        return false;
    }
    if(number == 2)
    {
        return true;
    }
    if(number % 2 == 0)
    {
        return false;
    }

    for(int i = 3; i < number; i += 2)
    {
        if(number % i == 0)
        {
            return false;
        }
    }

    return true;
}

int solution(string numbers)
{
    unordered_set<int> primes;
    
    sort(numbers.begin(), numbers.end());

    do
    {
        for(unsigned int i = 1; i <= numbers.size(); ++i)
        {
            string str = numbers.substr(0, i);
            const int number = stoi(str);
            
            if(isPrimeNumber(number))
            {
                primes.emplace(number);
            }
        }
    } while(next_permutation(numbers.begin(), numbers.end()));

    return primes.size();
}

// int main()
// {
//     cout << solution("011");
// }



/*문제 설명
한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때,
종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

제한사항
- numbers는 길이 1 이상 7 이하인 문자열입니다.
- numbers는 0~9까지 숫자만으로 이루어져 있습니다.
- "013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.

입출력 예
numbers	    return
"17"	    3
"011"	    2
*/