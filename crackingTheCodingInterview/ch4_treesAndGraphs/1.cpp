/*
  Chapter 4 (trees and graphs) Problem 1
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>

// Struct Node for a graph node
struct Node {
    int data;
    std::vector<Node*> adjacentVertex;
    bool visited;
    Node(int iD) : data {iD}, visited {false}{ }

    //output operator
    friend std::ostream& operator<<(std::ostream &os, const Node& node);
};

//output operator for Node class
std::ostream& operator<<(std::ostream &os, const Node& node) {
    os << node.data << ": ";
    for (auto &i : node.adjacentVertex) {
        os << i->data << " ";
    }
    return os;
}

// Graph class as Adjacency List representation
struct Graph {
    std::vector<Node*> nodes;                        //i think this could work really
    std::map<Node*, bool> visited;

    void readGraph () {  //TODO: should just pass an input stream (that could be file or whatever and should read from there)
        //vertex and edges...
        std::ifstream file("./4_treesAndGraphs/4.1.in");
        if (!file) {
            std::cout << "File not found.." << std::endl;
            return;
        }
        std::string line;
        int v = 0 , numVWithE = 0;
        file >> v;
        for (int i = 0; i < v; i++)
            nodes.push_back(new Node{i});
        file >> numVWithE;
        while (std::getline(file, line)) {
            std::istringstream is {line};
            int origV = 0, destV = 0;
            is >> origV;
            while (is >> destV) {
                nodes[origV]->adjacentVertex.push_back(nodes[destV]);
            }
        }

    }

    // --recursive method that will fill visited vector, of nodes that are reachable from 'root'
    void depthFirstSearch (Node* root) {
        if (root == nullptr) return;
        visited[root] = true;  //a node can always reach itself
        for (const auto &el : root->adjacentVertex)
            if (!visited[el])  //so that we don't enter in a infinite loop
                depthFirstSearch(el);
    }

    // --method that check if there's a path between orig and dest
    bool pathCheck(int orig, int dest) {
        //cleaning visited to false in case it was used in a previous run
        std::for_each(nodes.begin(), nodes.end(), [&visited = visited] (auto &el) { visited[el] = false;});

        depthFirstSearch(nodes[orig]);
        return visited[nodes[dest]];
    }

    //output operator
    friend std::ostream& operator<<(std::ostream &os, const Graph& node);
};

//output operator for LinkedList class
std::ostream& operator<<(std::ostream &os, const Graph& graph) {
    for (const auto &i : graph.nodes)
        os << *i << std::endl;
    return os;
}




int main () {
    Graph aG;

    aG.readGraph();
    std::cout << aG << std::endl;
    std::cout << "after printing " << std::endl;

    int pathOrig = 0, pathDest = 0;
    while (std::cout << "Please input origin and destination node(separated by space): " && std::cin >> pathOrig >> pathDest) {
        std::cout << "There's path between them? " << aG.pathCheck(pathOrig, pathDest) << std::endl;
    }

    return 0;
}


/*
bool isRoute(int a, int b, bool graph[][MAX]){
    queue<int> Que;
    bool visited[MAX] = {false};
    Que.push(a);
    visited[a] = true;
    int tmp;
    while(!Que.empty()){
        tmp = Que.front();
        Que.pop();
        for(int i=0; i<MAX; i++){
            if(graph[tmp][i] && !visited[i]){
                if(b==i)
                    return true;
                Que.push(i);
                visited[i]=true;
            }
        }
    }
    return false;
}
 int main(){
    freopen("./4.2.in", "r", stdin);
    int n, m, u, v;
    bool dgraph[MAX][MAX];
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        dgraph[u][v] = true;
    }
    cout<<isRoute(0, 3, dgraph);
}

 */