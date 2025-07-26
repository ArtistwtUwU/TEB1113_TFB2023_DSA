/** Name: Mohd Adrian Firdaus bin Mohd Rosli
Student ID: 22011425 **/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    unordered_map<char, vector<char>> adjList;

    void addEdge(char u, char v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected
    }

    void BFS(char start) {
        unordered_map<char, bool> visited;
        queue<char> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";
        while (!q.empty()) {
            char current = q.front();
            q.pop();
            cout << current << " ";

            for (char neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g;

    g.addEdge('a', 'b');
    g.addEdge('b', 'e');
    g.addEdge('a', 'd');
    g.addEdge('a', 'c');
    g.addEdge('c', 'd');
    g.addEdge('d', 'e');
    g.addEdge('b', 'd');

    g.BFS('a');

    return 0;
}
