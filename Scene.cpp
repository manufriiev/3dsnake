#define _CRT_SECURE_NO_WARNINGS
#include <gl/glut.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Scene.h"
#include "utils.h"
#include "Board.h"
#include "Cube.h"
#include "Grid.h"
#include "Anakonda.h"
#include <windows.h>
#include <algorithm> 
#include <fstream>
#define MAX 100

namespace SnakeGame
{
    using namespace GraphUtils;  
    int score = 0;
    float shade = 0;
    int highscore;
    int wincond = 0;
    bool gamestart = 1;
    Anakonda *anakonda = new Anakonda();
    Scene::Scene(float xStep, float zStep)
    {
        this->xStep = xStep;
        this->zStep = zStep;

        // ������ ����� ����� �������. 
        // ������ ��������� ���, ��� ��������� �� ������:
    shapes.push_back(new Board(0.5, 0, 0.5,  xStep*rows, 0.1, xStep*columns, diffDarkViolet, ambiDarkViolet, specDarkViolet));
        // ������ ������ (��� ���������� ����):
    for (int i = 0;i < columns;i++)
    {
        for (int j = 0;j < rows;j++)
        {
            int x = i;
            int y = j;
            if (x == 0 || x == columns - 1 || y == 0 || y == rows - 1)
            {
                shapes.push_back(new Cube(allocX(x), 0, allocZ(y), 1, 1, 1,
                                   diffRedViolet, ambiRedViolet, specRedViolet));
            }
           else 
                shapes.push_back(new Grid(allocX(x), 0, allocZ(y), 1, 1, 1,
                    diffWhite, ambiWhite, specWhite));
            anakonda->generatefood();
        }
        std::ifstream fin("Highscore.txt");
        fin >> highscore;
        if (highscore < 0)
            highscore = 5;
    }
        initialize();
    }


    Scene::~Scene()
    {
        // ��������� �� ������:
        for (int i = 0; i < shapes.size(); i++)
        {
            delete shapes[i];
        }
        for (int i = 0; i < anakonda->food.size(); i++)
        {
            delete  anakonda->food[i];
        }
        for (int i = 0; i < anakonda->snake.size(); i++)
        {
            delete  anakonda->snake[i];
        }
    }
    // ������������� ������� ������ fields � ���������� x
    float Scene::allocX(int i)
    {
        return   i - (rows - 1) * 1 / 2;
    }

    // ������������� ������� ������ fields � ���������� z
    float Scene::allocZ(int i)
    {
        return  i - (columns - 1) * 1 / 2;
    }
    // ����������� ����� (���������� ��������, � ���� � ������ ���������� ���):
    void Scene::initialize()
    {
        distZ = -rows*1.5;
        angleX = 0;
        angleY = 90;
        time = 0;
        anakonda->game_over = false;
        anakonda->restart();
        score = 0;
    }
 // ���������� ��䳿, ���'����� � �������������� ����
    void Scene::on_paint()
    {      
        if (!gamestart)
        anakonda->drawsnake();      
        char text[128]; // ����� �������, 
                        // ���������� ������ ������� �������� �� ����� ���:
        if (anakonda->game_over)
        {
            if (score < highscore)
                sprintf(text, "Game over. Score: %d,  F2 - Restart game   Esc - Exit", score);
            else 
                sprintf(text, "Game over, but you did well!!!!. New higscore: %d!!!!!!!!  F2 - Restart game   Esc - Exit", score);            
        }
        else if (gamestart) {
            sprintf(text, "Welcome! Highscore is: %d.Press F2 to start or Esc to exit", highscore);
        }
        else
        {
            if (score < highscore)
                sprintf(text, "F2 - Restart game, F3-4 - Zoom  Esc - Exit    Score: %d, Highscore: %d", score, highscore);
            else {
                sprintf(text, "F2 - Restart game, F3-4 - Zoom  Esc - Exit    Highscore beat!!!!!!     Score: %d", score);
                highscore = score;
            }
        }
        // ������������ ������� ��������� ����, ��� ���� �������� ��� ����:
        glViewport(0, 0, width, height);

        // ���������� ��������� �������� � ������� �����:
        float lightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // ���� �������� ��������� 
        float lightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // ���� ��������� ��������� 
        float lightSpecular[] = { 2.0f, 2.0f, 2.0f, 2.0f };// ���� ������������ �����������
        float lightPosition[] = { 1.0f, 1.0f, 1.0f, 0.0f };// ������������ ������� �����

        // ������������ ��������� ������� �����:
        glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
       
        // ��������� ��������� ���� ��� ��������:
        if (anakonda->game_over)
            glClearColor(0, 0, 0, 0);
        else if (score != 0) {           
            if (score >= highscore) {
                if (shade >= 1)
                    shade -= 0.2;
                else if (shade <= 0.5)
                    shade += 0.2;
            }
            else {
                float scorefloat = score;
                shade = scorefloat / 50;
            }
            glClearColor(0.1 + shade, 0, 0.2 + shade, 0);
        }
        else
            glClearColor(0.1, 0, 0.2, 0);
        // ������� ������:
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        // ��� ����������� ������, ����� ��������������� ������������ ��������:
        glOrtho(0, 1, 0, 1, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glColor3f(1, 1, 1); // ������ �����
        drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, 0.01, 0.95);
        glPopMatrix();

        // �������� ����� ������ � �������� ��������:
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        // ������ ������� ����� �������� � ����������� ������ ���������, 
        // 60 - ��� �������� � �������� �� �� �,
        // width/height - ��� �������� ������ �� x,
        // 1 � 100 - ������� �� ����������� �� ������ �������� �� ������:
        gluPerspective(60, width / height, 1, 100);

        // �������� ����� ������ � ������� ��������:
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0, 0, distZ);	// ������ � ������� ��������� ��������� �� distZ, 

        glRotatef(angleX, 0.0f, 1.0f, 0.0f);  // ���� ���������� �� �� Oy
        glRotatef(angleY, 1.0f, 0.0f, 0.0f);  // ���� ���������� �� �� Ox
        glEnable(GL_DEPTH_TEST);	// �������� ����� ������� (��� �������� ��������� ������ ����������)

                                    // �������� ����� ��� ��������� ���������:
        glEnable(GL_LIGHTING);

        // ������ ������� ����� � 0 (�� ���� ���� �� 8), ����� ���� ������ � "����":
        glEnable(GL_LIGHT0);
        // ������� �� ������:
        int size = anakonda->snake.size();
        for (int i = 0; i < anakonda->snake.size();i++)
        {
            anakonda->snake[i]->draw();
            /*std::cout << "1";*/
        }
        /*std::cout << std::endl;*/

        for (int i = 0; i < shapes.size(); i++)
        {
            shapes[i]->draw();
        }
        if (!gamestart)
        for (int i = 0; i < anakonda->food.size(); i++)
        {
            anakonda->food[i]->draw();
        }
        
        // �������� ���, �� ��������:
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH_TEST);
        glFlush();
        // �������� ����:
        glutSwapBuffers(); // ����������� ������
        if (!anakonda->game_over) {
            if (anakonda->lengthflag) {
                score++;
                anakonda->length_incr();
            }
            anakonda->snake.clear();
           // for (int j = 0; j < anakonda->snake.size(); j++)
           // {
           //     auto iter = anakonda->snake.cbegin(); // ��������� �� ������ �������
           //     anakonda->snake.erase(iter + j);
           //     //std::cout << "0";
           // }
           ///* std::cout << std::endl;*/
        }
        else {
            int highscoretemp;
            std::ifstream fin("Highscore.txt");
            fin >> highscoretemp;
            std::ofstream fout("Highscore.txt"); 
            if (score >= highscoretemp)
            fout << score;
            fout.close();
        }
        }
    

    // ���������� ��䳿, ���'����� � ����� ������ ���� 
    void Scene::on_size(int width, int height)
    {
        this->width = width;
        if (height == 0)
            height = 1;
        this->height = height;
    }

    // ���������� ����, ���'������ � ����������� ������ ����
    void Scene::on_mouse(int button, int state, int x, int y)
    {
         //�������� ������ ���������� ����:
        mouseX = x;
        mouseY = y;
        if ((state == GLUT_UP)) // ������ ������
        {
            // �������� ��������� ���:
            this->button = -1;  // ���� ������ �� ���������
            return;
        }
        this->button = button;  // �������� ���������� ��� ������
        if (finish)
        {
            return;
        }
        
    }

    // ���������� ����, ���'������ � ������������ ���� � ���������� �������
    void Scene::on_motion(int x, int y)
    {
        switch (button)
        {
        case 2: // ����� ������ - ��������� �����
            angleX += x - mouseX;
            angleY += y - mouseY;
            mouseX = x;
            mouseY = y;
            break;
        }
    }

    // ���������� ����, ���'������ � ����������� �������������� ����� � ������ 
    void Scene::on_special(int key, int x, int y)
    {
        switch (key) {
            case GLUT_KEY_UP:
                if (anakonda->sDirection != UP)
                    anakonda->sDirection = DOWN;
                break;
            case GLUT_KEY_DOWN:
                if (anakonda->sDirection != DOWN)
                    anakonda->sDirection = UP;
                break;
            case GLUT_KEY_RIGHT:
                if (anakonda->sDirection != LEFT)
                    anakonda->sDirection = RIGHT;
                break;
            case GLUT_KEY_LEFT:
                if (anakonda->sDirection != RIGHT)
                    anakonda->sDirection = LEFT;
                break;
        case GLUT_KEY_F3:   // ����������
            if (distZ > -1.7)
            {
                break;
            }
            distZ += 0.7;
            break;
        case GLUT_KEY_F4: // ���������
            distZ -= 0.7;
            break;
        case GLUT_KEY_F2:   // ���� ���
            initialize();
            gamestart = 0;
            break;
        }
    }

    int tick = 0; // ��������, �������� ����� ��������� ���� 25 ��

                  // ���������� ��䳿 �� �������
    void Scene::on_timer(int value)
    {      
        on_paint();         
    }
    float allocX(int i)
    {
        return   i - (rows - 1) * 1 / 2;
    }

    // ������������� ������� ������ fields � ���������� z
    float allocZ(int i)
    {
        return   i - (columns - 1) * 1 / 2;
    }
}
