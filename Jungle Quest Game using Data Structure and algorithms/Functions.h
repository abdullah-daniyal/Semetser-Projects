#include<iostream>
#include <cstdlib>
#include <cstring>
#include <windows.h>
using namespace std;

const int ROWS = 20;
const int COLS = 20;
char** making_map() {
    char** matrix = new char* [ROWS];
    int i = 0;
    while (i < ROWS) {
        matrix[i] = new char[COLS];
        int j = 0;
        while (j < COLS) {
            matrix[i][j] = 'C';
            j++;
        }
        i++;
    }


    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Add the crystal to a random location in the matrix
    int crystal_x = std::rand() % 20;
    int crystal_y = std::rand() % 20;
    matrix[crystal_x][crystal_y] = '*';

    // Add 25 rewards to random locations in the matrix
    char rewards[3] = { 'J', 'P', 'W' };
    i = 0;
    while (i < 25)
    {
        int reward_x = std::rand() % 20;
        int reward_y = std::rand() % 20;
        while (matrix[reward_x][reward_y] != 'C')
        {
            reward_x = std::rand() % 20;
            reward_y = std::rand() % 20;
        }
        matrix[reward_x][reward_y] = rewards[std::rand() % 3];
        i++;
    }
    // Add 15 death points to random locations in the matrix
    i = 0;
    while (i < 10)
    {
        int death_x = std::rand() % 20;
        int death_y = std::rand() % 20;
        while (matrix[death_x][death_y] != 'C')
        {
            death_x = std::rand() % 20;
            death_y = std::rand() % 20;
        }
        matrix[death_x][death_y] = '%';
        i++;
    }

    // Add 50 obstacles to random locations in the matrix
    i = 0;
    while (i < 50)
    {
        int obstacle_x = std::rand() % 20;
        int obstacle_y = std::rand() % 20;
        while (matrix[obstacle_x][obstacle_y] != 'C')
        {
            obstacle_x = std::rand() % 20;
            obstacle_y = std::rand() % 20;
        }
        matrix[obstacle_x][obstacle_y] = '#';
        i++;
    }

    // Add 20 monsters to random locations in the matrix
    char monsters[3] = { '&', '$', '@' };
    i = 0;
    while (i < 20)
    {
        int monster_x = std::rand() % 20;
        int monster_y = std::rand() % 20;
        while (matrix[monster_x][monster_y] != 'C')
        {
            monster_x = std::rand() % 20;
            monster_y = std::rand() % 20;
        }
        matrix[monster_x][monster_y] = monsters[std::rand() % 3];
        i++;
    }
    return matrix;

}


void DisplayMap(char map2[][20]) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // handle to console
    cout << "\t\t _____________________________________________________________________________" << endl;
    cout << "\t\t|                                                                             |" << endl;
    cout << "\t\t|                                   MAP                                       |" << endl;
    cout << "\t\t|_____________________________________________________________________________|" << endl << endl;
    for (int row = 0; row < 20; row++)
    {
        cout << "\t\t\t";
        for (int col = 0; col < 20; col++)
        {
            switch (map2[row][col]) {
            case 'C': SetConsoleTextAttribute(hConsole, 15); break; // white
            case '*': SetConsoleTextAttribute(hConsole, 14); break; // yellow
            case 'J': SetConsoleTextAttribute(hConsole, 10); break; // green
            case 'P': SetConsoleTextAttribute(hConsole, 11); break; // light cyan
            case 'W': SetConsoleTextAttribute(hConsole, 12); break; // red
            case '&': SetConsoleTextAttribute(hConsole, 13); break; // magenta
            case '$': SetConsoleTextAttribute(hConsole, 9); break;  // blue
            case '@': SetConsoleTextAttribute(hConsole, 6); break;  // yellow
            case '%': SetConsoleTextAttribute(hConsole, 4); break;  // red
            case '#': SetConsoleTextAttribute(hConsole, 8); break;  // gray
            }
            cout << map2[row][col] << "  ";
        }
        SetConsoleTextAttribute(hConsole, 15); // reset color to white
        cout << endl;
    }
}

class Axis
{
public:
    int src, dest, weight;
};

// Define comparison function to sort edges
bool compare_Axis(Axis e1, Axis e2)
{
    return e1.weight < e2.weight;
}

// Find parent of vertex using path compression technique
int found_parent(int parent[], int i)
{
    switch (parent[i] == i) {
    case true:
        return i;
    case false:
        return parent[i] = found_parent(parent, parent[i]);
    }
}


// Perform union of two vertices using rank heuristic
void unionVertices(int parent[], int rank[], int x, int y)
{
    int xroot = found_parent(parent, x);
    int yroot = found_parent(parent, y);

    int compare = rank[xroot] - rank[yroot];
    switch (compare) {
    case -1:
        parent[xroot] = yroot;
        break;
    case 1:
        parent[yroot] = xroot;
        break;
    default:
        parent[yroot] = xroot;
        rank[xroot]++;
        break;
    }
}


// Implement Kruskal's algorithm using adjacency matrix
void Kruskal_Algoritm(char** adjacencyMatrix, int V)
{
    Axis* edges = new Axis[V * V];
    int count = 0;

    // Populate edges vector with all edges in the graph
    for (int i = 0; i < V * V; i++)
    {
        int row = i / V;
        int col = i % V;
        if (adjacencyMatrix[row][col] != '0')
        {
            edges[count].src = row;
            edges[count].dest = col;
            edges[count].weight = adjacencyMatrix[row][col] - '0';
            count++;
        }
    }

    // Sort edges in non-decreasing order of their weights
    sort(edges, edges + count, compare_Axis);

    Axis* minimumSpanningTree = new Axis[V - 1];
    int* parent = new int[V];
    int* rank = new int[V];

    // Initialize parent and rank arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    int i = 0, j = 0;
    while (i < V - 1 && j < count)
    {
        Axis nextEdge = edges[j++];

        int x = found_parent(parent, nextEdge.src);
        int y = found_parent(parent, nextEdge.dest);

        switch (x == y) {
        case true:
            break;
        case false:
            minimumSpanningTree[i++] = nextEdge;
            unionVertices(parent, rank, x, y);
            break;
        }
    }

    // Print the minimum spanning tree
    cout << "*********MINIMUM SPANNING TREE USING KRUSKAL'S ALGORITHM*********" << endl;
    for (i = 0; i < V - 1; i++)
    {
        cout << minimumSpanningTree[i].src << " - " << minimumSpanningTree[i].dest << " : " << minimumSpanningTree[i].weight << endl;
    }

    delete[] edges;
    delete[] minimumSpanningTree;
    delete[] parent;
    delete[] rank;
}


//Declaring Global Variables
const int SIZE_IN_MAX = 400;
const char INF = '0';

int carry_min_index(char* key, bool* mstSet)
{
    int min_index = -1, min_value = INT_MAX;

    int i = 0;
    while (i < SIZE_IN_MAX) {
        switch (mstSet[i]) {
        case true:
            break;
        case false:
            switch (key[i] < min_value) {
            case true:
                min_index = i;
                min_value = key[i];
                break;
            case false:
                break;
            }
            break;
        }
        i++;
    }

    return min_index;
}

//Implementing prims algorithm to find print of adjacency matrix
void Prims_algorithm(char** graph, int size) {
    char* parent = new char[size];
    char* key = new char[size];
    bool* mstSet = new bool[size];

    int i = 0;
    while (i < size) {
        key[i] = INF;
        mstSet[i] = false;
        i++;
    }

    key[0] = 0;
    parent[0] = -1;

    i = 0;
    while (i < size - 1) {
        int u = carry_min_index(key, mstSet);
        mstSet[u] = true;

        int v = 0;
        while (v < size) {
            switch (graph[u][v]) {
            case INF:
                break;
            default:
                switch (mstSet[v]) {
                case true:
                    break;
                case false:
                    switch (graph[u][v] < key[v]) {
                    case true:
                        parent[v] = u;
                        key[v] = graph[u][v];
                        break;
                    case false:
                        break;
                    }
                    break;
                }

                break;
            }
            v++;
        }
        i++;
    }

    cout << "PRIM'S MINIMUM SPANNING TREE:" << endl;
    i = 1;
    while (i < size) {
        cout << parent[i] << " - " << i << "  " << (int)graph[i][parent[i]] << endl;
        i++;
    }
}