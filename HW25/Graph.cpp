#include "Graph.h"
#include <queue>

GraphAdjList::GraphAdjList(int Vertixes, ConnectionType type)
    : Graph(Vertixes, type)
{
    m_list.resize(Vertixes);
}

void GraphAdjList::addEdge(int v, int w)
{
    m_list[v].push_back(w);
    if (m_connectionType == ConnectionType::undirected)
    {
        m_list[w].push_back(v);
    }
}

void GraphAdjList::BFS(int vertex)
{
    // Mark all the vertices as not visited
    std::vector<bool> visited;
    visited.resize(m_vertixes, false);

    std::list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[vertex] = true;
    queue.push_back(vertex);

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        int currentVertex = queue.front();

        //or make anything else with it: push to vector, string, pass to another object, whatever
        std::cout << currentVertex << " ";

        queue.pop_front();

        // Get all adjacent vertices
        for (int adjacent : m_list[currentVertex])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

int GraphAdjList::numberOfNodesInLevel(int level)
{
    if (level < 0 || static_cast<unsigned int>(level) >= m_vertixes)
    {
        return 0;
    }

    std::vector<int> distances(m_vertixes, -1);
    std::queue<int> queue;

    queue.push(0);
    distances[0] = 1;

    int currentLevel = 1;
    int nodesInCurrentLevel = 1;

    while (!queue.empty() && currentLevel < level)
    {
        int nodesInCurrentLevelTemp = 0;

        for (int i = 0; i < nodesInCurrentLevel; ++i)
        {
            int vertex = queue.front();
            queue.pop();

            for (int neighbor : m_list[vertex])
            {
                if (distances[neighbor] == -1)
                {
                    queue.push(neighbor);
                    distances[neighbor] = distances[vertex] + 1;
                }
            }
        }
    }
    int count = 0;
    for (int dist : distances)
    {
        if (dist == level)
        {
            count++;
        }
    }
    return count;
}

void GraphAdjList::DFS(int vertex, std::unordered_set<int>& visited) const
{
    visited.insert(vertex);

    for (int neighbor : m_list[vertex])
    {
        if (visited.find(neighbor) == visited.end())
        {
            DFS(neighbor, visited);
        }
    }
}

bool GraphAdjList::isConnectedFrom(int source) const
{
    std::unordered_set<int> visited;
    DFS(source, visited);

    return visited.size() == m_vertixes;
}

bool Graph::isStronglyConnected() const
{
    for (int i = 0; i < m_vertixes; ++i)
    {
        if (!isConnectedFrom(i))
        {
            return false;
        }
    }

    return true;
}