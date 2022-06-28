#include "Anakonda.h"
#include "utils.h"
#include "Shape.h"
#include "Scene.h"
#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace GraphUtils;
namespace SnakeGame
{
    using namespace GraphUtils;
    Anakonda::Anakonda() {
        foodx = 20;
        foody = 20;
        for (int j = 0; j < snake.size(); j++)
        {
            auto iter = snake.cbegin(); // указатель на первый элемент
            snake.erase(iter + j);
        }
        length = 7;
        for (int i = 0; i < length; i++) {
            posx[i] = 10 - i;
            posy[i] = 10;
        }
        sDirection = RIGHT;
        foodflag = false;
        restartflag = false;
        bool randomflag = 1;
    }
    int Anakonda::random(int _min, int _max)
    {
        if (!randomflag) {
        srand(time(NULL));
        randomflag = 1;
    }
    else randomflag = 0;
        return _min + rand() % (_max - _min);
    }
    void Anakonda::generatefood() {
        for (int j = 0; j < food.size(); j++)
        {
            auto iter = food.cbegin(); // указатель на первый элемент
            food.erase(iter + j);
        }
        foodx = random(2, columns - 2);
        foody = random(2, rows - 2);
        food.push_back(new Cube(allocX(foodx), 0, allocZ(foody), 1, 1, 1,
            diffYellow, ambiYellow, specYellow));
        foodflag = 1;
    }
    void Anakonda::restart() {
        for (int j = 0; j < snake.size(); j++)
        {
            auto iter = snake.cbegin(); // указатель на первый элемент
            snake.erase(iter + j);
        }
        length = 7;
        for (int i = 0; i < length; i++) {
            posx[i] = 20 - i;
            posy[i] = 10;
        }
        /*food.pop_back();*/
        sDirection = RIGHT;
        foodflag = false;
        restartflag = false;
    }
    void Anakonda::collisioncheck() {
        if (allocX(posx[0]) <= allocX(0) || allocX(posx[0]) >= allocX(columns - 1)
            || allocZ(posy[0]) <= allocZ(0) || allocZ(posy[0]) >= allocZ(rows - 1))
            game_over = true;
        for (int i = 1; i < length; i++)
            if (posx[i] == posx[0] && posy[i] == posy[0])
                game_over = 1;
    }
    void Anakonda::foodcheck() {
        if (allocX(posx[0]) == allocX(foodx) && allocZ(posy[0]) == allocZ(foody)) {
            /*food.pop_back();*/
            foodfirst = 0;
            foodflag = false;
            lengthflag = 1;
        }
        if (!foodflag)
        {
            Anakonda::generatefood();
        }      
        
    }
    void Anakonda::drawsnake() {
        if (!game_over) {                   
            for (int i = 1;i < length;i++)
            {
                    snake.push_back(new Cube(allocX(posx[i]), 0, allocZ(posy[i]), 0.995, 0.995, 0.995,
                        diffLightBlue, ambiLightBlue, specLightBlue));                   
            }
            snake.push_back(new Cube(allocX(posx[0]), 0, allocZ(posy[0]), 1.005, 1.005, 1.005,
                diffGoodGreen, ambiGoodGreen, specGoodGreen));
            switch (sDirection)
            {
            case UP:
                posy[0]++;
                break;
            case DOWN:
                posy[0]--;
                break;
            case RIGHT:
                posx[0]++;
                break;
            case LEFT:
                posx[0]--;
                break;
            }
        }
        if (restartflag) {
            restart();
        }
        foodcheck();
        collisioncheck();
        for (int i = length;i > 0;i--)
        {
            posx[i] = posx[i - 1];
            posy[i] = posy[i - 1];
        }
    }
    void Anakonda::length_incr() {
        if (lengthflag) {
            length++;
            lengthflag = 0;
        }
    }
    void Anakonda::snakedell() {
        
    }
}