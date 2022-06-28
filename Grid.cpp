#include <gl/glut.h>
#include "Grid.h"
#include "utils.h"

namespace SnakeGame
{
    void Grid::draw()
    {
        // Визначення властивостей матеріалу:
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, getAmbiColor());
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, getDiffColor());
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, getSpecColor());
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, GraphUtils::shininess);
        // Запис поточної матриці в стек
        // (збереження вмісту поточної матриці для подальшого використання):
        glPushMatrix();
        glTranslatef(getXCenter(), getYCenter() + getYSize() / 2, getZCenter());
        // Циліндр повинен бути розташований у вертикальному напрямку:
        glutWireCube(1);
        glPopMatrix();
    }

}