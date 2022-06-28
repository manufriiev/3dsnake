//#include <GL/glut.h>
//#include "Food.h"
//#include <ctime>
//#include <windows.h>
//namespace SnakeGame {
//    int random(int _min, int _max)
//    {
//        if (!seedflag)
//        {
//            srand(time(NULL));
//            seedflag = true;
//        }
//        else
//            seedflag = false;
//        return _min + rand() % (_max - _min);
//    }
//void Food::draw()
//{
//    if (!food)
//    {
//        foodx = random(2, columns - 2);
//        foody = random(2, rows - 2);
//
//        food = true;
//    }
//    glBegin(GL_QUADS);
//    glVertex2d(foodx, foody); glVertex2d(foodx + 1, foody); glVertex2d(foodx + 1, foody + 1); glVertex2d(foodx, foody + 1);
//    glEnd();}
//}