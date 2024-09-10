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

// int main()
// {
//     const vector<string> genres({"classic", "pop", "classic", "classic", "pop"});
//     const vector<int> plays({500, 600, 150, 800, 2500});
//
//     const vector<int> answer = solution(genres, plays);
//
//     for (const int i : answer)
//     {
//         cout << i << " ";
//     }
// }


/*문제 설명
스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다.
노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

1. 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
2. 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
3. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.

노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때,
베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.

제한사항
genres[i]는 고유번호가 i인 노래의 장르입니다.
plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
장르 종류는 100개 미만입니다.
장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
모든 장르는 재생된 횟수가 다릅니다.*/