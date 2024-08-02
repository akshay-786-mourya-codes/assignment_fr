#include <iostream>
#include <vector>
#include <tuple>

// Structure to hold the coordinates of an airport
struct Coordinate {
    int x;
    int y;
    int z;
};

// Function to draw the flight paths
void drawFlightPaths(const std::vector<std::tuple<Coordinate, Coordinate, Coordinate>>& flights) {
    for(size_t i = 0; i < flights.size(); ++i) {
        auto [c1, c2, c3] = flights[i];
        std::cout << "Flight " << i + 1 << ": (" << c1.x << ", " << c1.y << ", " << c1.z << ") -> "
                  << "(" << c2.x << ", " << c2.y << ", " << c2.z << ") -> "
                  << "(" << c3.x << ", " << c3.y << ", " << c3.z << ")" << std::endl;
    }
}

int main() {
    // Input coordinates for each flight
    std::vector<std::tuple<Coordinate, Coordinate, Coordinate>> flights = {
        { {1, 1, 1}, {2, 2, 2}, {3, 3, 3} },
        { {1, 1, 1}, {2, 4, 3}, {3, 2, 4} },
        { {1, 1, 1}, {4, 2, 3}, {4, 3, 4} }
    };

    // Draw the flight paths
    drawFlightPaths(flights);

    return 0;
}
