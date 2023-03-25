#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct location
{
    int row;
    int column;
};

void findWay(struct location currentLocation, int &waysCount, int matrixRowAndCols)
{

    // If it reaches cheese, return true and add waysCount
    if (currentLocation.row == matrixRowAndCols && currentLocation.column == matrixRowAndCols)
    {
        waysCount++;
        return;
    }

    // Every time, we try to go righ first, and if it is not possible, we go down
    struct location nextLocation1, nextLocation2;
    nextLocation1 = {currentLocation.row, currentLocation.column + 1};
    nextLocation2 = {currentLocation.row + 1, currentLocation.column};

    // Check if we remain in the down and left half of matrix if do move2
    if (nextLocation1.column <= nextLocation1.row)
    {
        findWay(nextLocation1, waysCount, matrixRowAndCols);
    }
    // Check if we dont go out of matrix if do move1
    if (nextLocation2.row <= matrixRowAndCols)
    {
        findWay(nextLocation2, waysCount, matrixRowAndCols);
    }
}

int main()
{
    int matrixRowAndCols;
    cin >> matrixRowAndCols;

    int waysCount = 0;
    struct location startPoint = {0, 0};

    findWay(startPoint, waysCount, matrixRowAndCols);
    cout << waysCount;
    return 0;
}