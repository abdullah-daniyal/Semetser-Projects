#pragma once

using namespace std;
// CLASSES

// OPENGL FUNCTIONS
float xr = 0, yr = 0;
float x2 = 0, y2 = 0;
float canx, cany;
//class that will be inherited
class Counter_inheritance
{
protected:
    int counter;

public:
    Counter_inheritance()
    {
        counter = 0;
    }

    void setcounter()
    {
        counter++;
    }
};

//class for name high score credits settings stuff
class Game_start_menu
{
protected:
    string name_of_player1;
    string name_of_player2;
    int number_of_player;

public:
    Game_start_menu()
    {
        name_of_player1 = "ab";
        name_of_player2 = "cd";
        number_of_player = 0;
    }

    /*Game_start_menu(string name1, string name2, int noplayer)
    {
      name_of_player1 = name1;
      name_of_player2 = name2;
      number_of_player = noplayer;
    }*/

    void setname(string name1)
    {
        name_of_player1 = name1;
    }

    string getname()
    {
        return name_of_player1;
    }

    void setname2(string name2)
    {
        name_of_player2 = name2;
    }

    string getname2()
    {
        return name_of_player2;
    }

    void setnumber_of_player(int noplayer)
    {
        number_of_player = noplayer;
    }

    int getnoplayer()
    {
        return number_of_player;
    }

    void high_scores()
    {
        ofstream MyFile("filename.txt");

        // Write to the file
        MyFile << "\n     *********LIST OF HIGH SCORES*********" << endl
               << endl;
        MyFile << "Sr No.              NAME               SCORE" << endl;
        MyFile << "1                   Abdullah              97" << endl;
        MyFile << "2                   Bilal                 96" << endl;
        MyFile << "3                   Usman                 93" << endl;
        MyFile << "4                   Saim                  90" << endl;
        MyFile << "5                   Eman                  87" << endl;
        MyFile << "6                   Siddique              83" << endl;
        MyFile << "7                   Ahsan                 72" << endl;
        MyFile << "8                   Faisal                70" << endl;
        MyFile << "9                   Taimoor               62" << endl;
        MyFile << "10                  Basiq                 58" << endl;

        // Close the file
        MyFile.close();

        string myText;

        // Read from the text file
        ifstream MyReadFile("filename.txt");

        // Use a while loop together with the getline() function to read the file line by line
        while (getline(MyReadFile, myText))
        {
            // Output the text from the file
            cout << myText;
            cout << endl;
        }

        // Close the file
        MyReadFile.close();
    }

    void credits()
    {
        cout << "\n\nPublished by: Atari, Inc.\nDeveloped by: Atari, Inc.\nReleased: Oct 14, 1977\nAlso For Plex Arcade, Windows, Xbox 360 | Combined View\nGenre: Action\nPerspective: Top-down\nVisual: Fixed / flip-screen\nGameplay: Shooter\nInterface: Direct control\nVehicular: Flight / aviation, Tank\n\n";
    }
};
//class for vehicle
class Vehicle
{

public:
    void DrawTank()
    {
        glColor3ub(106, 13, 173);
        glVertex2f(0.68 + xr, 0.7 + yr);
        glVertex2f(0.72 + xr, 0.7 + yr);
        glVertex2f(0.72 + xr, 0.62 + yr);
        glVertex2f(0.68 + xr, 0.62 + yr);

        // nozzle
        glVertex2f(0.62 + xr, 0.655 + yr);
        glVertex2f(0.7 + xr, 0.655 + yr);
        glVertex2f(0.7 + xr, 0.675 + yr);
        glVertex2f(0.62 + xr, 0.675 + yr);

        // sides
        glVertex2f(0.66 + xr, 0.73 + yr);
        glVertex2f(0.76 + xr, 0.73 + yr);
        glVertex2f(0.76 + xr, 0.7 + yr);
        glVertex2f(0.66 + xr, 0.7 + yr);

        glVertex2f(0.66 + xr, 0.62 + yr);
        glVertex2f(0.76 + xr, 0.62 + yr);
        glVertex2f(0.76 + xr, 0.59 + yr);
        glVertex2f(0.66 + xr, 0.59 + yr);

        // canon
        glVertex2f(0.62 + xr + canx, 0.655 + yr + cany);
        glVertex2f(0.64 + xr + canx, 0.655 + yr + cany);
        glVertex2f(0.64 + xr + canx, 0.675 + yr + cany);
        glVertex2f(0.62 + xr + canx, 0.675 + yr + cany);

        // Player 2

        glColor3ub(246, 190, 0);
        glVertex2f(-0.68 + x2, -0.7 + y2);
        glVertex2f(-0.72 + x2, -0.7 + y2);
        glVertex2f(-0.72 + x2, -0.62 + y2);
        glVertex2f(-0.68 + x2, -0.62 + y2);

        // nozzle
        glVertex2f(-0.62 + x2, -0.655 + y2);
        glVertex2f(-0.7 + x2, -0.655 + y2);
        glVertex2f(-0.7 + x2, -0.675 + y2);
        glVertex2f(-0.62 + x2, -0.675 + y2);

        // sides
        glVertex2f(-0.66 + x2, -0.73 + y2);
        glVertex2f(-0.76 + x2, -0.73 + y2);
        glVertex2f(-0.76 + x2, -0.7 + y2);
        glVertex2f(-0.66 + x2, -0.7 + y2);

        glVertex2f(-0.66 + x2, -0.62 + y2);
        glVertex2f(-0.76 + x2, -0.62 + y2);
        glVertex2f(-0.76 + x2, -0.59 + y2);
        glVertex2f(-0.66 + x2, -0.59 + y2);

        glutPostRedisplay();
    }

    void DrawHelicopter()
    {
        // body
        glColor3ub(106, 13, 173);
        glVertex2f(0.68 + xr, 0.7 + yr);
        glVertex2f(0.77 + xr, 0.7 + yr);
        glVertex2f(0.77 + xr, 0.64 + yr);
        glVertex2f(0.68 + xr, 0.64 + yr);

        // end long
        glVertex2f(0.77 + xr, 0.67 + yr);
        glVertex2f(0.85 + xr, 0.67 + yr);
        glVertex2f(0.85 + xr, 0.65 + yr);
        glVertex2f(0.77 + xr, 0.65 + yr);

        // sidesup
        glVertex2f(0.66 + xr, 0.75 + yr);
        glVertex2f(0.79 + xr, 0.75 + yr);
        glVertex2f(0.79 + xr, 0.73 + yr);
        glVertex2f(0.66 + xr, 0.73 + yr);

        // endp up
        glVertex2f(0.85 + xr, 0.70 + yr);
        glVertex2f(0.87 + xr, 0.70 + yr);
        glVertex2f(0.87 + xr, 0.65 + yr);
        glVertex2f(0.85 + xr, 0.65 + yr);

        // phanka down line
        glVertex2f(0.72 + xr, 0.73 + yr);
        glVertex2f(0.73 + xr, 0.73 + yr);
        glVertex2f(0.73 + xr, 0.7 + yr);
        glVertex2f(0.72 + xr, 0.7 + yr);

        // PLAYER 2
        // body
        glColor3ub(246, 190, 0);
        glVertex2f(-0.77 + x2, -0.7 + y2);
        glVertex2f(-0.68 + x2, -0.7 + y2);
        glVertex2f(-0.68 + x2, -0.64 + y2);
        glVertex2f(-0.77 + x2, -0.64 + y2);

        // end long
        glVertex2f(-0.85 + x2, -0.68 + y2);
        glVertex2f(-0.77 + x2, -0.68 + y2);
        glVertex2f(-0.77 + x2, -0.66 + y2);
        glVertex2f(-0.85 + x2, -0.66 + y2);

        // sidesup
        glVertex2f(-0.79 + x2, -0.59 + y2);
        glVertex2f(-0.66 + x2, -0.59 + y2);
        glVertex2f(-0.66 + x2, -0.61 + y2);
        glVertex2f(-0.79 + x2, -0.61 + y2);

        // endp up
        glVertex2f(-0.85 + x2, -0.68 + y2);
        glVertex2f(-0.87 + x2, -0.68 + y2);
        glVertex2f(-0.87 + x2, -0.63 + y2);
        glVertex2f(-0.85 + x2, -0.63 + y2);

        // phanka down line
        glVertex2f(-0.73 + x2, -0.61 + y2);
        glVertex2f(-0.72 + x2, -0.61 + y2);
        glVertex2f(-0.72 + x2, -0.64 + y2);
        glVertex2f(-0.73 + x2, -0.64 + y2);

        glutPostRedisplay();
    }

    void DrawFighterjet()
    {
        // body
        glColor3ub(106, 13, 173);
        glVertex2f(0.67 + xr, 0.7 + yr);
        glVertex2f(0.84 + xr, 0.7 + yr);
        glVertex2f(0.84 + xr, 0.68 + yr);
        glVertex2f(0.67 + xr, 0.68 + yr);

        // end
        glVertex2f(0.81 + xr, 0.73 + yr);
        glVertex2f(0.82 + xr, 0.73 + yr);
        glVertex2f(0.82 + xr, 0.65 + yr);
        glVertex2f(0.81 + xr, 0.65 + yr);

        // centre
        glVertex2f(0.71 + xr, 0.77 + yr);
        glVertex2f(0.72 + xr, 0.77 + yr);
        glVertex2f(0.72 + xr, 0.6 + yr);
        glVertex2f(0.71 + xr, 0.6 + yr);

        // centre up
        glVertex2f(0.73 + xr, 0.73 + yr);
        glVertex2f(0.74 + xr, 0.73 + yr);
        glVertex2f(0.74 + xr, 0.7 + yr);
        glVertex2f(0.73 + xr, 0.7 + yr);

        // centre down
        glVertex2f(0.73 + xr, 0.68 + yr);
        glVertex2f(0.74 + xr, 0.68 + yr);
        glVertex2f(0.74 + xr, 0.65 + yr);
        glVertex2f(0.73 + xr, 0.65 + yr);

        // PLAYER 2
        // body
        glColor3ub(246, 190, 0);
        glVertex2f(-0.84 + x2, -0.7 + y2);
        glVertex2f(-0.67 + x2, -0.7 + y2);
        glVertex2f(-0.67 + x2, -0.68 + y2);
        glVertex2f(-0.84 + x2, -0.68 + y2);

        // end
        glVertex2f(-0.82 + x2, -0.73 + y2);
        glVertex2f(-0.81 + x2, -0.73 + y2);
        glVertex2f(-0.81 + x2, -0.65 + y2);
        glVertex2f(-0.82 + x2, -0.65 + y2);

        // centre
        glVertex2f(-0.72 + x2, -0.77 + y2);
        glVertex2f(-0.71 + x2, -0.77 + y2);
        glVertex2f(-0.71 + x2, -0.6 + y2);
        glVertex2f(-0.72 + x2, -0.6 + y2);

        // centre up
        glVertex2f(-0.74 + x2, -0.73 + y2);
        glVertex2f(-0.73 + x2, -0.73 + y2);
        glVertex2f(-0.73 + x2, -0.7 + y2);
        glVertex2f(-0.74 + x2, -0.7 + y2);

        // centre down
        glVertex2f(-0.74 + x2, -0.68 + y2);
        glVertex2f(-0.73 + x2, -0.68 + y2);
        glVertex2f(-0.73 + x2, -0.65 + y2);
        glVertex2f(-0.74 + x2, -0.65 + y2);

        glutPostRedisplay();
    }
};

Vehicle obj4;

// class for maps
class Game_Play
{
protected:
    int type_of_vehicle;

public:
    // float xr = 0, yr = 0;
    void set_type_of_vehicle(int a)
    {
        type_of_vehicle = a;
    }

    void display_type_of_vehicle()
    {
        if (type_of_vehicle == 1)
            cout << "You have chosed Tank\n";

        if (type_of_vehicle == 2)
            cout << "You have chosed Helicopter\n";

        if (type_of_vehicle == 3)
            cout << "You have chosed Fighter Plane\n";
    }

    void display_easy_map()
    {

        glClearColor(0.0, 0.0, 256.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
        glColor3ub(173, 216, 233);
        glVertex2f(0.15, 0.06);
        glVertex2f(0.77, 0.06);
        glVertex2f(0.77, -0.06);
        glVertex2f(0.15, -0.06);

        glVertex2f(-0.77, 0.06);
        glVertex2f(-0.15, 0.06);
        glVertex2f(-0.15, -0.06);
        glVertex2f(-0.77, -0.06);

        glVertex2f(0.23, 0.14);
        glVertex2f(0.69, 0.14);
        glVertex2f(0.69, -0.14);
        glVertex2f(0.23, -0.14);

        glVertex2f(-0.69, 0.14);
        glVertex2f(-0.23, 0.14);
        glVertex2f(-0.23, -0.14);
        glVertex2f(-0.69, -0.14);

        glVertex2f(0.30, 0.22);
        glVertex2f(0.60, 0.22);
        glVertex2f(0.60, -0.22);
        glVertex2f(0.30, -0.22);

        glVertex2f(-0.60, 0.22);
        glVertex2f(-0.30, 0.22);
        glVertex2f(-0.30, -0.22);
        glVertex2f(-0.60, -0.22);

		//doing composition
        if (type_of_vehicle == 1)
            obj4.DrawTank();
        if (type_of_vehicle == 2)
            obj4.DrawHelicopter();
        if (type_of_vehicle == 3)
            obj4.DrawFighterjet();

        glutPostRedisplay();
        glEnd();
        glFlush();
    }

    void display_medium_map()
    {
        glClearColor(256.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
        glColor3ub(101, 67, 33);
        glVertex2f(-1.0, 1.0);
        glVertex2f(-0.95, 1.0);
        glVertex2f(-0.95, -1.0);
        glVertex2f(-1.0, -1.0);
        // glEnd();
        // glBegin(GL_QUADS);
        glVertex2f(-1.0, 1.0);
        glVertex2f(1.0, 1.0);
        glVertex2f(1.0, 0.95);
        glVertex2f(-1.0, 0.95);

        glVertex2f(0.95, 1.0);
        glVertex2f(1.0, 1.0);
        glVertex2f(1.0, -1.0);
        glVertex2f(0.95, -1.0);

        glVertex2f(-1.0, -0.95);
        glVertex2f(1.0, -0.95);
        glVertex2f(1.0, -1.0);
        glVertex2f(-1.0, -1.0);

        // ANDAR WALE
        glVertex2f(-0.05, 0.4);
        glVertex2f(0.05, 0.4);
        glVertex2f(0.05, 0.2);
        glVertex2f(-0.05, 0.2);

        glVertex2f(-0.05, -0.2);
        glVertex2f(0.05, -0.2);
        glVertex2f(0.05, -0.4);
        glVertex2f(-0.05, -0.4);

        glVertex2f(0.2, 0.05);
        glVertex2f(0.37, 0.05);
        glVertex2f(0.37, -0.05);
        glVertex2f(0.2, -0.05);

        glVertex2f(-0.37, 0.05);
        glVertex2f(-0.2, 0.05);
        glVertex2f(-0.2, -0.05);
        glVertex2f(-0.37, -0.05);

        glVertex2f(0.6, 0.3);
        glVertex2f(0.7, 0.3);
        glVertex2f(0.7, 0.2);
        glVertex2f(0.6, 0.2);

        glVertex2f(0.6, 0.3);
        glVertex2f(0.65, 0.3);
        glVertex2f(0.65, -0.3);
        glVertex2f(0.6, -0.3);

        glVertex2f(0.6, -0.2);
        glVertex2f(0.7, -0.2);
        glVertex2f(0.7, -0.3);
        glVertex2f(0.6, -0.3);

        glVertex2f(-0.6, 0.3);
        glVertex2f(-0.7, 0.3);
        glVertex2f(-0.7, 0.2);
        glVertex2f(-0.6, 0.2);

        glVertex2f(-0.6, 0.3);
        glVertex2f(-0.65, 0.3);
        glVertex2f(-0.65, -0.3);
        glVertex2f(-0.6, -0.3);

        glVertex2f(-0.7, -0.3);
        glVertex2f(-0.6, -0.3);
        glVertex2f(-0.6, -0.2);
        glVertex2f(-0.7, -0.2);

        if (type_of_vehicle == 1)
            obj4.DrawTank();
        if (type_of_vehicle == 2)
            obj4.DrawHelicopter();
        if (type_of_vehicle == 3)
            obj4.DrawFighterjet();

        glutPostRedisplay();
        glEnd();
        glFlush();
    }

    void display_difficult_map()
    {

        glClearColor(0.0, 256.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
        glColor3ub(101, 67, 33);
        glVertex2f(-1.0, 1.0);
        glVertex2f(-0.95, 1.0);
        glVertex2f(-0.95, -1.0);
        glVertex2f(-1.0, -1.0);

        glVertex2f(-1.0, 1.0);
        glVertex2f(1.0, 1.0);
        glVertex2f(1.0, 0.95);
        glVertex2f(-1.0, 0.95);

        glVertex2f(0.95, 1.0);
        glVertex2f(1.0, 1.0);
        glVertex2f(1.0, -1.0);
        glVertex2f(0.95, -1.0);

        glVertex2f(-1.0, -0.95);
        glVertex2f(1.0, -0.95);
        glVertex2f(1.0, -1.0);
        glVertex2f(-1.0, -1.0);

        glVertex2f(0.6, 0.3);
        glVertex2f(0.7, 0.3);
        glVertex2f(0.7, 0.2);
        glVertex2f(0.6, 0.2);

        glVertex2f(0.6, 0.3);
        glVertex2f(0.65, 0.3);
        glVertex2f(0.65, -0.3);
        glVertex2f(0.6, -0.3);

        glVertex2f(0.6, -0.2);
        glVertex2f(0.7, -0.2);
        glVertex2f(0.7, -0.3);
        glVertex2f(0.6, -0.3);

        glVertex2f(-0.6, 0.3);
        glVertex2f(-0.7, 0.3);
        glVertex2f(-0.7, 0.2);
        glVertex2f(-0.6, 0.2);

        glVertex2f(-0.6, 0.3);
        glVertex2f(-0.65, 0.3);
        glVertex2f(-0.65, -0.3);
        glVertex2f(-0.6, -0.3);

        glVertex2f(-0.7, -0.3);
        glVertex2f(-0.6, -0.3);
        glVertex2f(-0.6, -0.2);
        glVertex2f(-0.7, -0.2);

        // en mai update

        glVertex2f(-0.05, 1.0);
        glVertex2f(0.05, 1.0);
        glVertex2f(0.05, 0.8);
        glVertex2f(-0.05, 0.8);

        glVertex2f(-0.05, -0.8);
        glVertex2f(0.05, -0.8);
        glVertex2f(0.05, -1.0);
        glVertex2f(-0.05, -1.0);

        glVertex2f(0.3, 0.07);
        glVertex2f(0.4, 0.07);
        glVertex2f(0.4, -0.07);
        glVertex2f(0.3, -0.07);

        glVertex2f(-0.4, 0.07);
        glVertex2f(-0.3, 0.07);
        glVertex2f(-0.3, -0.07);
        glVertex2f(-0.4, -0.07);

        // rect

        glVertex2f(0.4, 0.7);
        glVertex2f(0.6, 0.7);
        glVertex2f(0.6, 0.6);
        glVertex2f(0.4, 0.6);

        glVertex2f(0.4, -0.6);
        glVertex2f(0.6, -0.6);
        glVertex2f(0.6, -0.7);
        glVertex2f(0.4, -0.7);

        glVertex2f(-0.6, 0.7);
        glVertex2f(-0.4, 0.7);
        glVertex2f(-0.4, 0.6);
        glVertex2f(-0.6, 0.6);

        glVertex2f(-0.6, -0.7);
        glVertex2f(-0.4, -0.7);
        glVertex2f(-0.4, -0.6);
        glVertex2f(-0.6, -0.6);

        // L wale

        glVertex2f(0.1, 0.5);
        glVertex2f(0.24, 0.5);
        glVertex2f(0.24, 0.42);
        glVertex2f(0.1, 0.42);

        glVertex2f(0.19, 0.5);
        glVertex2f(0.24, 0.5);
        glVertex2f(0.24, 0.35);
        glVertex2f(0.19, 0.35);

        glVertex2f(0.1, -0.42);
        glVertex2f(0.24, -0.42);
        glVertex2f(0.24, -0.5);
        glVertex2f(0.1, -0.5);

        glVertex2f(0.19, -0.5);
        glVertex2f(0.24, -0.5);
        glVertex2f(0.24, -0.35);
        glVertex2f(0.19, -0.35);

        glVertex2f(-0.24, -0.42);
        glVertex2f(-0.1, -0.42);
        glVertex2f(-0.1, -0.5);
        glVertex2f(-0.24, -0.5);

        glVertex2f(-0.24, -0.5);
        glVertex2f(-0.19, -0.5);
        glVertex2f(-0.19, -0.35);
        glVertex2f(-0.24, -0.35);

        glVertex2f(-0.24, 0.5);
        glVertex2f(-0.1, 0.5);
        glVertex2f(-0.1, 0.42);
        glVertex2f(-0.24, 0.42);

        glVertex2f(-0.24, 0.5);
        glVertex2f(-0.19, 0.5);
        glVertex2f(-0.19, 0.35);
        glVertex2f(-0.24, 0.35);

        if (type_of_vehicle == 1)
            obj4.DrawTank();
        if (type_of_vehicle == 2)
            obj4.DrawHelicopter();
        if (type_of_vehicle == 3)
            obj4.DrawFighterjet();

        glutPostRedisplay();
        glEnd();
        glFlush();
    }
//for 1st player
    void special_key(int key, int x, int y)
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            yr = yr + 0.01;
            cout << y << endl;
            glutPostRedisplay();
            break;

        case GLUT_KEY_DOWN:
            yr = yr - 0.01;
            cout << y << endl;
            glutPostRedisplay();
            break;

        case GLUT_KEY_LEFT:
            xr = xr - 0.01;
            cout << x << endl;
            glutPostRedisplay();
            break;

        case GLUT_KEY_RIGHT:
            xr = xr + 0.01;
            cout << x << endl;
            glutPostRedisplay();
            break;
        }
    }
//for 2nd player
    void PrintableKeys_class(unsigned char key, int x, int y)
    {
        if (key == 27 /* Escape key ASCII*/)
        {
            exit(1); // exit the program when escape key is pressed.
        }

        if (key == 'w' || key == 'W') // Key for placing the bomb
        {
            // do something if b is pressed
            y2 = y2 + 0.01;
            cout << "W pressed" << endl;
            sndPlaySound("tank-moving-sound-effect.wav", SND_ASYNC | SND_LOOP);
            glutPostRedisplay();
        }

        if (key == 's' || key == 'S') // Key for placing the bomb
        {
            // do something if b is pressed
            y2 = y2 - 0.01;
            cout << "S pressed" << endl;
            glutPostRedisplay();
        }

        if (key == 'a' || key == 'A') // Key for placing the bomb
        {
            // do something if b is pressed
            x2 = x2 - 0.01;
            cout << "A pressed" << endl;
            glutPostRedisplay();
        }

        if (key == 'd' || key == 'D') // Key for placing the bomb
        {
            // do something if b is pressed
            x2 = x2 + 0.01;
            cout << "D pressed" << endl;
            glutPostRedisplay();
        }

        if (key == 'c' || key == 'C') // Key for placing the bomb
        {
            // do something if b is pressed
            // x2 = x2 - 0.01;
            canx = canx - 0.01;
            cout << "C pressed" << endl;
            glutPostRedisplay();
        }
        glutPostRedisplay();
    }
};
