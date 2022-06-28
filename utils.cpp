#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <gl/glut.h>
#include "utils.h"

namespace GraphUtils
{
    // Визначення кольорів:
    float diffWhite[] = { 0.5f, 0.3f, 0.5f };
    float ambiWhite[] = { 0.4f, 0.2f, 0.4f };
    float specWhite[] = { 0.3f, 0.1f, 0.3f };

    float diffBlue[] = { 0.0f, 0.0f, 0.6f };
    float ambiBlue[] = { 0.1f, 0.1f, 0.2f };
    float specBlue[] = { 0.2f, 0.2f, 0.8f };

    float diffBlack[] = { -1, -1, -1 };
    float ambiBlack[] = { -2, -2, -2 };
    float specBlack[] = { -3, -3, -3 };

    float diffGray[] = { 0.6f, 0.6f, 0.6f };
    float ambiGray[] = { 0.2f, 0.2f, 0.2f };
    float specGray[] = { 0.8f, 0.8f, 0.8f };

    float diffRed[] = { 0.6f, 0.0f, 0.0f };
    float ambiRed[] = { 0.2f, 0.1f, 0.1f };
    float specRed[] = { 0.8f, 0.2f, 0.2f };

    float diffYellow[] = { 4, 4, 0 };
    float ambiYellow[] = { 2, 2, 0 };
    float specYellow[] = { 1, 1, 0 };

    float diffGreen[] = { 0, 0.5f, 0 };
    float ambiGreen[] = { 0.1f, 0.2f, 0.1f };
    float specGreen[] = { 0.2f, 0.7f, 0.2f };

    float diffOrange[] = { 0.9f, 0.2f, 0 };
    float ambiOrange[] = { 0.2f, 0.2f, 0.2f };
    float specOrange[] = { 0.8f, 0.8f, 0.8f };

    float diffLightBlue[] = {0, 4, 4 };
    float ambiLightBlue[] = { 0, 1, 1};
    float specLightBlue[] = { 0, 2, 1 };

    float diffGoodGreen[] = { 0, 5, 0.5 };
    float ambiGoodGreen[] = { 0, 5, 0.5 };
    float specGoodGreen[] = { 0, 5, 0.5 };

    float diffViolet[] = { 0.5f, 0, 0.8f };
    float ambiViolet[] = { 0.2f, 0, 0.2f };
    float specViolet[] = { 0.8f, 0, 0.8f };

    float diffDarkViolet[] = { 0.5f, 0, 0.7f };
    float ambiDarkViolet[] = { 0.4f, 0, 0.6f };
    float specDarkViolet[] = { 0.25f, 0, 0.5f };

    float diffKindaDarkViolet[] = { 2, 0, 2.6f };
    float ambiKindaDarkViolet[] = { 1.6f, 0, 2.4f };
    float specKindaDarkViolet[] = { 2, 0, 2 };

    float diffRedViolet[] = { 2, 0, 1.0f };
    float ambiRedViolet[] = { 1, 0.5f, 0.5f };
    float specRedViolet[] = { 1, 0.2f, 0.4f };

    
    // Малювання паралелепіпеда
    void parallelepiped(float length, float width, float height)
    {
        glBegin(GL_QUAD_STRIP);
        //грань 1 || YZ, x<0
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(-length / 2, -width / 2, -height / 2);
        glVertex3f(-length / 2, -width / 2, height / 2);
        glVertex3f(-length / 2, width / 2, -height / 2);
        glVertex3f(-length / 2, width / 2, height / 2);

        //грань 2 || ZX, y>0
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(length / 2, width / 2, -height / 2);
        glVertex3f(length / 2, width / 2, height / 2);

        //грань 3 || YZ, x>0
        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(length / 2, -width / 2, -height / 2);
        glVertex3f(length / 2, -width / 2, height / 2);

        //грань 4 || ZX y<0
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(-length / 2, -width / 2, -height / 2);
        glVertex3f(-length / 2, -width / 2, height / 2);
        glEnd();

        glBegin(GL_QUADS);
        //грань 5 || YX, z>0
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-length / 2, -width / 2, height / 2);
        glVertex3f(-length / 2, width / 2, height / 2);
        glVertex3f(length / 2, width / 2, height / 2);
        glVertex3f(length / 2, -width / 2, height / 2);

        //грань 6  || YX, z<0
        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(-length / 2, -width / 2, -height / 2);
        glVertex3f(-length / 2, width / 2, -height / 2);
        glVertex3f(length / 2, width / 2, -height / 2);
        glVertex3f(length / 2, -width / 2, -height / 2);
        glEnd();
    }

    // Відображення рядка тексту вказаним шрифтом у вказаній позиції
    void drawString(void* font, const char* text, float x, float y)
    {
        if (!text) // нульовий указівник
        {
            return;
        }
        // Встановлення позиції тексту:
        glRasterPos2f(x, y);
        while (*text)
        {
            // Рядок виводиться посимвольно:
            glutBitmapCharacter(font, *text);
            text++;
        }
    }
}