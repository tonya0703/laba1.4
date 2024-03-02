#pragma once
#include <string>
#include <iostream>

class Matrix
{
private:
    int rows;
    int cols;
    int** data;

public:
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void setRows(int r) { rows = r; }
    void setCols(int c) { cols = c; }

    void Init(int r, int c);
    void Read();
    void Display() const;
    std::string toString() const;

    void DisplaySubmatrix(int startRow, int startCol, int subRows, int subCols) const;
    void Resize(int newRows, int newCols);
};

