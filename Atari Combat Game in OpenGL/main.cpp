#include <iostream>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <GL/glut.h>
//#include <mmsystem.h>
#include "main.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
// CLASSES

// OPENGL FUNCTIONS

Game_Play obj2;
int sprite;
int level;

void cdisplay(void)
{

    obj2.display_easy_map();
}

void sdisplay(void)
{

    obj2.display_medium_map();
}

void edisplay(void)
{

    obj2.display_difficult_map();
}

void specialkey(int key, int x, int y)
{

    obj2.special_key(key, x, y);
}

void PrintableKeys(unsigned char key, int x, int y)
{
    obj2.PrintableKeys_class(key, x, y);
}

Game_start_menu obj;

int main(int argc, char **argv)
{
    string welcome[28] = {"W", "E", "L", "C", "O", "M", "E", " ", "T", "O", " ", "A", "T", "A", "R", "I", " ", "C", "O", "M", "B", "A", "T", " ", "G", "A", "M", "E"};
    int userchoice;
    cout << "**************";
    for (int i = 0; i < 28; i++)
    {
        cout << welcome[i];
        Sleep(250);
    }
    cout << "**************\n";
    while (userchoice != -99)
    {
        cout << "\nSelect what you want to do first: ";
        cout << "\n1. See the high scores\n";
        cout << "2. Check setting\n";
        cout << "3. Credits\n";
        cout << "4. Start Game\n";
        cout << "5. Exit\n";
        cout << "\nEnter your option: ";
        cin >> userchoice;
        while (userchoice <= 0 || userchoice >= 6)
        {
            cout << "Enter valid option: ";
            cin >> userchoice;
        }
        switch (userchoice)
        {
        case 1:
        {
            obj.high_scores();
            break;
        }

        case 2:
        {
            cout << "\n. The controls if the user chooses one player game mode:\n";
            cout << "W-To move up\n";
            cout << "A-To move left\n";
            cout << "S-To move down\n";
            cout << "D-To move right\n\n";
            cout << "\n. The controls if the user chooses two player game mode:\n";
            cout << "Arrow up-To move up\n";
            cout << "Arrow left-To move left\n";
            cout << "Arrow down-To move down\n";
            cout << "Arrow right-To move right\n";
            break;
        }

        case 3:
        {
            obj.credits();

            break;
        }
        case 4:
        {
            glutInit(&argc, argv);
            // int n;
            // cout<<"Which screen do you want"<<endl;
            // cin>>n;

            cout << "\nEnter the player mode\n";
            cout << "1. One Player\n2. Two Player\n";
            int n;
            cin >> n;
            obj.setnumber_of_player(n);

            if (n == 1)
            {
                cout << "\nAs you have chosen " << obj.getnoplayer() << " player game\n\n";
                string name1, name2;
                cout << "Enter the name of the first player: ";
                cin >> name1;
                obj.setname(name1);
                cout << "\nName of player 1: " << obj.getname() << endl;
                cout << "What do you want to choose \n1. EASY \n2. MEDIUM \n3. HARD \n4. From EASY to HARD " << endl;
                // int level;
                cin >> level;

                cout << "Which sprite do you want: \n1. Tank \n2. Helicopter \n3. Fighter plane\n";
                // int sprite;
                cin >> sprite;
                obj2.set_type_of_vehicle(sprite);
                cout << "You chose ";
                obj2.display_type_of_vehicle();
                cout << endl;
                if (level == 1)
                {

                    cout << "\nLoading";
                    for (int i = 0; i <= 3; i++)
                    {
                        cout << ".";
                        Sleep(300);
                    }

                    glutInitWindowSize(800, 600);
                    glutCreateWindow("Atari Combat 1977");
                    glutDisplayFunc(cdisplay);
                    glutSpecialFunc(specialkey);
                }

                if (level == 2)
                {

                    cout << "\nLoading";
                    for (int i = 0; i <= 3; i++)
                    {
                        cout << ".";
                        Sleep(300);
                    }

                    glutInitWindowSize(800, 600);
                    glutCreateWindow("Atari Combat 1977");
                    glutDisplayFunc(sdisplay);
                    glutSpecialFunc(specialkey);
                }

                if (level == 3)
                {

                    cout << "\nLoading";
                    for (int i = 0; i <= 3; i++)
                    {
                        cout << ".";
                        Sleep(300);
                    }

                    glutInitWindowSize(800, 600);
                    glutCreateWindow("Atari Combat 1977");
                    glutDisplayFunc(edisplay);
                    glutSpecialFunc(specialkey);
                }
            }
            if (n == 2)
            {
                cout << "\nAs you have chosen " << obj.getnoplayer() << " player game\n\n";
                string name1, name2;
                cout << "Enter the name of the first player: ";
                cin >> name1;
                obj.setname(name1);
                cout << "Enter the name of the second player: ";
                cin >> name2;
                obj.setname2(name2);
                cout << "\nName of player 1: " << obj.getname() << endl;
                cout << "\nName of player 2: " << obj.getname2() << endl;

                cout << "What do you want to choose \n1. EASY \n2. MEDIUM \n3. HARD \n4. From EASY to HARD " << endl;
                // int level;
                cin >> level;
                cout << "Which sprite do you want: \n1. Tank \n2. Helicopter \n3. Fighter plane\n";
                // int sprite;
                cin >> sprite;
                obj2.set_type_of_vehicle(sprite);
                cout << "\nYou chose ";
                obj2.display_type_of_vehicle();
                cout << endl;
                if (level == 1)
                {

                    cout << "\nLoading";
                    for (int i = 0; i <= 3; i++)
                    {
                        cout << ".";
                        Sleep(300);
                    }

                    glutInitWindowSize(800, 600);
                    glutCreateWindow("Atari Combat 1977");
                    glutDisplayFunc(cdisplay);
                    glutSpecialFunc(specialkey);
                    glutKeyboardFunc(PrintableKeys);
                    // PlaySound(TEXT("tank-moving-sound-effect.wav"),NULL,SND_SYNC);
                }

                if (level == 2)
                {

                    cout << "\nLoading";
                    for (int i = 0; i <= 3; i++)
                    {
                        cout << ".";
                        Sleep(300);
                    }

                    glutInitWindowSize(800, 600);
                    glutCreateWindow("Atari Combat 1977");
                    glutDisplayFunc(sdisplay);
                    glutSpecialFunc(specialkey);
                    glutKeyboardFunc(PrintableKeys);
                }

                if (level == 3)
                {

                    cout << "\nLoading";
                    for (int i = 0; i <= 3; i++)
                    {
                        cout << ".";
                        Sleep(300);
                    }

                    glutInitWindowSize(800, 600);
                    glutCreateWindow("Atari Combat 1977");
                    glutDisplayFunc(edisplay);
                    glutSpecialFunc(specialkey);
                    glutKeyboardFunc(PrintableKeys);
                }
            }
            glutMainLoop();

            break;
        }

        case 5:
        {
            cout << "\n\n****THANKYOU!****";
            return 0;
        }
        }
    }
    return 0;
}

// header

