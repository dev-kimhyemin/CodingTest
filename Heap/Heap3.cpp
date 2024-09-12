#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void insert(deque<int>& numbers, const int number)
{
    for(unsigned int i = 0; i < numbers.size(); ++i)
    {
        if(numbers[i] <= number)
        {
            continue;
        }

        numbers.emplace(numbers.begin() + i, number);
        return;
    }

    numbers.emplace(numbers.begin() + static_cast<int>(numbers.size()), number);
}

vector<int> solution(vector<string> operations)
{
    deque<int> numbers;

    for(const string& operation : operations)
    {
        const string delimiter = " ";
        const size_t delimiterLocation = operation.find(delimiter);
        
        const string flag = operation.substr(0, delimiterLocation);
        const string numberString = operation.substr(delimiterLocation + 1, operation.length() - delimiterLocation - 1);
        const int number = stoi(numberString);

        if(flag == "I")
        {
            insert(numbers, number);
        }
        else if(flag == "D")
        {
            if(numbers.empty())
            {
                continue;
            }
            
            if(number > 0)
            {
                numbers.pop_back();
            }
            else
            {
                numbers.pop_front();
            }
        }
    }

    vector<int> answer;
    answer.emplace_back(numbers.empty() ? 0 : numbers.back());
    answer.emplace_back(numbers.empty() ? 0 : numbers.front());

    return answer;
}

int main()
{
    const vector<int> answer = solution({"D 1", "I 5", "D -1", "D -1"});
    for(const int a : answer)
    {
        cout << a << ", ";
    }
}