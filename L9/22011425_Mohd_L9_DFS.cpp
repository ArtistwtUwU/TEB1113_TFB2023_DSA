/** Name: Mohd Adrian Firdaus bin Mohd Rosli
Student ID: 22011425 **/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    unordered_map<char, vector<char>> adjList;

    void addEdge(char u, char v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected
    }

    void DFS(char start) {
        unordered_map<char, bool> visited;
        stack<char> s;

        s.push(start);
        cout << "DFS: ";
        while (!s.empty()) {
            char current = s.top();
            s.pop();

            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";

                // Reverse iterate to match recursive-like behavior
                for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it) {
                    if (!visited[*it]) {
                        s.push(*it);
                    }
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

    g.DFS('a');

    return 0;
}