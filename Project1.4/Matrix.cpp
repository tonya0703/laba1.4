#include "Matrix.h"
void Matrix::Init(int r, int c) {
    setRows(r);
    setCols(c);
    data = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
    }
}

void Matrix::Read() {
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            std::cin >> data[i][j];
        }
    }
}

void Matrix::Display() const {
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::string Matrix::toString() const {
    std::string result;
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            result += std::to_string(data[i][j]) + " ";
        }
        result += "\n";
    }
    return result;
}

void Matrix::DisplaySubmatrix(int startRow, int startCol, int subRows, int subCols) const {
    if (startRow + subRows > getRows() || startCol + subCols > getCols()) {
        std::cout << "Submatrix dimensions exceed matrix dimensions!" << std::endl;
        return;
    }

    for (int i = startRow; i < startRow + subRows; ++i) {
        for (int j = startCol; j < startCol + subCols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::Resize(int newRows, int newCols) {
    // Створення нового масиву даних
    int** newData = new int* [newRows];
    for (int i = 0; i < newRows; ++i) {
        newData[i] = new int[newCols];
    }

    // Копіювання даних з попереднього масиву до нового з урахуванням мінімальних розмірів
    for (int i = 0; i < std::min(rows, newRows); ++i) {
        for (int j = 0; j < std::min(cols, newCols); ++j) {
            newData[i][j] = data[i][j];
        }
    }

    // Звільнення пам'яті попереднього масиву
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;

    // Оновлення розмірів та масиву даних
    setRows(newRows);
    setCols(newCols);
    data = newData;
}