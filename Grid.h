#pragma once
#include "shape.h"

namespace SnakeGame
{
    // ����, ���� ������� �� ��������� �������
    class Grid : public Shape
    {
    public:
        Grid(float xCenter, float yCenter, float zCenter,
            float xSize, float ySize, float zSize,
            float* diffColor, float* ambiColor, float* specColor)
            : Shape(xCenter, yCenter, zCenter,
                xSize, ySize, zSize,
                specColor, diffColor, ambiColor) { }
        virtual void draw();
    };
}