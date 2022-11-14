#include <iostream>
#include <cstring>

int main(int ac, char **argv) {
    int i;

    i = 0;
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } else {
        while (++i < ac) {
            for (int j = 0; static_cast<size_t>(j) < strlen(argv[i]); j++) {
                std::cout << static_cast<char>(toupper(argv[i][j]));
            }
        }
    }
    std::cout << std::endl;
