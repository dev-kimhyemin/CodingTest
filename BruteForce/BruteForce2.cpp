#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers)
{
    const vector<vector<int>> answerSheets({
        {1, 2, 3, 4, 5, 1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    });
    
    vector<int> winners;
    unsigned int maxCount = 0;

    for(unsigned int i = 0; i < answerSheets.size(); ++i)
    {
        unsigned int currentCount = 0;
        
        for(unsigned int j = 0; j < answers.size(); ++j)
        {
            if(answers[j] == answerSheets[i][j % answerSheets[i].size()])
            {
                ++currentCount;
            }
        }
        
        if(currentCount > maxCount)
        {
            winners.clear();
        }

        if(currentCount >= maxCount)
        {
            winners.emplace_back(i + 1);
            maxCount = currentCount;
        }
    }

    return winners;
}

// int main()
// {
//     const vector<int> answers({5, 5, 4, 2, 3});
//     const vector<int> result = solution(answers);
//
//     for(const int i : result)
//     {
//         cout << i << ", ";
//     }
// }



/*문제 설명
수포자는 수학을 포기한 사람의 준말입니다.
수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다.
수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때,
가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한 조건
-시험은 최대 10,000 문제로 구성되어있습니다. 
- 문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
- 가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.

입출력 예
answers         return
[1,2,3,4,5]	    [1]
[1,3,2,4,2]	    [1,2,3]
*/