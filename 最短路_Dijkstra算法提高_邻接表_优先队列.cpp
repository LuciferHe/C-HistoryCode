#include <iostream>
#include <queue>

#define MAX_EDGE 30
#define MAX_VERTEX 10
#define INFINITE 0x7fffffff
#define AL_END -1

using namespace std;

struct Vertex
{
	int vertex;
	int cost;
};

bool operator < (const Vertex &a, const Vertex &b)
{
	return a.cost > b.cost;
}

struct AlEdge
{
	int next;
	int vertex;
	int cost;
};

class AlGraph
{
public:
	int source;
	int destination;

	int edgeNum;
	int vertexNum;

	int allCost;

	void Dijkstra();

private:
	AlEdge edge[MAX_EDGE];
	priority_queue<Vertex> nextVertexQueue;
	int alVertex[MAX_VERTEX];
	bool vertexDealed[MAX_VERTEX];

	void initialize();
	void geteData();
};

void AlGraph::geteData()
{
	cout << "Please input the number of vertex: ";
	cin >> vertexNum;

	cout << "Please input the number of edge: ";
	cin >> edgeNum;

	cout << "Please input the source: ";
	cin >> source;

	cout << "Please input the destination: ";
	cin >> destination;

	cout << "Please input the edges.(source, destination, cost.)" << endl;
	int s, d, c;
	int ip = 0;
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> s >> d >> c;
		edge[ip].next = alVertex[s];
		edge[ip].vertex = d;
		edge[ip].cost = c;
		alVertex[s] = ip++;
	}
}

void AlGraph::initialize()
{
	memset(alVertex, AL_END, sizeof(alVertex));
	memset(vertexDealed, 0, sizeof(vertexDealed));

	allCost = 0;

	while (!nextVertexQueue.empty())
	{
		nextVertexQueue.pop();
	}

	geteData();
}

void AlGraph::Dijkstra()
{
	initialize();

	Vertex currentVertex;
	currentVertex.cost = 0;
	currentVertex.vertex = source;
	nextVertexQueue.push(currentVertex);

	while (!nextVertexQueue.empty())
	{
		currentVertex = nextVertexQueue.top();
		nextVertexQueue.pop();

		if (currentVertex.vertex == destination)
		{
			break;
		}

		if (vertexDealed[currentVertex.vertex])
		{
			continue;
		}

		vertexDealed[currentVertex.vertex] = true;

		Vertex nextVertex;
		for (int i = alVertex[currentVertex.vertex]; i != AL_END; i = edge[i].next)
		{
			if (!vertexDealed[edge[i].vertex])
			{
				nextVertex.vertex = edge[i].vertex;
				nextVertex.cost = currentVertex.cost + edge[i].cost;
				nextVertexQueue.push(nextVertex);
			}
		}

	}

	if (currentVertex.vertex == destination)
	{
		allCost = currentVertex.cost;
	}
	else
	{
		allCost = INFINITE;
	}
}

int main()
{
	AlGraph test;

	test.Dijkstra();
	cout << "The smallest cost is: " << test.allCost << endl;

	return 0;
}