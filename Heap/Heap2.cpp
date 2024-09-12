#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> jobs)
{
    const int jobCount = static_cast<int>(jobs.size());

    sort(jobs.begin(), jobs.end(), cmp);

    int sum = 0;
    int timer = 0;

    while(!jobs.empty())
    {
        for(unsigned int i = 0; i < jobs.size(); ++i)
        {
            if(jobs[i][0] <= timer)
            {
                timer += jobs[i][1];
                sum += timer - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }

            if(i == jobs.size() - 1)
            {
                ++timer;
            }
        }
    }

    return sum / jobCount;
}

// int main()
// {
//     const vector<vector<int>> jobs({{7, 8}, {3, 5}, {9, 6}});
//     cout << solution(jobs);
// }



/*문제 설명
하드디스크는 한 번에 하나의 작업만 수행할 수 있습니다.
디스크 컨트롤러를 구현하는 방법은 여러 가지가 있습니다.
가장 일반적인 방법은 요청이 들어온 순서대로 처리하는 것입니다.

각 작업에 대해 [작업이 요청되는 시점, 작업의 소요시간]을 담은 2차원 배열 jobs가 매개변수로 주어질 때,
작업의 요청부터 종료까지 걸린 시간의 평균을 가장 줄이는 방법으로 처리하면 평균이 얼마가 되는지 return 하도록 solution 함수를 작성해주세요.
(단, 소수점 이하의 수는 버립니다)*/