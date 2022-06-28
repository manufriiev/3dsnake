#pragma once
#include "Shape.h"
#include "Disk.h"
#include <vector>

namespace SnakeGame
{
    const int rows = 30, columns = 30;
    float allocX(int i);
    float allocZ(int i);
                            // Основний клас гри, який представляє геометрію сцени,
                            // контролює правила гри, розташування елементів,
                            // а також реалізує обробку подій GLUT
    class Scene
    {
        std::vector<Shape*> shapes;
        /*std::vector<Shape*> snake;
        std::vector<Shape*> food;*/// "гнучкий" масив указівників на елементи гри
        int button;           // кнопка миші (-1 - не натиснута, 0 - ліва, 2 - права)
        float angleX, angleY; // поточний кут повороту сцени 
        float mouseX, mouseY; // поточні координати
        float width, height;  // Розміри вікна
        float distZ;          // відстань по осі Z до сцени
        bool finish;          // ознака того, що гру завершено
        float xStep, zStep;   // відстань між окремими стрижнями
        int time;             // поточний час у секуднаx

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
