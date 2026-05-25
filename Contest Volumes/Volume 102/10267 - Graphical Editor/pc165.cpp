#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>
#include <fstream>


class Image {
public:
    Image() {}

    void command(const std::vector<std::string>& cmd) {
        if (cmd[0] == "I") {
            newImgI(std::stoi(cmd[1]), std::stoi(cmd[2]));
        }
        if (cmd[0] == "C") {
            clearC();
        }
        if (cmd[0] == "L") {
            locationL(std::stoi(cmd[1]), std::stoi(cmd[2]), cmd[3]);
        }
        if (cmd[0] == "V") {
            vertV(std::stoi(cmd[1]), std::stoi(cmd[2]), std::stoi(cmd[3]), cmd[4]);
        }
        if (cmd[0] == "H") {
            horizH(std::stoi(cmd[1]), std::stoi(cmd[2]), std::stoi(cmd[3]), cmd[4]);
        }
        if (cmd[0] == "K") {
            rectK(std::stoi(cmd[1]), std::stoi(cmd[2]), std::stoi(cmd[3]), std::stoi(cmd[4]), cmd[5]);
        }
        if (cmd[0] == "F") {
            fillF(std::stoi(cmd[1]), std::stoi(cmd[2]), cmd[3]);
        }
        if (cmd[0] == "S") {
            saveS(cmd[1]);
        }
    }

private:
    std::vector<std::vector<std::string>> img;

    void newImgI(int M, int N) {
        img.clear();
        img.resize(N, std::vector<std::string>(M, "O"));
    }

    void locationL(int X, int Y, const std::string& C) {
        img[Y - 1][X - 1] = C;
    }

    void clearC() {
        for (auto& row : img) {
            std::fill(row.begin(), row.end(), "O");
        }
    }

    void vertV(int X, int Y1, int Y2, const std::string& C) {
        for (int y = std::min(Y2, Y1) - 1; y < std::max(Y1, Y2); ++y) {
            img[y][X - 1] = C;
        }
    }

    void horizH(int X1, int X2, int Y, const std::string& C) {
        int lower = std::min(X2, X1) - 1;
        int upper = std::max(X1, X2) - 1;
        std::fill(img[Y - 1].begin() + lower, img[Y - 1].begin() + upper + 1, C);
    }

    void rectK(int X1, int Y1, int X2, int Y2, const std::string& C) {
        int lower = std::min(X1, X2) - 1;
        int upper = std::max(X2, X1) - 1;
        for (int y = std::min(Y1, Y2) - 1; y < std::max(Y2, Y1); ++y) {
            std::fill(img[y].begin() + lower, img[y].begin() + upper + 1, C);
        }
    }

    void fillF(int X, int Y, const std::string& C) {
        int maxX = img[0].size();
        int maxY = img.size();
        int origX = X - 1;
        int origY = Y - 1;
        std::string oldColor = img[origY][origX];

        if (oldColor != C) {
            std::vector<std::pair<int, int>> queue;
            std::set<std::pair<int, int>> visited;

            queue.emplace_back(origX, origY);
            visited.insert({origX, origY});
            img[origY][origX] = C;

            while (!queue.empty()) {
                auto [curX, curY] = queue.back();
                queue.pop_back();

                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if (std::abs(i) + std::abs(j) == 1) { // Only adjacent cells
                            int nextX = curX + j;
                            int nextY = curY + i;

                            if (nextX >= 0 && nextX < maxX && nextY >= 0 && nextY < maxY) {
                                if (img[nextY][nextX] == oldColor) {
                                    img[nextY][nextX] = C;
                                    if (visited.insert({nextX, nextY}).second) {
                                        queue.emplace_back(nextX, nextY);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    void saveS(const std::string& Name) {
        std::cout << Name << std::endl;
        for (const auto& row : img) {
            for (const auto& cell : row) {
                std::cout << cell;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Image img;
    std::string line;

    
    while (std::getline(std::cin, line)) {
        if (line != "X") {
            std::vector<std::string> cmd;
            std::istringstream iss(line);
            std::string token;
            while (iss >> token) {
                cmd.push_back(token);
            }
            img.command(cmd);
        } else {
            //std::cout << std::endl;
            break;
        }
    }
    
    /*
    std::ifstream file("pc165_inputs.txt");
    while (std::getline(file, line)) {
        if (line != "X") {
            std::vector<std::string> cmd;
            std::istringstream iss(line);
            std::string token;
            while (iss >> token) {
                cmd.push_back(token);
            }
            img.command(cmd);
        } else {
            //std::cout << std::endl;
            break;
        }
    }*/

    return 0;
}