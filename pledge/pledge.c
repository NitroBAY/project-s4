#include <stdio.h>
#include <stddef.h>

void pledge(size_t row, size_t col, int labyrinth[row][col]) {
    size_t robot_x = 0;
    size_t robot_y = 0;
    long direction = 0;

    while (1) {
        if (labyrinth[robot_y][robot_x] == 2) break;

        if (direction == 0) {
            if (labyrinth[robot_y + 1][robot_x] == 0) { // NO WALL IN FRONT OF ROBOT
                robot_y++;
            } else if (labyrinth[robot_y + 1][robot_x] == 1) { // WALL IN FRONT OF ROBOT
                if (labyrinth[robot_y][robot_x - 1] == 0) { // WE CAN GO LEFT
                    direction += 1;
                    robot_x -= 1;
                } else { // WE CAN ONLY GO RIGHT
                    direction += 1;
                    robot_x -= 1;
                }
            }
        }
        else {
            // x and y that is at robot's right side
            size_t x_of_right_side = 0;
            size_t y_of_right_side = 0;

            if (direction == -3 || direction == 1 || direction == -1 || direction == 3) { // we are going west/east
                x_of_right_side = robot_x;
                y_of_right_side = robot_y - 1;
            } else if (direction == 2 || direction == -2) { // we are going south
                x_of_right_side = robot_x - 1;
                y_of_right_side = robot_y;
            }

            size_t x_to_move = 0;
            size_t y_to_move = 0;

            if (direction == -3 || direction == 1) { // we are going west
                x_to_move = 1;
            } else if (direction == -1 || direction == 3) { // we are going west
                x_to_move = -1;
            } else if (direction == 2 || direction == -2) { // we are going south
                y_to_move = -1;
            }

            if (labyrinth[y_of_right_side][x_of_right_side] == 1) { // we keep following wall (at our right side)
                size_t x_of_left_side = -x_of_right_side;
                size_t y_of_left_side = -y_of_right_side;

                if (labyrinth[y_to_move][x_to_move] == 0) {
                    robot_x += x_to_move;
                    robot_y += y_to_move;
                } else {
                    if (labyrinth[y_of_left_side][x_of_left_side] == 0) { // we can go left
                        direction += 1;
                        robot_x += x_of_left_side;
                        robot_y += y_of_left_side;
                    } else { // WE CAN ONLY GO BACKWARD
                        robot_x -= x_to_move;
                        robot_y -= y_to_move;
                    }
                }
            } else { // no wall at our right
                robot_x += x_of_right_side;
                robot_y += x_of_right_side;
                direction -= 1;
            }
        }
    }
}

