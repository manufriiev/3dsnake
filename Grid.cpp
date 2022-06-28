#include <gl/glut.h>
#include "Grid.h"
#include "utils.h"

namespace SnakeGame
{
    void Grid::draw()
    {
        // ���������� ������������ ��������:
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, getAmbiColor());
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, getDiffColor());
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, getSpecColor());
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, GraphUtils::shininess);
        // ����� ������� ������� � ����
        // (���������� ����� ������� ������� ��� ���������� ������������):
        glPushMatrix();
        glTranslatef(getXCenter(), getYCenter() + getYSize() / 2, getZCenter());
        // ������ ������� ���� ������������ � ������������� ��������:
        glutWireCube(1);
        glPopMatrix();
    }

}