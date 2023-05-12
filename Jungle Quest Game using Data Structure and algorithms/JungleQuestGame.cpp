#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include "Menu.h"
#include "Functions.h"
#include<windows.h>

using namespace std;
const char START = '0', END = '*', OBSTACLE = '#', DEATH = '%';
// const int ROWS = 20, COLS = 20;
const int INDEX_LENGTH = 20;
const int SIZE_int = 20;
//Avl implementation
struct Node {
public:
    int val; // score
    int id;// name of the player
    int counter;
    int height;
    Node* left;
    Node* right;

    Node(int id, int v) {
        val = v;
        this->id = id;
        height = 1;
        left = nullptr;
        right = nullptr;
        this->counter = 1;
    }
};

int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

void updateHeight(Node* node) {
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

Node* SingleRotateWithRight(Node* k1) {
    Node* k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
    k2->height = max(getHeight(k2->right), k1->height) + 1;
    return k2;
}

Node* SingleRotateWithLeft(Node* k1) {
    Node* k2;
    k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
    k2->height = max(getHeight(k2->left), k1->height) + 1;
    return k2;
}

Node* DobubleRotateWithRight(Node* k1) {
    k1->right = SingleRotateWithLeft(k1->right);
    return SingleRotateWithRight(k1);
}

Node* DobubleRotateWithLeft(Node* k1) {
    k1->left = SingleRotateWithLeft(k1->left);
    return SingleRotateWithLeft(k1);
}
class AVLTree {
public:
    Node* root;
    AVLTree() {
        root = NULL;
    }
    Node* insert(Node* T, int id, int score) {
        if (T == NULL) {
            T = new Node(id, score);
        }
        else if (id < T->val) {
            T->left = insert(T->left, id, score);
            if (getHeight(T->left) - getHeight(T->right) == 2) {
                if (id < T->left->val) {
                    T = SingleRotateWithLeft(T);
                }
                else {
                    T = DobubleRotateWithLeft(T);
                }
            }
        }
        else if (id > T->val) {
            T->right = insert(T->right, id, score);
            if (getHeight(T->right) - getHeight(T->left) == 2) {
                if (id > T->right->val) {
                    T = SingleRotateWithRight(T);
                }
                else {
                    T = DobubleRotateWithRight(T);
                }
            }
        }
        else if (id == T->val) {
            T->counter++;
            return T;
        }
        T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
        return T;
    }

    void display(Node* node) {
        if (node == nullptr) {
            return;
        }
        // Inorder traversal to display the nodes in ascending order
        display(node->left);
        cout << "ID+count: " << node->id << ", Score: " << node->val << ", Count: " << node->counter << endl;
        display(node->right);
    }

    int score(Node* node, int sum) {
        if (node == nullptr) {
            return 0;
        }
        // Inorder traversal to sum the nodes in ascending order
        score(node->left, sum);
        sum += node->val;
        score(node->right, sum);
        return sum;
    }
};



class Pos
{
public:
    int row, col;
};
// graph using adjacency list
char** make_adjacency_matrix(char map2[][20])
{
    char** adjacency_matrix = new char* [20 * 20];
    for (int i = 0; i < 20 * 20; i++)
    {
        adjacency_matrix[i] = new char[20 * 20];
    }
    int i = 0, j = 0, k = 0, l = 0;
    int rows = 20;
    int cols = 20;
    int count = 0;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            k = 0;
            while (k < rows)
            {
                l = 0;
                while (l < cols)
                {
                    switch (map2[k][l])
                    {
                    case OBSTACLE:
                    case DEATH:
                        adjacency_matrix[count][k * cols + l] = '0';
                        break;
                    case END:
                        adjacency_matrix[count][k * cols + l] = '1';
                        break;
                    default:
                        adjacency_matrix[count][k * cols + l] = '1';
                        break;
                    }
                    l++;
                }
                k++;
            }
            if (k == rows)
            {
                adjacency_matrix[count][i * cols + j] = '0';
            }
            j++;
            count++;
        }
        i++;
    }
    return adjacency_matrix;
}


int Distance_row[] = { -1, 0, 1, 0 };
int Distance_column[] = { 0, 1, 0, -1 };

int Dijkstra_from_start(char map2[][COLS])
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

    cout << "\n\n\t\t";
    cout << "**********DIJKSTRA ALGORITHM**********" << endl;

    // Reset console text color to default
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    int dist[ROWS][COLS];
    int score = 0;
    int indication = 1;
    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            dist[r][c] = -1;
        }
    }

    queue<Pos> q;
    dist[0][0] = 0;
    q.push({ 0, 0 });

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = cur.row + Distance_row[i];
            int nc = cur.col + Distance_column[i];

            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && dist[nr][nc] == -1 && map2[nr][nc] != OBSTACLE && map2[nr][nc] != DEATH) {
                dist[nr][nc] = dist[cur.row][cur.col] + 1;

                switch (map2[nr][nc]) {
                case 'J':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    cout << "You found a jewel!";
                    score += 50;
                    cout << " score: " << score << endl;
                    break;
                case 'P':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    cout << "You found a potion!";
                    score += 70;
                    cout << " score: " << score << endl;
                    break;
                case 'W':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    cout << "You found a weapon!";
                    score += 30;
                    cout << " score: " << score << endl;
                    break;
                case '&':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    cout << "You found a dragon!";
                    score -= 50;
                    cout << " score: " << score << endl;
                    break;
                case '$':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    cout << "You found a goblin!";
                    score -= 70;
                    cout << " score: " << score << endl;
                    break;
                case '@':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    cout << "You found a werewolf!";
                    score -= 30;
                    cout << " score: " << score << endl;
                    break;
                case END:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    cout << "You found a crystal!";
                    score += 100;
                    cout << " score: " << score << endl;
                    cout << "\nYour score is: " << score << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    return dist[nr][nc];
                default:
                    break;
                }

                q.push({ nr, nc });
            }
        }
    }
    return -1;

}

int Dijkstra_from_desired(char map2[][20], int _startingrow, int _startingcol)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

    cout << "\n\n\t\t";
    cout << "**********DIJKSTRA ALGORITHM**********" << endl;

    // Reset console text color to default
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    int dist[ROWS][COLS];
    int score = 0;
    int indication = 1;
    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            dist[r][c] = -1;
        }
    }

    queue<Pos> q;
    dist[_startingrow][_startingcol] = 0;
    q.push({ _startingrow, _startingcol });

    while (!q.empty())
    {
        Pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nr = cur.row + Distance_row[i];
            int nc = cur.col + Distance_column[i];

            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && dist[nr][nc] == -1 && map2[nr][nc] != OBSTACLE && map2[nr][nc] != DEATH)
            {
                dist[nr][nc] = dist[cur.row][cur.col] + 1;
                switch (map2[nr][nc])
                {
                case 'J':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                    cout << "You found a jewel!";
                    score += 50;
                    cout << " score: " << score << endl;
                    break;
                case 'P':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                    cout << "You found a potion!";
                    score += 70;
                    cout << " score: " << score << endl;
                    break;
                case 'W':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                    cout << "You found a weapon!";
                    score += 30;
                    cout << " score: " << score << endl;
                    break;
                case '&':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                    cout << "You found a dragon!";
                    score -= 50;
                    cout << " score: " << score << endl;
                    break;
                case '$':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                    cout << "You found a goblin!";
                    score -= 70;
                    cout << " score: " << score << endl;
                    break;
                case '@':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                    cout << "You found a warewolf!";
                    score -= 30;
                    cout << " score: " << score << endl;
                    break;
                case END:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                    cout << "You found a crystal!";
                    score += 100;
                    cout << " score: " << score << endl;
                    cout << "\nYour score is: " << score << endl;
                    // Change the color back to the default
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    return dist[nr][nc];
                default:
                    break;
                }
                q.push({ nr, nc });
            }
        }
    }
    return -1;

}

//AVL function
AVLTree AVLtreeFunction(char map2[][COLS])
{
    srand(time(nullptr));
    AVLTree tree;
    int AVL_counter = 0;
    int id = 0;

    int Array_Distance[ROWS][COLS];
    int score = 0;
    int indication = 1;
    bool status = false;
    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            Array_Distance[r][c] = -1;
        }
    }
    queue<Pos> input_in_queue_;
    input_in_queue_.push({ 0, 0 });
    int sum_score = 0;
    for (; !input_in_queue_.empty();)
    {
        Pos cur = input_in_queue_.front();
        input_in_queue_.pop();

        for (int i = 0; i < 4; ++i)
        {
            int current_row = cur.row + Distance_row[i];
            int current_column = cur.col + Distance_column[i];

            id = rand() % 201; // modulo 201 to get a number between 0 and 200

            if (current_row >= 0 && current_row < ROWS && current_column >= 0 && current_column < COLS && Array_Distance[current_row][current_column] == -1 && map2[current_row][current_column] != OBSTACLE && map2[current_row][current_column] != DEATH)
            {
                Array_Distance[current_row][current_column] = Array_Distance[cur.row][cur.col] + 1;
                if (map2[current_row][current_column] == 'J')
                {
                    cout << "You found a jewel!";
                    score += 50;
                    if (status == false)
                    {
                        tree.root = tree.insert(tree.root, 100, 50);
                        status = true;
                    }
                    else
                    {
                        tree.root = tree.insert(tree.root, id, 50);
                    }
                    cout << " score: " << score << endl;
                }
                if (map2[current_row][current_column] == 'P')
                {
                    cout << "You found a potion!";
                    score += 70;
                    if (status == false)
                    {
                        tree.root = tree.insert(tree.root, 100, 70);
                        status = true;
                    }
                    else
                    {
                        tree.root = tree.insert(tree.root, id, 70);
                    }
                    cout << " score: " << score << endl;
                }
                if (map2[current_row][current_column] == 'W')
                {
                    cout << "You found a weapon!";
                    score += 30;
                    if (status == false)
                    {
                        tree.root = tree.insert(tree.root, 100, 30);
                        status = true;
                    }
                    else
                    {
                        tree.root = tree.insert(tree.root, id, 30);
                    }
                    cout << " score: " << score << endl;
                }
                if (map2[current_row][current_column] == '&')
                {
                    cout << "You found a dragon!";
                    score -= 50;
                    if (status == false)
                    {
                        tree.root = tree.insert(tree.root, 100, -50);
                        status = true;
                    }
                    else
                    {

                        tree.root = tree.insert(tree.root, id, -50);
                    }
                    cout << " score: " << score << endl;
                }
                if (map2[current_row][current_column] == '$')
                {
                    cout << "You found a goblin!";
                    score -= 70;
                    if (status == false)
                    {
                        tree.root = tree.insert(tree.root, 100, -70);
                        status = true;
                    }
                    else
                    {
                        tree.root = tree.insert(tree.root, id, -70);
                    }
                    cout << " score: " << score << endl;
                }
                if (map2[current_row][current_column] == '@')
                {
                    cout << "You found a warewolf!";
                    score -= 30;
                    if (status == false)
                    {
                        tree.root = tree.insert(tree.root, 100, -30);
                        status = true;
                    }
                    else
                    {
                        tree.root = tree.insert(tree.root, id, -30);
                    }
                    cout << " score: " << score << endl;
                }
                if (map2[current_row][current_column] == END)
                {
                    cout << "You found a crystal!" << endl;
                    score += 100;
                    if (status == false)
                    {
                        tree.root = tree.insert(tree.root, 100, 100);
                        status = true;
                    }
                    else
                    {
                        tree.root = tree.insert(tree.root, id, 100);
                        sum_score = tree.score(tree.root, sum_score);
                    }
                    cout << "\nYour score is: " << score << endl;
                    return tree;
                }
                input_in_queue_.push({ current_row, current_column });
            }
        }
    }
    return tree;
}

int Floyds_Algorithm(char char_map[][20])
{
    int score = 0;
    int adj_matrix[SIZE_int * SIZE_int][SIZE_int * SIZE_int];

    for (int i = 0; i < SIZE_int * SIZE_int; ++i)
    {
        for (int j = 0; j < SIZE_int * SIZE_int; ++j)
        {
            adj_matrix[i][j] = (i == j) ? 0 : INF;
        }
    }

    pair<int, int> start(0, 0), end;

    for (int i = 0; i < SIZE_int; ++i)
    {
        for (int j = 0; j < SIZE_int; ++j)
        {
            if (char_map[i][j] == '*')
            {
                end = make_pair(i, j);
            }
        }
    }

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    int i = 0;
    while (i < SIZE_int) {
        int j = 0;
        while (j < SIZE_int) {
            switch (char_map[i][j]) {
            case '#':
            case '%':
                break;
            default:
                int k = 0;
                while (k < 4) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < SIZE_int && y >= 0 && y < SIZE_int && char_map[x][y] != '#' && char_map[x][y] != '%') {
                        adj_matrix[i * SIZE_int + j][x * SIZE_int + y] = 1;
                    }
                    k++;
                }
                break;
            }
            j++;
        }
        i++;
    }


    int k = 0;
    while (k < SIZE_int * SIZE_int)
    {
        int i = 0;
        while (i < SIZE_int * SIZE_int)
        {
            int j = 0;
            while (j < SIZE_int * SIZE_int)
            {
                switch (adj_matrix[i][k] != INF && adj_matrix[k][j] != INF)
                {
                case true:
                    adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
                    break;
                case false:
                    break;
                }
                j++;
            }
            i++;
        }
        k++;
    }


    int shortest_path_length = adj_matrix[start.first * SIZE_int + start.second][end.first * SIZE_int + end.second];
    return shortest_path_length;
}

int floyd_marshall_location(char map2[][20], int _startingrow, int _startingcolumn)
{
    int shortest_path_length = 0;
    int adj_matrix[SIZE_int * SIZE_int][SIZE_int * SIZE_int];

    for (int i = 0; i < SIZE_int * SIZE_int; ++i)
    {
        for (int j = 0; j < SIZE_int * SIZE_int; ++j)
        {
            adj_matrix[i][j] = (i == j) ? 0 : INF;
        }
    }

    pair<int, int> start(_startingrow, _startingcolumn), end;
    for (int i = 0; i < SIZE_int; ++i)
    {
        for (int j = 0; j < SIZE_int; ++j)
        {
            if (map2[i][j] == '*')
            {
                end = make_pair(i, j);
            }
        }
    }

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    for (int i = 0; i < SIZE_int; ++i)
    {
        for (int j = 0; j < SIZE_int; ++j)
        {
            if (map2[i][j] != '#' && map2[i][j] != '%')
            {
                for (int k = 0; k < 4; ++k)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x >= 0 && x < SIZE_int && y >= 0 && y < SIZE_int && map2[x][y] != '#' && map2[x][y] != '%')
                    {
                        adj_matrix[i * SIZE_int + j][x * SIZE_int + y] = 1;
                    }
                }
            }
        }
    }

    for (int k = 0; k < SIZE_int * SIZE_int; ++k)
    {
        for (int i = 0; i < SIZE_int * SIZE_int; ++i)
        {
            for (int j = 0; j < SIZE_int * SIZE_int; ++j)
            {
                if (adj_matrix[i][k] != INF && adj_matrix[k][j] != INF)
                {
                    adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
                }
            }
        }
    }

    shortest_path_length = adj_matrix[start.first * SIZE_int + start.second][end.first * SIZE_int + end.second];
    return shortest_path_length;
}

//Main function starts 
int main()
{
    AVLTree tree;
    int user_option;
    bool status = true;
    char map2[20][20];
    char** matrix = new char* [ROWS];
    for (int i = 0; i < ROWS; i++)
    {
        matrix[i] = new char[COLS];
    }
    matrix = making_map();
    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 20; col++)
        {
            map2[row][col] = matrix[row][col];
        }
    }

    while (status)
    {
        WelcomeMenu();
        MainMenu();
        cin >> user_option;
        switch (user_option)
        {
        case 1:
        {
            char** adjacency_matrix = make_adjacency_matrix(map2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

            cout << "\n\n\t\t";
            cout << "**********ADJACENCY MATRIX**********" << endl;

            // Reset console text color to default
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            for (int row = 0; row < 20 * 20; row++)
            {
                for (int col = 0; col < 20 * 20; col++)
                {
                    cout << adjacency_matrix[row][col] << " ";
                }
                cout << endl;
            }
        }
        break;
        case 2:
        { // print map2
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << "\n1. Find from start \n2. Find from your desired location: \n";

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                DisplayMap(map2);
                int shortest_path = Dijkstra_from_start(map2);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                cout << "Shortest distance using Dijkstra theorem: " << shortest_path << endl
                    << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                break;
            }
            case 2:
            {
                int row, col;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                cout << "Enter the row and column of your desired location: ";
                cin >> row >> col;
                DisplayMap(map2);
                int shortest_path = Dijkstra_from_desired(map2, row, col);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                cout << "Shortest distance using Dijkstra theorem: " << shortest_path << endl
                    << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                break;
            }
            }
            break;
        }
        case 3:
        {
            // floyds algorithm
            cout << "\n1. Find from start \n2. Find from your desired location: \n";
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                DisplayMap(map2);
                int shortest_path = Floyds_Algorithm(map2);
                cout << "Shortest distance using Floyd's theorem: " << shortest_path << endl
                    << endl;
                break;
            }
            case 2:
            {
                int row, col;
                cout << "Enter the row and column of your desired location: ";
                cin >> row >> col;
                DisplayMap(map2);
                int shortest_path = floyd_marshall_location(map2, row, col);
                cout << "Shortest distance using Floyd's theorem: " << shortest_path << endl
                    << endl;
                break;
            }
            }
            break;
        }
        case 4:
        {
            //cout << "View MST(Kruskal's Algorithm)" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

            cout << "\n\n\t\t";
            cout << "**********View MST(Kruskal's Algorithm)**********" << endl;

            // Reset console text color to default
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            Kruskal_Algoritm(make_adjacency_matrix(map2), 400);
            break;
        }
        case 5:
        {
            //cout << "View MST(Prim's Algorithm)" << endl;
            //cout << "View MST(Kruskal's Algorithm)" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

            cout << "\n\n\t\t";
            cout << "**********View MST(Prim's Algorithm)**********" << endl;

            // Reset console text color to default
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

            Prims_algorithm(make_adjacency_matrix(map2), 400);
            break;
        }
        case 6:
        {
            DisplayMap(map2);
            tree = AVLtreeFunction(map2);
            tree.display(tree.root);
            break;

            break;
        }

        case 7:
        {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "\n\n\n\t\tYou have exited the game. Thank you for playing!" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            status = false;
            break;
        }
        default:
        {
            cout << "Invalid input. Please try again.";
            break;
        }
        }
    }
    return 0;
}