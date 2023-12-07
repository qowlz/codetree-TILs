#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K, P, T;
    cin >> N >> K >> P >> T;
    
    const int MAX_TIME = 250;
    vector<pair<int, int>> arr(MAX_TIME + 1, make_pair(0, 0));
    for (int i = 0; i < T; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        arr[t] = make_pair(x, y);   
    }

    vector<int> answer(N + 1, 0);
    vector<int> people(N + 1, 0);
    people[P] = K; answer[P] = 1;
    for (int i = 1; i <= 250; i++)
    {
        // 둘다 감염되어있는 상태일떄
        if (answer[arr[i].first] && answer[arr[i].second])
        {
            people[arr[i].first]--;
            people[arr[i].second]--;
        }
        else if (!answer[arr[i].first] && people[arr[i].second] > 0) // 왼쪽 신규 감염 케이스
        {
            people[arr[i].second]--;

            answer[arr[i].first] = 1;
            people[arr[i].first] = K;
        }
        else if (people[arr[i].first] > 0 && !answer[arr[i].second]) // 오른쪽 신규 감염 케이스
        {
            people[arr[i].first]--;

            answer[arr[i].second] = 1;
            people[arr[i].second] = K;
        }
    }

    for (int i = 1; i <= N; i++) cout << answer[i];

    return 0;
}