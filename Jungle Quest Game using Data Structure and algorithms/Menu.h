#include<iostream>
#include<windows.h>
using namespace std;

void WelcomeMenu()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6); // set color to yellow
    cout << "\t\t _____________________________________________________________________________" << endl;
    cout << "\t\t|                                                                             |" << endl;
    cout << "\t\t|                                                                             |" << endl;
    cout << "\t\t|                         WELCOME TO JUNGLE QUEST GAME                        |" << endl;
    cout << "\t\t|                                                                             |" << endl;
    cout << "\t\t|_____________________________________________________________________________|" << endl;
    SetConsoleTextAttribute(hConsole, 7); // set color back to default
}

void MainMenu()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 13); // set color to yellow
    cout << "\t\t _____________________________________________________________________________" << endl;
    cout << "\t\t|                                                                             |" << endl;
    cout << "\t\t|                                    MainMenu                                 |" << endl;
    cout << "\t\t|_____________________________________________________________________________|" << endl;
    cout << "\t\t|                                                                             |" << endl;
    cout << "\t\t|                            1 - Adjancecy Matrix                             |" << endl;
    cout << "\t\t|                            2 - Play(Dijkstra's algorithm)                   |" << endl;
    cout << "\t\t|                            3 - Play(Floyd's Algorithm)                      |" << endl;
    cout << "\t\t|                            4 - View MST(Kruskal's Algorithm)                |" << endl;
    cout << "\t\t|                            5 - View MST(Prim's Algorithm)                   |" << endl;
    cout << "\t\t|                            6 - View AVL TREE                                |" << endl;
    cout << "\t\t|                            7 - Exit                                         |" << endl;
    cout << "\t\t|_____________________________________________________________________________|" << endl;
    SetConsoleTextAttribute(hConsole, 7); // set color back to default
    cout << "\t\t Enter your choice: ";
}