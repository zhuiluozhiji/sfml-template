#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5,6,7,8,9};
    for(size_t i = 0; i < v.size(); ++i)
    {
        if (true) // Check if the number is even
        {
            v.erase(v.begin() + i); // Remove the even number
            //i--; // Adjust index after erasing
        }
    }

    for(const auto& num : v)
    {
        cout << num << " ";
    }
    return 0;
}