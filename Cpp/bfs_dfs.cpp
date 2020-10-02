/*
A C++ Program to implement BFS and DFS traversal of a Graph.
The major difference between BFS and DFS is
that BFS uses a queue for handling vertices, while DFS uses a stack.
*/

#include <bits/stdc++.h>
//Macro to define the maximum vertices of the graph.
#define MAX 100

using namespace std;

//Function for BFS Traversal. 
void BFS(int source, int graph[][MAX], int n)
{
    queue<int> q;
    int i, visited[MAX] = {0}, counter = 0;
    q.push(source);
    visited[source] = 1;

    while (!q.empty())
    {
        counter++;
        source = q.front();
        q.pop();
        cout << source;
        if (counter < n)
        {
            cout << " --> ";
        }

        for (i = 0; i < n; i++)
        {
            if (graph[source][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    //Code fragment to traverse disconnected Graph
        if (q.empty() && counter < n)
        {
            for (i = 0; i < n; i++)
            {
                if (visited[i] == 0)
                {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
}

//Function for DFS Traversal
void DFS(int source, int graph[][MAX], int n)
{
    stack<int> s;
    int i, visited[MAX] = {0}, counter = 0;

    visited[source] = 1;
    s.push(source);
    do
    {
        counter++;
        source = s.top();
        s.pop();
        cout << source;
        if (counter < n)
        {
            cout << " --> ";
        }
        for (i = 0; i < n; i++)
        {
            if (graph[source][i] == 1 && visited[i] == 0)
            {
                s.push(i);
                visited[i] = 1;
            }
        }
    
    //Code fragment to traverse disconnected Graph
        if (s.empty() && counter < n)
        {
            for (i = 0; i < n; i++)
            {
                if (visited[i] == 0)
                {
                    s.push(i);
                    visited[i] = 1;
                }
            }
        }

    } while (!s.empty());
}

int main()
{
    int graph[MAX][MAX];
    int v1, v2, source, i, j, n, e;
    cout << "Enter the number of Vertices and Edges of the Graph:\n";
    cin >> n;
    cin >> e;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    cout << "\nEnter the " << e << " Edges of the Graph" << endl;

    for (i = 0; i < e; i++)
    {
        cin >> v1;
        cout << "\033[1A\033[1C --> ";
        cin >> v2;
        graph[v1][v2] = 1;
        cout << "\n";
    }

    cout << "Enter the staring vertex\n";
    cin >> source;

    cout << "DFS Traversal for the matrix is " << endl;
    DFS(source, graph, n);
    cout << "\n\n";
    cout << "BFS Traversal for the matrix is " << endl;
    BFS(source, graph, n);

    return 0;
}

/*
Test I/O
Enter the number of Vertices and Edges of the Graph:
10
14

Enter the 14 Edges of the Graph
0 --> 1

0 --> 3

3 --> 1

1 --> 2

2 --> 3

0 --> 4

4 --> 5

5 --> 6

6 --> 5

4 --> 7

7 --> 0

9 --> 7

9 --> 8

8 --> 7

Enter the staring vertex
0
DFS Traversal for the matrix is 
0 --> 4 --> 7 --> 5 --> 6 --> 3 --> 1 --> 2 --> 9 --> 8

BFS Traversal for the matrix is 
0 --> 1 --> 3 --> 4 --> 2 --> 5 --> 7 --> 6 --> 8 --> 9
*/
