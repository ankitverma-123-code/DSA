#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph
{
    unordered_map<T, list<pair<T, int>>> g;
    unordered_map<T, int> dist;

public:
    void addEdeges(int u, int v, int w, bool bidir = true)
    {
        g[u].push_back({v, w});
        if (bidir)
            g[v].push_back({u, w});
    }

    void printGraph()
    {
        for (auto it : g)
        {
            cout << it.first << "->";
            for (auto j : it.second)
            {
                cout << "(" << j.first << "," << j.second << "),";
            }
            cout << endl;
        }
    }

    void dijisktra(int src)
    {
        for (auto it : g)
        {
            dist[it.first] = INT_MAX;
        }
        dist[src] = 0;
        set<pair<int, T>> s;
        s.insert({0, src});

        while (!s.empty())
        {
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            for (auto nbr : g[node])
            {
                if (nodeDist + nbr.second < dist[nbr.first])
                {
                    T destination = nbr.first;
                    auto f = s.find({dist[destination], destination});

                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    dist[destination] = nodeDist + nbr.second;
                    s.insert({dist[destination], destination});
                }
            }
        }
    }

    void printmindistance()
    {
        for (auto it : g)
        {
            if (dist[it.first] == 0)
                continue;
            if (dist[it.first] == INT_MAX)
            {
                cout << "-1" << endl;
                continue;
            }
            cout << dist[it.first] << " ";
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Graph<int> g;
        int n, e;
        cin >> n >> e;
        for (int i = 0; i < e; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            g.addEdeges(a, b, w);
        }
        int src;
        cin >> src;
        g.dijisktra(src);
        g.printmindistance();
    }
}
