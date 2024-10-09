#include <iostream>
#include <vector>
#include <unistd.h>  // For usleep function
#include <cstdlib>   // For system("cls")

using namespace std;

const int grid_width = 20;
const int grid_height = 20;
const char ALIVE = 'o'; // Character representing a live cell
const char DEAD = ' ';  // Character representing a dead cell

// Class representing a single cell in the grid
class Cell 
{
public:
    // Constructor initializes the cell as dead
    Cell()  
    {
        alive = false; 
    }

    // Getter to check if the cell is alive
    bool isAlive() const { return alive; }

    // Setter to update the cell's alive state
    void setAlive(bool alive) { this->alive = alive; }

    // Overloaded << operator to print the cell's state (alive or dead)
    friend ostream& operator<<(ostream& os, const Cell& cell) {
        os << (cell.isAlive() ? ALIVE : DEAD);
        return os;
    }

private:
    bool alive; // Tracks whether the cell is alive or dead
};

// Class representing the entire grid of cells
class Grid 
{
public:
    // Constructor initializes the grid with dead cells
    Grid() 
    {
        for (int i = 0; i < grid_height; ++i) 
        {
            vector<Cell> row;
            for (int j = 0; j < grid_width; ++j) 
            {
                row.push_back(Cell()); // Initialize each cell as dead
            }
            cells.push_back(row); // Add the row to the grid
        }
    }

    // Function to count the number of alive neighbors for a given cell
    int countAliveNeighbors(int x, int y) const 
    {
        int count = 0;
        for (int i = -1; i <= 1; ++i) 
        {
            for (int j = -1; j <= 1; ++j) 
            {
                if (i == 0 && j == 0) continue; // Skip the cell itself

                int neighborX = x + i;
                int neighborY = y + j;

                // Check if the neighbor is within grid bounds and alive
                if (neighborX >= 0 && neighborX < grid_height && neighborY >= 0 && neighborY < grid_width) 
                {
                    if (cells[neighborX][neighborY].isAlive()) 
                    {
                        count++;
                    }
                }
            }
        }
        return count; // Return the count of alive neighbors
    }

    // Function to update the grid based on the Game of Life rules
    void update() 
    {
        vector<vector<Cell>> new_cells = cells; // Create a copy of the current grid

        for (int i = 0; i < grid_height; ++i) 
        {
            for (int j = 0; j < grid_width; ++j) 
            {
                int alive_neighbours = countAliveNeighbors(i, j); // Count alive neighbors
                
                // Apply rules of Game of Life
                if (cells[i][j].isAlive()) 
                {
                    if (alive_neighbours < 2 || alive_neighbours > 3) 
                    {
                        new_cells[i][j].setAlive(false); // Cell dies
                    }
                } 
                else 
                {
                    if (alive_neighbours == 3) 
                    {
                        new_cells[i][j].setAlive(true); // Cell becomes alive
                    }
                }
            }
        }

        cells = new_cells; // Update the grid with the new state
    }

    // Function to set a specific cell as alive
    void aliveNew(int a, int b) 
    {
        cells[a][b].setAlive(true);
    }

    // Overloaded << operator to print the entire grid
    friend ostream& operator<<(ostream& os, const Grid& grid) 
    {
        for (int i = 0; i < grid_height; ++i) 
        {
            for (int j = 0; j < grid_width; ++j) 
            {
                os << grid.cells[i][j] << ' '; // Print each cell
            }
            os << endl;
        }
        return os;
    }

private:
    vector<vector<Cell>> cells; // 2D grid of cells
};

int main() 
{
    Grid grid;
    int ch;

    // Prompt user to select a pattern
    cout << "ENTER CHOICE \n 1. LWSS : \n 2. Glider :  \n 3. Penta Decathalon : ";
    cin >> ch;

    // Set up the initial configuration based on user choice
    switch(ch)
    {
        case 1: // LWSS pattern
            grid.aliveNew(3,3);
            grid.aliveNew(3,4);
            grid.aliveNew(3,5);
            grid.aliveNew(3,6);
            grid.aliveNew(3,7);
            grid.aliveNew(4,7);
            grid.aliveNew(4,2);
            grid.aliveNew(5,7);
            grid.aliveNew(6,6);
            grid.aliveNew(7,4);
            break;

        case 2: // Glider pattern
            grid.aliveNew(1,2);
            grid.aliveNew(3,2);
            grid.aliveNew(2,3);
            grid.aliveNew(2,4);
            grid.aliveNew(3,2);
            grid.aliveNew(3,3);
            break;

        case 3: // Penta Decathalon pattern
            grid.aliveNew(8,8);
            grid.aliveNew(9,8);
            grid.aliveNew(10,7);
            grid.aliveNew(10,9);
            grid.aliveNew(11,8);
            grid.aliveNew(12,8);
            grid.aliveNew(13,8);
            grid.aliveNew(14,8);
            grid.aliveNew(15,7);
            grid.aliveNew(15,9);
            grid.aliveNew(16,8);
            grid.aliveNew(17,8);
            break;

        default:
            cout << "Invalid choice, exiting.";
            return 0;
    }

    // Continuously update and display the grid
    while (true) 
    {
        system("cls"); // Clear the console (system("clear") for Linux/Mac)
        cout << grid;  // Display the grid
        grid.update(); // Update the grid state
        usleep(1);     // Sleep to control the simulation speed
    }

    return 0;
}
