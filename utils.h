#pragma once
namespace GraphUtils
{
    // Попередній опис масивів, які визначають кольори:
    extern float diffWhite[];
    extern float ambiWhite[];
    extern float specWhite[];

    extern float diffBlue[];
    extern float ambiBlue[];
    extern float specBlue[];

    extern float diffGray[];
    extern float ambiGray[];
    extern float specGray[];

    extern float diffBlack[];
    extern float ambiBlack[];
    extern float specBlack[];

    extern float diffRed[];
    extern float ambiRed[];
    extern float specRed[];

    extern float diffYellow[];
    extern float ambiYellow[];
    extern float specYellow[];

    extern float diffGreen[];
    extern float ambiGreen[];
    extern float specGreen[];

    extern float diffOrange[];
    extern float ambiOrange[];
    extern float specOrange[];

    extern float diffLightBlue[];
    extern float ambiLightBlue[];
    extern float specLightBlue[];

    extern float diffGoodGreen[];
    extern float ambiGoodGreen[];
    extern float specGoodGreen[];

    extern float diffViolet[];
    extern float ambiViolet[];
    extern float specViolet[];

    extern float diffDarkViolet[];
    extern float ambiDarkViolet[];
    extern float specDarkViolet[];
    
    extern float diffKindaDarkViolet[];
    extern float ambiKindaDarkViolet[];
    extern float specKindaDarkViolet[];

    extern float diffRedViolet[];
    extern float ambiRedViolet[];
    extern float specRedViolet[];

    const float shininess = 64; // блиск

    // Випадкове "тасування" одновимірного масиву цілих чисел
    void shuffle(int* a, int size);

    // Малювання паралелепіпеда
    void parallelepiped(float length, float width, float height);

    // Відображення рядка тексту вказаним шрифтом у вказаній позиції
    void drawString(void* font, const char* text, float x, float y);
}
