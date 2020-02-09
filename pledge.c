#include <stdio.h>

void pledge(size_t row, size_t col, int labyrinth[row][col]) {
    size_t robot_x = 0;
    size_t robot_y = 0;
    long directions = 0;

    while (1) {
        if (labyrinth[robot_y][robot_x] == 2) break;

        if (directions == 0) {
            if (labyrinth[robot_y + 1][robot_x] == 0) { // NO WALL IN FRONT OF ROBOT
                robot_y++;
            } else if (labyrinth[robot_y + 1][robot_x] == 1) { // WALL IN FRONT OF ROBOT
                if (labyrinth[robot_y][robot_x - 1] == 0) { // WE CAN GO LEFT
                    directions += 1;
                    robot_x -= 1;
                } else { // WE CAN ONLY GO RIGHT
                    directions += 1;
                    robot_x -= 1;
                }
            }
        }
        else {
            if (labyrinth[robot_y][robot_x - 1] == 0) { // NO WALL IN THE WEST
                if (labyrinth[robot_y + 1][robot_x] == 1) { // LET'S GO RIGHT TO KEEP WALL AT OUR RIGHT
                    robot_y++;
                    directions--;
                } else {
                    robot_x--;
                }
            } else {
                if (labyrinth[robot_y - 1][robot_x] == 0) { // WE CAN GO LEFT (SOUTH)
                    directions += 1;
                    robot_y -= 1;
                } else if (labyrinth[robot_y + 1][robot_x] == 0) { // WE CAN ONLY GO RIGHT (NORTH)
                    directions += 1;
                    robot_y += 1;
                }
            }
        }
    }
}

