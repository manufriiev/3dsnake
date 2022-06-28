#include <gl/glut.h>
#include "Cube.h"
#include "utils.h"

namespace SnakeGame
{
    void Cube::draw()
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
        glutSolidCube(1);
        glPopMatrix();
    }

}