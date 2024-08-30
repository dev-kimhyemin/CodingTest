#include <iostream>
#include <queue>
#include <vector>

enum
{
    Max = 1001
};

using namespace std;

int NodeNum;
int NodePairNum;
int Answer;

vector<pair<int, int>> Graph[Max];
bool Visited[Max];


void InitializeVisitedArray()
{
    for (bool& i : Visited)
    {
        i = false;
    }
}

void Dfs(int start, int destination, int distance)
{
    if(start == destination)
    {
        Answer = distance;
        return;
    }
    
    for(const pair<int, int> &pair : Graph[start])
    {
        const int next = pair.first;
        const int weight = pair.second;
    
        if(!Visited[next])
        {
            Visited[next] = true;
            Dfs(next, destination, distance + weight);
            Visited[next] = false;
        }
    }
}

void Bfs(int start, int destination)
{
    queue<pair<int, int>> adjoinNodes;

    Visited[start] = true;
    adjoinNodes.emplace(start, 0);

    while(!adjoinNodes.empty())
    {
        const int currentNode = adjoinNodes.front().first;
        const int currentDistance = adjoinNodes.front().second;
        adjoinNodes.pop();

        if(currentNode == destination)
        {
            Answer = currentDistance;
        }
        
        for(const pair<int, int> &pair : Graph[currentNode])
        {
            const int next = pair.first;
            const int distance = pair.second;

            if(Visited[next] == false)
            {
                Visited[next] = true;
                adjoinNodes.emplace(next, currentDistance + distance);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    cin >> NodeNum >> NodePairNum;

    for(int i = 0; i < NodeNum - 1; i++)
    {
        int node1, node2, distance;
        
        cin >> node1 >> node2 >> distance;

        Graph[node1].emplace_back(node2, distance);
        Graph[node2].emplace_back(node1, distance);
    }
    
    for(int i = 0; i < NodePairNum; i++)
    {
        int node1 = 0;
        int node2 = 0;

        cin >> node1 >> node2;
        
        InitializeVisitedArray();

        Visited[node1] = true;
        // Dfs(node1, node2, 0);
        Bfs(node1, node2);
        Visited[node1] = false;

        cout << Answer << '\n';
    }
    
    return 0;
}
