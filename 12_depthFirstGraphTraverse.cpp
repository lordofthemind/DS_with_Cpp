#include <iostream>
#include <stack>
using namespace std;

// Define maximum number of vertices in the graph
#define MAX_VERTICES 100

// Define graph class
class Graph
{
private:
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;

public:
    // Constructor
    Graph(int num_vertices)
    {
        this->num_vertices = num_vertices;
        for (int i = 0; i < num_vertices; i++)
        {
            for (int j = 0; j < num_vertices; j++)
            {
                adjacency_matrix[i][j] = 0;
            }
        }
    }

    // Add an edge to the graph
    void add_edge(int src, int dest)
    {
        adjacency_matrix[src][dest] = 1;
        adjacency_matrix[dest][src] = 1; // for undirected graphs
    }

    // Depth-first search traversal
    void dfs(int start_vertex)
    {
        bool visited[num_vertices] = {false};
        stack<int> s;

        s.push(start_vertex);

        while (!s.empty())
        {
            int current_vertex = s.top();
            s.pop();

            if (!visited[current_vertex])
            {
                cout << current_vertex << " ";
                visited[current_vertex] = true;

                // Visit all the adjacent vertices
                for (int i = 0; i < num_vertices; i++)
                {
                    if (adjacency_matrix[current_vertex][i] == 1 && !visited[i])
                    {
                        s.push(i);
                    }
                }
            }
        }
    }
};

// Main function
int main()
{
    Graph g(6);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 5);

    cout << "Depth-first traversal starting from vertex 0: ";
    g.dfs(0);
    cout << endl;

    return 0;
}
