#include "ttt.hpp"
#include <cstdlib>
#include <iostream>

void get_pos(unsigned &x, unsigned &y) {
  std::cout << "Enter Position :";
  std::cin >> x;
  y = (x % 10) - 1;
  x = (x / 10) - 1;
}
int main(int argc, char const *argv[]) {
  TTT t;
  unsigned chances = 9, x, y, code;

  try {
    code = system("clear");
    code = system("figlet -f slant Tic Tac Toe!!");
  } catch (...) {
    std::cout << "figlet error\n";
  }

  while (1 == 1) {
    get_pos(x, y);

    code = t.mark(x, y);
    system("clear");
    if (code > 0) {
      t.print();
      chances--;
      if (code == 1) {
        std::cout << "Player 1 won!\n";
        break;
      } else if (code == 2) {
        std::cout << "Player 2 won!\n";
        break;
      } else if (code == 3 and !chances) {
        std::cout << "It's a Draw!!\n";
        break;
      }
    } else {
      if (code == 0)
        std::cout << "\nPosition already occupied -_-\nEnter again\n";
      else
        std::cout << "Invalid Position!!\n";
    }
  }

  return 0;
}
