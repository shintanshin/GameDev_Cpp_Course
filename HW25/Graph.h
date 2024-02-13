#pragma once
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>

class Graph
{
public:
	enum class ConnectionType
	{
		undirected,
		directed
	};

	Graph(int vertixes, ConnectionType type = ConnectionType::undirected)
		: m_vertixes(vertixes), m_connectionType(type) {}

	virtual void addEdge(int v, int w) = 0;
	virtual void BFS(int vertex = 0) {};
	virtual void DFS(int vertex = 0) {};
	bool isStronglyConnected() const;

	virtual bool isConnectedFrom(int source) const = 0;

protected:
	unsigned int m_vertixes;
	ConnectionType m_connectionType;
};

// using adjacency list
class GraphAdjList : public Graph
{
public:
	GraphAdjList(int vertixes, ConnectionType type = ConnectionType::undirected);
	void addEdge(int v, int w) override;

	void BFS(int vertex = 0) override;

	int numberOfNodesInLevel(int level);

	void DFS(int vertex, std::unordered_set<int>& visited) const;
	bool isConnectedFrom(int source) const;

private:
	std::vector<std::list<int> > m_list;
};

class GraphAdjMatrix : public Graph
{
	using Graph::Graph;

	void addEdge(int v, int w) override {};
	void DFS(int vertex = 0) override {};

private:
	std::vector<std::vector<bool>> m_matrix;
};