#ifndef TTT_HPP
#define TTT_HPP

#include <iostream>
enum status { U, X, O };
struct account {
  unsigned xcount, ocount;
  account() {
    xcount = 0;
    ocount = 0;
  }
};
class TTT {
  status matrix[3][3], chance;
  account row[3], col[3], diagonal[2];

  void remember_o(unsigned x, unsigned y);
  void remember_x(unsigned x, unsigned y);
  bool check_win_x();
  bool check_win_o();

public:
  TTT();

  unsigned mark(unsigned x, unsigned y);
  void print();
};

TTT::TTT() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      matrix[i][j] = U;
    }
  }
  chance = X;
}
void TTT::remember_x(unsigned x, unsigned y) {
  row[x].xcount++;
  col[y].xcount++;
  if (x == y) {
    diagonal[0].xcount++;
  }
  if (x == 2 - y) {
    diagonal[1].xcount++;
  }
}
void TTT::remember_o(unsigned x, unsigned y) {
  row[x].ocount++;
  col[y].ocount++;
  if (x == y) {
    diagonal[0].ocount++;
  }
  if (x == 3 - y) {
    diagonal[1].ocount++;
  }
}
bool TTT::check_win_o() {
  for (auto elm : row) {
    if (elm.ocount == 3) {
      return true;
    }
  }
  for (auto elm : col) {
    if (elm.ocount == 3) {
      return true;
    }
  }
  for (auto elm : diagonal) {
    if (elm.ocount == 3) {
      return true;
    }
  }
  return false;
}
bool TTT::check_win_x() {
  for (auto elm : row) {
    if (elm.xcount == 3) {
      return true;
    }
  }
  for (auto elm : col) {
    if (elm.xcount == 3) {
      return true;
    }
  }
  for (auto elm : diagonal) {
    if (elm.xcount == 3) {
      return true;
    }
  }

  return false;
}
unsigned TTT::mark(unsigned x, unsigned y) {

  if (!(x >= 0 && y >= 0 && x < 3 && y < 3))
    return -1;
  if (matrix[x][y] == U) {
    matrix[x][y] = chance;
    if (chance == X) {
      chance = O;
      remember_x(x, y);
    } else {
      chance = X;
      remember_o(x, y);
    }
    if (check_win_x()) {
      return 1;
    } else if (check_win_o()) {
      return 2;
    } else
      return 3;
  } else
    return 0;
}
void TTT::print() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      switch (matrix[i][j]) {
      case 0:
        std::cout << "- ";
        break;
      case 1:
        std::cout << "X ";
        break;
      case 2:
        std::cout << "O ";
        break;
      }
    }
    std::cout << std::endl;
  }
}

#endif
