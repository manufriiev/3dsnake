#pragma once
#include "Cube.h"
#include "Shape.h"
#include <vector>

#define UP -1
#define RIGHT -2
#define DOWN 1
#define LEFT 2

namespace SnakeGame
{
    
    class Anakonda
    {
   /* public:
        Snake(float xCenter, float yCenter, float zCenter,
            float xSize, float ySize, float zSize,
            float* diffColor, float* ambiColor, float* specColor)
            : Cube(xCenter, yCenter, zCenter,
                xSize, ySize, zSize,
                specColor, diffColor, ambiColor) { }
        virtual void draw();*/
    public:
        bool lengthflag = 0;
        bool game_over = 0;
        bool foodflag = 0;
        int sDirection = RIGHT;
        bool restartflag = 0;
        bool foodfirst = 1;
        bool randomflag;
        Anakonda();
        std::vector<Shape*> snake;
        std::vector<Shape*> food;
        void generatefood();
        void drawsnake();
        void restart();
        void collisioncheck();
        void foodcheck();
        void length_incr();
        void snakedell();
        int random(int, int);
        int foodx, foody;
        int length;
        int posx[100];
        int posy[100];
        const int columns  = 30;
        const int rows = 30;
    };
}