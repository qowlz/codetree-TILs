#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;

    vector<P> arr(n, make_pair(0, 0));
    priority_queue<P, vector<P>, greater<P>> pq;
    for (int i = 0; i < n; i++)
    {
        int a, t;
        cin >> a >> t;
        arr[i] = make_pair(a, t);
        pq.push(make_pair(a, i));
    }

    int current = 0;
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> wait;
    while(!pq.empty() || !wait.empty())
    {
        // 현재 시간 기준 대기자 명단 구성
        while (!pq.empty() && current >= pq.top().first)
        {
            wait.push(pq.top().second);
            pq.pop();
        }

        if (wait.empty()) // 대기자가 없는 경우
        {
            int a, i;
            tie(a, i) = pq.top();
            pq.pop();

            current = a + arr[i].second;
        }
        else // 대기자가 있는 경우
        {
            int i = wait.top();
            wait.pop();

            answer = max(answer, current - arr[i].first);
            current += arr[i].second;
        }
    }

    cout << answer;

    return 0;
}