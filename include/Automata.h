// Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 public:
  void on();
  void off();
  void coin(int money);
  void getMenu();
  STATES getState();
  int getCash();
  void choice(std::string drinkName);
  void cancel();
  void change();

  Automata() {
    cash = 0;
    state = OFF;
    menu = {"Latte", "Cappuccino", "Americano", "Hot Chocolate", "Espresso"};
    prices = {130, 100, 110, 90, 80};
  }

 private:
  int cash;
  std::vector<std::string> menu;
  std::vector<int> prices;
  STATES state;
  void check(std::string drinkName);
  void cook();
  void finish();
  void writeState();
  void writeBalance();
  bool isDrinkInMenu(std::string drinkName);
};
#endif // INCLUDE_AUTOMATA_H_
