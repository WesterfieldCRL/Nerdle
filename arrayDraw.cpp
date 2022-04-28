//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/20/2022
//Date Last Modified: 4/20/2022

#include "arrayDraw.h"

void drawChar(char character, const Point& p, SDL_Plotter& plotter, const Color& color, int size)
{
    ifstream file;
    switch (character)
    {
        case '0':
            file.open("zero.dat");
            break;
        case '1':
            file.open("one.dat");
            break;
        case '2':
            file.open("two.dat");
            break;
        case '3':
            file.open("three.dat");
            break;
        case '4':
            file.open("four.dat");
            break;
        case '5':
            file.open("five.dat");
            break;
        case '6':
            file.open("six.dat");
            break;
        case '7':
            file.open("seven.dat");
            break;
        case '8':
            file.open("eight.dat");
            break;
        case '9':
            file.open("nine.dat");
            break;
        case '+':
            file.open("plus.dat");
            break;
        case '-':
            file.open("minus.dat");
            break;
        case '/':
            file.open("divide.dat");
            break;
        case '*':
            file.open("multiply.dat");
            break;
        default:
            cout << "character not found" << endl;
            break;
    }
    assert(file);
    drawArray(p, plotter, color, file, size);
}

void drawArray(const Point& point, SDL_Plotter& plotter, const Color& color, ifstream& file, int size)
{
    int row;
    int col;
    int num;
    int factor = 0;
    file >> row >> col;
    for (int y = 0; y < row; y++)
    {
        for (int x = 0; x < col; x++)
        {
            file >> num;
            if (num == 1)
            {
                for (int i = -size; i <= size; i++)
                {
                    for (int j = -size; j <= size; j++)
                    {
                        plotter.plotPixel(x + point.x+i+factor, y + point.y+j+factor, color.R, color.G, color.B);
                    }
                }
                //factor+=size;
            }
        }
    }
}