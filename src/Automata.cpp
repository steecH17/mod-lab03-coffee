// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>
#include <string>

STATES Automata::getState() { 
    return state;
}

void Automata::getMenu() {
  if (state != OFF) {
    for (int i = 0; i < menu.size(); i++) {
      std::cout << menu[i] << " " << prices[i] << '\n';
    }
  }
}

int Automata::getCash() { return cash; }

void Automata::on() {
  if (state == OFF) {
    std::cout << "The coffee machine is ON!\n";
    state = WAIT;
  } else {
    std::cout << "Automata already worked!\n";
  }
}

void Automata::off() {
  if (state == WAIT) {
    std::cout << "The coffee machine is turned OFF!\n";
    change();
    state = OFF;
  } else {
    std::cout << "Cancel the current operation first!!!\n";
  }
}

void Automata::writeState() { std::cout << state << '\n'; }

void Automata::coin(int money) {
  if (state != OFF) {
    if (state == WAIT) {
      state = ACCEPT;
    }
    cash += money;
    writeBalance();
  }
}

void Automata::writeBalance() { std::cout << "Balance : " << cash << '\n'; }

void Automata::choice(std::string drinkName) {
  if (state == ACCEPT) {
    if (isDrinkInMenu(drinkName)) {
      std::cout << "You choice drink : " << drinkName << '\n';
      if (state == ACCEPT) {
        state = CHECK;
        check(drinkName);
      }
    } else {
      std::cout << "This drink is not on the menu.\n";
    }
  } else {
    std::cout << "Before choosing a drink, deposit the money.\n";
  }
}

void Automata::cancel() {
  if (state != OFF && state != WAIT) {
    state = WAIT;
    std::cout << "Cancellation of the operation\n";
  } else {
    std::cout << "It is impossible to cancel the operation!\n";
  }
}

void Automata::check(std::string drinkName) {
  if (state == CHECK) {
    int priceOfDrink = -1;
    for (int i = 0; i < menu.size(); i++) {
      if (drinkName == menu[i]) {
        priceOfDrink = prices[i];
        break;
      }
    }

    if (priceOfDrink <= cash) {
      cash -= priceOfDrink;
      cook();
    } else {
      std::cout << "There is not enough money in the balance\n";
      state = ACCEPT;
    }
  }
}

void Automata::cook() {
  std::cout << "Cooking";
  sleep(1);
  std::cout << "." << std::flush;
  sleep(1);
  std::cout << "." << std::flush;
  sleep(1);
  std::cout << "." << std::flush;
  sleep(1);
  std::cout << '\n';
  finish();
}

void Automata::finish() {
  std::cout << "Drink prepared!\nFinish!!! Put your drink!\n";
  state = WAIT;
  writeBalance();
}

bool Automata::isDrinkInMenu(std::string drinkName) {
  for (int i = 0; i < menu.size(); i++) {
    if (drinkName == menu[i]) {
      return true;
    }
  }
  return false;
}

void Automata::change() {
  if (state != OFF) {
    if (cash > 0) {
      std::cout << "Your change : " << cash << '\n';
      cash = 0;
    } else {
      std::cout << "Balance is empty.\n";
    }
  }
}
