// Shape.h
#pragma once
#include "RenderState.h"
#include "Global.h"
#include "fstream"


bool operator == (const COORD& p1, const COORD& p2);

bool isInside(const COORD &pos);
bool isOutSideRight(const COORD& pos);
bool isOutSideLeft(const COORD& pos);
class Shape
{
private:
    unsigned int** m_shape;
    int m_width;
    int m_height;
    //std::string m_fileName;
public:
    Shape() = default;
    Shape(std::string fileName);
    Shape(const Shape& s);

    Shape& operator=(const Shape& s);
    ~Shape();
    void render(int offset_x, int offset_y);
    void set_file_name(std::string file_name) {
        //m_fileName = file_name;
    }

    void getSize(int& width, int& height);
};
