// Copyright 2022 UNN-IASR
#include "Automata.h"

int main() {
  Automata machine = Automata();
  machine.on();
  machine.getMenu();
  machine.coin(80);
  machine.coin(20);
  machine.choice("Hot Chocolate");
  machine.choice("Latte");
  machine.change();
  machine.change();
  machine.off();
}
