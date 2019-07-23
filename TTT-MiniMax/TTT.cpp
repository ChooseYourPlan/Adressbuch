#include <bitset>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "../TextTable.h"

#define P1 false
#define P2 true

struct feld {
  unsigned short int p1 : 9;
  unsigned short int p2 : 9;
  unsigned short int to_check : 9;

  bool turn = P1;
  bool gameov = false;

  feld() {
    p1 = 0b000000000;
    p2 = 0b000000000;
    to_check = 0b000000000;
  }

  void Bitset(bool P, short int index) {
    if (P == P1) {
      this->p1 |= 1UL << index;
    } else {
      this->p2 |= 1UL << index;
    }
  }

  bool check_bit(bool P, short int index) {
    if (P == P1) {
      return (this->p1 & (1 << index));
    } else {
      return (this->p2 & (1 << index));
    }
  }

  bool tie() const { return (p1 + p2) == 511; }

  bool move(short int index) {
    if (check_bit(P1, index) || check_bit(P2, index)) return false;
    if (turn == P1)
      Bitset(P1, index);
    else
      Bitset(P2, index);
    return true;
  }

  std::vector<std::bitset<9>> possible_moves(std::bitset<9> to_check_p1,
                                             std::bitset<9> to_check_p2,
                                             bool P) {
    std::vector<std::bitset<9>> pm;

    for (int i = 0; i < 9; i++) {
      if (!to_check_p1.test(i) && !to_check_p2.test(i)) {
        if (P == P1) {
          to_check_p1.set(i, 1);
          pm.push_back(to_check_p1);
          to_check_p1.reset(i);
        } else {
          to_check_p2.set(i, 1);
          pm.push_back(to_check_p2);
          to_check_p2.reset(i);
        }
      }
    }
    return pm;
  }

  std::size_t get_move(std::bitset<9> move) {
    std::bitset<9> p_moves = ~(p1 | p2);
    move &= p_moves;
    std::size_t i = 0;
    while (i < move.size() && !move.test(i)) ++i;
    return i;
  }

  short int random_move() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 9);
    return dist6(rng) - 1;
  }

  std::bitset<9> findmove() {
    auto moves = possible_moves(std::bitset<9>(p1), std::bitset<9>(p2), P2);
    std::bitset<9> retvalue = 0;
    int best_score = 5000;
    for (auto &i : moves) {
      int score = eve_tree(P1, p1, i);
      if (score <= best_score) {
        best_score = score;
        retvalue = i;
      }
    }
    return retvalue;
  }

  int eve_tree(bool mm_turn, std::bitset<9> cp1 = 0, std::bitset<9> cp2 = 0) {
    if (win(cp1))
      return 100;
    else if (win(cp2))
      return -100;
    else if (cp1.to_ulong() + cp2.to_ulong() == 511)
      return 0;

    int best_score = 0;

    if (mm_turn == P1) {
      best_score = -5000;
      auto moves = possible_moves(cp1, cp2, mm_turn);
      for (auto &i : moves) {
        int score = eve_tree(!mm_turn, i, cp2);
        score += moves.size();
        if (score >= best_score) best_score = score;
      }
    } else {
      best_score = 5000;
      auto moves = possible_moves(cp1, cp2, mm_turn);
      for (auto &i : moves) {
        int score = eve_tree(!mm_turn, cp1, i);
        score -= moves.size();
        if (score <= best_score) best_score = score;
      }
    }
    return best_score;
  }

  int game(bool draw_f) {
    short int index;
    do {
      do {
        if (turn == P1) {
          index = random_move();
        } else {
          index = get_move(findmove());
        }

      } while (!move(index));
      if(draw_f)
        draw();
      if (win() == true) {
        if (turn == P1) {
		  if(draw_f)
				std::cout << "Spieler 1 hat gewonnen" << std::endl;
		   reset_all();
		   return 1;
        } else if(turn == P2) {
		  if(draw_f)
				 std::cout << "Spieler 2 hat gewonnen" << std::endl;
		  reset_all();
		  return 2;
		}

        gameov = true;
        break;
      }
      if (tie() == true) {
        gameov = true;
		if(draw_f)
        std::cout << "Unentschieden" << std::endl;
		reset_all();
		return 0;
        break;
      }
      turn = !turn;
    } while (!gameov);
   }

  void reset_all() {
    p1 = 0b00000000;
    p2 = 0b00000000;
    turn = P1;
    gameov = false;
  }

  bool win() {
    if (turn == P1)
      to_check = p1;
    else
      to_check = p2;

    return (to_check & 7) == 7 || (to_check & 56) == 56 ||
           (to_check & 448) == 448 || (to_check & 292) == 292 ||
           (to_check & 146) == 146 || (to_check & 73) == 73 ||
           (to_check & 273) == 273 || (to_check & 84) == 84;
  }

  bool win(std::bitset<9> to_checkbit) {
    short int to_check = to_checkbit.to_ulong();

    return (to_check & 7) == 7 || (to_check & 56) == 56 ||
           (to_check & 448) == 448 || (to_check & 292) == 292 ||
           (to_check & 146) == 146 || (to_check & 73) == 73 ||
           (to_check & 273) == 273 || (to_check & 84) == 84;
  }

  void draw() {
    TextTable t('-', '|', '+');
    for (int i = 1; i < 10; i++) {
      std::string buff;
      if (check_bit(P1, i - 1)) {
        buff = "X";
        t.add(buff);
      } else if (check_bit(P2, i - 1)) {
        buff = 'O';
        t.add(buff);
      } else {
        buff = std::to_string(i);
        t.add(buff);
      }

      if (i % 3 == 0) t.endOfRow();
    }

    t.setAlignment(1, TextTable::Alignment::LEFT);
    std::cout << t;
  }
};
