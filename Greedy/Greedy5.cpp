#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

typedef int Island;
typedef int Cost;


// 프림 알고리즘 사용
int solution(int n, vector<vector<int>> costs)
{
    int totalCost = 0;
    
    unordered_set<int> connected;

    connected.emplace(costs[0][0]);

    while(connected.size() < n && !costs.empty())
    {
        pair<Island, Cost> minimum({-1, numeric_limits<int>::max()});
        unsigned int index = 0;

        // 하나는 연결되어 있고 하나는 연결되지 않은 경우에서 최소값
        for(unsigned int i = 0; i < costs.size(); ++i)
        {
            const auto& costData = costs[i];
            
            const bool isFirstConnected = connected.find(costData[0]) != connected.end();
            const bool isSecondConnected = connected.find(costData[1]) != connected.end();

            if(isFirstConnected == isSecondConnected)
            {
                continue;
            }

            if(minimum.second > costData[2])
            {
                index = i;
                minimum = make_pair(isFirstConnected ? costData[1] : costData[0], costData[2]);
            }
        }
        
        connected.emplace(minimum.first);
        totalCost += minimum.second;
        costs.erase(costs.begin() + index);
    }

    return totalCost;
}

// int main()
// {
//     const vector<vector<int>> costs({{0,1,1}, {0,2,2}, {1,2,5}, {1,3,1}, {2,3,8}});
//
//     cout << solution(4, costs);
// }

/*문제 설명
n개의 섬 사이에 다리를 건설하는 비용(costs)이 주어질 때,
최소의 비용으로 모든 섬이 서로 통행 가능하도록 만들 때 필요한 최소 비용을 return 하도록 solution을 완성하세요.

다리를 여러 번 건너더라도, 도달할 수만 있으면 통행 가능하다고 봅니다.
예를 들어 A 섬과 B 섬 사이에 다리가 있고, B 섬과 C 섬 사이에 다리가 있으면 A 섬과 C 섬은 서로 통행 가능합니다.

제한사항

- 섬의 개수 n은 1 이상 100 이하입니다.
- costs의 길이는 ((n-1) * n) / 2이하입니다.
- 임의의 i에 대해, costs[i][0] 와 costs[i] [1]에는 다리가 연결되는 두 섬의 번호가 들어있고,
  costs[i] [2]에는 이 두 섬을 연결하는 다리를 건설할 때 드는 비용입니다.
- 같은 연결은 두 번 주어지지 않습니다. 또한 순서가 바뀌더라도 같은 연결로 봅니다.
  즉 0과 1 사이를 연결하는 비용이 주어졌을 때, 1과 0의 비용이 주어지지 않습니다.
- 모든 섬 사이의 다리 건설 비용이 주어지지 않습니다. 이 경우, 두 섬 사이의 건설이 불가능한 것으로 봅니다.
- 연결할 수 없는 섬은 주어지지 않습니다.

입출력 예

n	costs	                                    return
4	[[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]	4
*/