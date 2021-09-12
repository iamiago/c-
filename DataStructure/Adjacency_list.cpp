#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int v;

    // tableau de list de
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printAdjList()
    {
        //iterate over all the vertices
        for (int i = 0; i < v; i++)
        {
            cout << "Vertex: " << i << "->";
            for (int nbr : l[i])
            {
                cout << nbr << ",";
            }
            cout << "\n";
        }
    }
};

int main()
{
    Graph graph = Graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.printAdjList();
    return 0;
}