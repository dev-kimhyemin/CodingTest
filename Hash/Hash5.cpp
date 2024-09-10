#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 재생 횟수 총합이 큰 것 우선
bool sortWithTotalPlays(const pair<string, vector<pair<int, int>>>& v1, const pair<string, vector<pair<int, int>>>& v2)
{
    int sum1 = 0, sum2 = 0;
    
    for (const auto pair1 : v1.second)
    {
        sum1 += pair1.first;
    }

    for(const auto pair2 : v2.second)
    {
        sum2 += pair2.first;
    }

    return sum1 > sum2;
}

// pair<재생 횟수, 고유 번호>에서 재생 횟수가 같으면 고유 번호가 작은 것 우선, 아니면 재생 횟수가 큰 것 우선
bool sortWithPlays(const pair<int, int>& v1, const pair<int, int>& v2)
{
    if(v1.first == v2.first)
    {
        return v1.second < v2.second;
    }

    return v1.first > v2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    unordered_map<string, vector<pair<int, int>>> musicsMap;
    
    for(unsigned int i = 0; i < genres.size(); i++)
    {
        musicsMap[genres[i]].emplace_back(plays[i], i);
    }

    for(auto& musics : musicsMap)
    {
        sort(musics.second.begin(), musics.second.end(), sortWithPlays);
    }

    vector<pair<string, vector<pair<int, int>>>> sortedMusics(musicsMap.begin(), musicsMap.end());
    sort(sortedMusics.begin(), sortedMusics.end(), sortWithTotalPlays);

    vector<int> answer;

    for(auto& sortedMusic : sortedMusics)
    {
        for(int i = 0; i < min(2, static_cast<int>(sortedMusic.second.size())); i++)
        {
            answer.emplace_back(sortedMusic.second[i].second);
        }
    }

    return answer;
}

int main()
{
    const vector<string> genres({"classic", "pop", "classic", "classic", "pop"});
    const vector<int> plays({500, 600, 150, 800, 2500});

    const vector<int> answer = solution(genres, plays);

    for (const int i : answer)
    {
        cout << i << " ";
    }
}