#include <bits/stdc++.h>

using namespace std;

class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int val, int wt)
    {
        this->v = val;
        this->w = wt;
    }

    Edge(){};
};

vector<vector<Edge *>> graph(7, vector<Edge *>());

void AddCheck(int u, int v, int w)
{
    if (u >= graph.size() || u < 0 || v < 0 || v >= graph.size())
        return;

    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}

void Display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " => ";
        for (int j = 0; j < graph[i].size(); j++)
            cout << "(" << graph[i][j]->v << "|" << graph[i][j]->w << ") ";

        cout << endl;
    }
}

//Remove Edge & Vertex ============================================
void removeEdge(int u, int v)
{
    int i = -1;
    int j = -1;

    for (int k = 0; i < graph[u].size(); k++)
    {
        if (graph[u][k]->v == v)
        {
            i = k;
            break;
        }
    }

    for (int k = 0; k < graph[v].size(); k++)
    {
        if (graph[v][k]->v == u)
        {
            j = k;
            break;
        }
    }

    graph[u].erase(graph[u].begin() + i);
    graph[v].erase(graph[v].begin() + j);
}

void removeVtx(int u)
{
    for (int i = graph[u].size() - 1; i >= 0; i--)
    {
        removeEdge(graph[u][i]->v, u);
    }
}

//HasPath =============================================
bool hasPath(int src, int des, vector<bool> &visited, string str)
{
    if (visited[src])
        return false;

    if (src == des)
    {
        cout << str << endl;
        return true;
    }

    visited[src] = true;
    bool res = false;

    for (Edge *e : graph[src])
    {
        int v = e->v;
        res = res || hasPath(v, des, visited, str + to_string(v) + "->");
    }

    return res;
}

//All Path-Has Path ===============================================
void allPath(int src, int des, vector<bool> &visited, string str)
{
    if (visited[src])
        return;

    if (src == des)
    {
        cout << str << endl;
        return;
    }

    visited[src] = true;

    for (Edge *e : graph[src])
    {
        int v = e->v;
        allPath(v, des, visited, str + to_string(v) + "->");
    }

    visited[src] = false;
}

//Pre-Order =======================================================
void PreOrderPath(int src, int des, vector<bool> &visited, string str)
{

    visited[src] = true;

    for (Edge *e : graph[src])
    {
        int v = e->v;
        allPath(v, des, visited, str + to_string(v) + "->");
    }

    visited[src] = false;
}

//Hamiltonian Path=================================================
void HamiltonianPathCycle(int src, int osrc, int cnt, vector<bool> &visited, string ans)
{
    if (cnt == graph.size() - 1)
    {
        cout << ans + to_string(src);

        for (Edge *e : graph[src])
        {
            if (e->v == osrc)
            {
                cout << " ->cycle";
            }
        }

        cout << endl;
        return;
    }

    visited[src] = true;

    for (Edge *e : graph[src])
    {
        int v = e->v;

        if (!visited[v])
        {
            HamiltonianPathCycle(v, osrc, cnt + 1, visited, ans + to_string(src));
        }
    }

    visited[src] = false;
}

//Bipartite Graph==================================================

class bpair
{
public:
    int vtx = 0;
    int color = 0;

    bpair(int s, int c)
    {
        this->vtx = s;
        this->color = c;
    }
};

bool bipartite(int src, vector<int> &vis)
{
    list<bpair> que;

    bpair root(src, 0);
    que.push_back(root);

    while (que.size() > 0)
    {
        bpair rem = que.front();
        que.pop_front();

        if (vis[rem.vtx] != -1)
        {
            if (vis[rem.color] != rem.color)
            {
                return false;
            }
        }

        vis[rem.vtx] = rem.color;

        for (Edge *e : graph[rem.vtx])
        {
            if (vis[e->v] == -1)
            {
                bpair npair(e->v, (rem.color + 1) % 2);
                que.push_back(npair);
            }
        }
    }

    return true;
}

//Djikstraaa=================================================================
class dpair{
    public:
    int u = 0;
    int w = 0;
    int wsf = 0;
    string psf = "";

    dpair(int u, int w, int wsf, string psf)
    {
        this->u = u;
        this->w = w;
        this->wsf = wsf;
        this->psf = psf;
    }

    bool operator<(const dpair &o) const
    {
        // return this->wsf > o.wsf; for djikstraa //min heap
        return this->w > o.w; //Prims
    }
};

void djikstra(int src, int des)
{
    priority_queue<dpair> que;
    dpair root(src, 0, 0, to_string(src));
    que.push(root);

    vector<bool> visited(graph.size(), false);
    bool path = false;

    while(que.size()>0)
    {
        dpair rem = que.top();
        que.pop();

        if(rem.u == des && !path)
        {
            path = true;
            cout<<rem.psf<<"@"<<rem.wsf<<endl;
        }
        if(visited[rem.u])
        {
            continue;
        }

        visited[rem.u] = true;

        for(Edge *e: graph[rem.u])
        {
            if(!visited[e->v])
            {
                dpair npair(e->v, e->w, rem.wsf+e->w, rem.psf+to_string(e->v));
                que.push(npair);
            }
        }
    }
}
//Prims======================================================================

void Prims(int src, int des)
{
    priority_queue<dpair> que;
    dpair root(src, 0, 0, to_string(src));
    que.push(root);

    vector<bool> visited(graph.size(), false);
    bool path = false;

    while(que.size() > 0)
    {
        dpair rem = que.top();
        que.pop();

        if(rem.u == des && !path)
        {
            path = true;
            cout << rem.psf << " -> " << rem.wsf << endl;
        }

        if(visited[rem.u])
        {
            continue;
        }

        visited[rem.u] = true;

        for(Edge *e: graph[rem.u])
        {
            dpair npair(e->v, e->w, rem.wsf+e->w, rem.psf+to_string(e->v));
            que.push(npair);
        }
    }    
}
//===========================================================================

int main(int args, char **argv)
{
    AddCheck(0, 3, 10);
    AddCheck(0, 1, 10);
    AddCheck(1, 2, 10);
    AddCheck(2, 3, 40);
    AddCheck(3, 4, 2);
    AddCheck(4, 5, 2);
    AddCheck(4, 6, 3);
    AddCheck(5, 6, 8);
    cout << "Initial Graph============" << endl;
    Display();
    cout<<"====="<<endl;

    // vector<bool> visited(graph.size(), false);
    vector<int> visited(graph.size(), -1);
    // hasPath(0, 6, visited, "");
    // allPath(0, 6, visited, "");
    // HamiltonianPathCycle(0, 0, 0, visited, "");
    // for (int i = 0; i < graph.size(); i++)
    // {
    //     cout << "RES=" << bipartite(i, visited) << endl;
    // }
    // cout << "Insert vertex to be deleted:";
    // int edge;
    // cin >> edge;
    // removeVtx(edge);
    // djikstra(0, 6);
    Prims(2, 6);

    // cout << "Graph after deletion" << endl;
    // Display();
}
