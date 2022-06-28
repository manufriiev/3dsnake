#pragma once
#include "Shape.h"
#include "Disk.h"
#include <vector>

namespace SnakeGame
{
    const int rows = 30, columns = 30;
    float allocX(int i);
    float allocZ(int i);
                            // �������� ���� ���, ���� ����������� �������� �����,
                            // ��������� ������� ���, ������������ ��������,
                            // � ����� ������ ������� ���� GLUT
    class Scene
    {
        std::vector<Shape*> shapes;
        /*std::vector<Shape*> snake;
        std::vector<Shape*> food;*/// "�������" ����� ��������� �� �������� ���
        int button;           // ������ ���� (-1 - �� ���������, 0 - ���, 2 - �����)
        float angleX, angleY; // �������� ��� �������� ����� 
        float mouseX, mouseY; // ������ ����������
        float width, height;  // ������ ����
        float distZ;          // ������� �� �� Z �� �����
        bool finish;          // ������ ����, �� ��� ���������
        float xStep, zStep;   // ������� �� �������� ���������
        int time;             // �������� ��� � �������x

    public:
        bool lengthflag;
        Scene(float xStep, float zStep);
        ~Scene();
        void on_paint();
        void on_size(int width, int height);
        void on_mouse(int button, int state, int x, int y);
        void on_motion(int x, int y);
        void on_special(int key, int x, int y);
        void on_timer(int value);
        /*void generatefood();
        void drawsnake();
        void restart();
        void collisioncheck();
        void foodcheck();
        void length_incr();*/
    private:
        void initialize();
        float allocX(int i);
        float allocZ(int i);

    };

}
