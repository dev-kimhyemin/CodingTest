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

    int current = costs[0][0];
    connected.emplace(current);

    while(connected.size() < n)
    {
        pair<Island, Cost> minimum({-1, numeric_limits<int>::max()});
        unsigned int index = 0;

        if(costs.empty())
        {
            break;
        }

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