#include <iostream>
using namespace std;

// Namespace for square operations
namespace Square {
    int num;

    int fun(int n) {
        return n * n;
    }
}

// Namespace for cube operations
namespace Cube {
    int num;

    int fun(int n) {
        return n * n * n;
    }
}

int main() {
    // Set num in Square namespace
    Square::num = 4;

    // Set num in Cube namespace
    Cube::num = 3;

    // Compute and print the cube of Square::num using Cube::fun
    int cubeOfSquareNum = Cube::fun(Square::num);
    cout << "Cube of Square::num (" << Square::num << ") = " << cubeOfSquareNum << endl;

    // Compute and print the square of Cube::num using Square::fun
    int squareOfCubeNum = Square::fun(Cube::num);
    cout << "Square of Cube::num (" << Cube::num << ") = " << squareOfCubeNum << endl;

    return 0;
}
