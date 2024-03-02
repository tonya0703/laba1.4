#include "Matrix.h"

using namespace std;


int main() {
    Matrix matrix;
    int choice;

    std::cout << "Enter the number of rows and columns for the matrix: ";
    int rows, cols;
    std::cin >> rows >> cols;

    matrix.Init(rows, cols);

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Read matrix\n";
        std::cout << "2. Display matrix\n";
        std::cout << "3. Display submatrix\n";
        std::cout << "4. Resize matrix\n";
        std::cout << "5. Set number of rows\n";
        std::cout << "6. Set number of columns\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            matrix.Read();
            break;
        case 2:
            std::cout << "Matrix:\n";
            matrix.Display();
            break;
        case 3:
            int startRow, startCol, subRows, subCols;
            std::cout << "Enter starting row and column, and submatrix dimensions: ";
            std::cin >> startRow >> startCol >> subRows >> subCols;
            std::cout << std::endl;
            matrix.DisplaySubmatrix(startRow, startCol, subRows, subCols);
            break;
        case 4:
            int newRows, newCols;
            std::cout << "Enter new number of rows and columns: ";
            std::cin >> newRows >> newCols;
            matrix.Resize(newRows, newCols);
            break;
        case 5:
            std::cout << "Enter number of rows: ";
            std::cin >> rows;
            matrix.setRows(rows);
            break;
        case 6:
            std::cout << "Enter number of columns: ";
            std::cin >> cols;
            matrix.setCols(cols);
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}