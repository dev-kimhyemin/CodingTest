#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <limits>

using namespace std;

typedef pair<int, int> NodeWeightPair;
typedef vector<vector<NodeWeightPair>> Graph;

vector<int> Dijkstra(const Graph& graph, int start)
{
    const int size = static_cast<int>(graph.size());
    vector<int> dist(size, numeric_limits<int>::max());
    priority_queue<NodeWeightPair, vector<NodeWeightPair>, greater<>> minHeap;

    dist[start] = 0;
    minHeap.emplace(start, 0);

    while(!minHeap.empty())
    {
        const int currentNode = minHeap.top().first;
        const int currentDist = minHeap.top().second;
        minHeap.pop();

        if(currentDist > dist[currentNode])
        {
            continue;
        }

        for(const auto& neighbor : graph[currentNode])
        {
            const int nextNode = neighbor.first;
            const int weight = neighbor.second;

            if(dist[currentNode] + weight < dist[nextNode])
            {
                dist[nextNode] = dist[currentNode] + weight;
                minHeap.emplace(nextNode, dist[nextNode]);
            }
        }
    }

    return dist;
}

int main()
{
    constexpr int nodeNumber = 5;
    Graph graph(nodeNumber);

    graph[0].emplace_back(1, 10);
    graph[0].emplace_back(3, 5);
    graph[1].emplace_back(2, 1);
    graph[1].emplace_back(3, 2);
    graph[2].emplace_back(4, 4);
    graph[3].emplace_back(1, 3);
    graph[3].emplace_back(2, 9);
    graph[3].emplace_back(4, 2);
    graph[4].emplace_back(0, 7);
    graph[4].emplace_back(2, 6);

    constexpr int start = 2;
    const vector<int> distances = Dijkstra(graph, start);

    for (int i = 0; i < nodeNumber; i++)
    {
        if (distances[i] == numeric_limits<int>::max())
        {
            cout << "Vertex " << i << ": Unreachable" << '\n';
        }
        else if(distances[i] == 0)
        {
            cout << "Vertex " << i << ": Start Point" << '\n';
        }
        else
        {
            cout << "Vertex " << i << ": " << distances[i] << '\n';
        }
    }

    return 0;
}
