#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
using namespace std;

int visit[305][305];
int parents[90005];
queue<pair<int, int>> q;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int find(int x)
{
    if (parents[x] == x)
        return x;
    int parent = find(parents[x]);
    parents[x] = parent;
    return parent;
}

void union_func(int x, int y)
{
    x = find(x);
    y = find(y);
    parents[y] = x;
}

ll solution(vector<vector<int>> land, int height) {
    ll answer = 0;

    int N = land.size();

    //bfs
    q.push({ 0,0 });
    int x, y, nx, ny, stair = 0;
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };
    bool remain = true;

    while (remain)   // 아직 체크하지 않은 칸 존재
    {
        remain = false;
        stair++;

        while (!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            visit[x][y] = stair;

            for (int i = 0; i < 4; i++)
            {
                nx = x + dx[i];
                ny = y + dy[i];

                if ((nx >= 0 && nx < N) && (ny >= 0 && ny < N)
                    && !visit[nx][ny]
                    && (abs(land[nx][ny] - land[x][y]) <= height))
                {
                    q.push({ nx, ny });
                }
            }

        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visit[i][j])
                {
                    q.push({ i, j });
                    remain = true;
                    break;
                }
            }
            if (remain)
                break;
        }
    }

    /*
    // 출력
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            cout<<visit[i][j]<<' ';
        }
        cout<<'\n';
    }
    */


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visit[i][j] != visit[i + 1][j] && i != N - 1)
                pq.push({ abs(land[i][j] - land[i + 1][j]), {visit[i][j], visit[i + 1][j]} });

            if (visit[i][j] != visit[i][j + 1] && j != N - 1)
                pq.push({ abs(land[i][j] - land[i][j + 1]), {visit[i][j], visit[i][j + 1]} });
        }
    }
    /*
    // 출력
    while(!pq.empty())
    {
        cout<<pq.top().first<<' '<<pq.top().second.first<<' '<<pq.top().second.second<<'\n';
        pq.pop();
    }
    */

    //최소신장트리
    //make_set
    for (int i = 1; i <= stair; i++)
        parents[i] = i;

    int dist, s1, s2;
    while (!pq.empty())
    {
        dist = pq.top().first;
        s1 = pq.top().second.first, s2 = pq.top().second.second;
        pq.pop();

        if (find(s1) != find(s2))
        {
            answer += dist;
            union_func(s1, s2);
        }
    }


    return answer;
}