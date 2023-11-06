/*

*/
#include "raylib.h"

int main()
{
    // Initialize WIDTH and HEIGHT variables
    int width = 800;
    int height = 450;

    
    // Additional data types, for reference
    float root_beer = 1.99; // holds 6-7 characters
    double cheese_burger{5.99}; // holds 15-16 characters
    bool shouldHaveLunch{}; // initialized to false
    // operator quiz
    bool equal{4 == 9}; // false
    bool notEqual{4 != 9}; // true
    bool less{4 < 9}; // true
    bool greater{4 > 9}; // false
    bool lessEqual{4 <= 9}; // true
    bool greaterEqual{4 >= 9}; // false
    
    
    // Initialize Popup window with specified dimensions and title
    InitWindow(width, height, "Axe Game");

    return 0;
}