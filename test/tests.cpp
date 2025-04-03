// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, InitialStateIsOFF) {
  Automata automata = Automata();
  ASSERT_EQ(STATES::OFF, automata.getState());
}

TEST(AutomataTest, TurnONTheAutomata) {
  Automata automata = Automata();
  automata.on();
  ASSERT_EQ(STATES::WAIT, automata.getState());
}

TEST(AutomataTest, DepositMoney) {
  Automata automata = Automata();
  automata.on();
  automata.coin(50);
  ASSERT_EQ(STATES::ACCEPT, automata.getState());
  ASSERT_EQ(50, automata.getCash());
}

TEST(AutomataTest, ReDepositMoney) {
  Automata automata = Automata();
  automata.on();
  automata.coin(50);
  automata.coin(30);
  ASSERT_EQ(STATES::ACCEPT, automata.getState());
  ASSERT_EQ(80, automata.getCash());
}

TEST(AutomataTest, StateAcceptCancel) {
  Automata automata = Automata();
  automata.on();
  automata.coin(50);
  automata.cancel();
  ASSERT_EQ(STATES::WAIT, automata.getState());
  ASSERT_EQ(50, automata.getCash());
}

TEST(AutomataTest, ChoiceDrinkHaveMoney) {
  Automata automata = Automata();
  automata.on();
  automata.coin(200);
  automata.choice("Latte");
  ASSERT_EQ(STATES::WAIT, automata.getState());
  ASSERT_EQ(70, automata.getCash());
}

TEST(AutomataTest, ChoiceDrinkDontHaveMoney) {
  Automata automata = Automata();
  automata.on();
  automata.coin(50);
  automata.choice("Latte");
  ASSERT_EQ(STATES::ACCEPT, automata.getState());
  ASSERT_EQ(50, automata.getCash());
}

TEST(AutomataTest, ChoiceUnknowDrink) {
  Automata automata = Automata();
  automata.on();
  automata.coin(200);
  automata.choice("Tea");
  ASSERT_EQ(STATES::ACCEPT, automata.getState());
}

TEST(AutomataTest, CorrectPreparationDrink) {
  Automata automata = Automata();
  automata.on();
  automata.coin(110);
  automata.choice("Americano");
  ASSERT_EQ(STATES::WAIT, automata.getState());
  ASSERT_EQ(0, automata.getCash());
}

TEST(AutomataTest, CorrectPreparationDrinkMuchMoney) {
  Automata automata = Automata();
  automata.on();
  automata.coin(200);
  automata.choice("Americano");
  ASSERT_EQ(STATES::WAIT, automata.getState());
  ASSERT_EQ(90, automata.getCash());
}

TEST(AutomataTest, CorrectPreparationDrinkWithChange) {
  Automata automata = Automata();
  automata.on();
  automata.coin(200);
  automata.choice("Americano");
  ASSERT_EQ(STATES::WAIT, automata.getState());
  automata.change();
  ASSERT_EQ(0, automata.getCash());
}

TEST(AutomataTest, CorrectPreparationTwoDrink) {
  Automata automata = Automata();
  automata.on();
  automata.coin(150);
  automata.choice("Americano");
  ASSERT_EQ(STATES::WAIT, automata.getState());
  automata.coin(40);
  automata.choice("Espresso");
  ASSERT_EQ(STATES::WAIT, automata.getState());
  ASSERT_EQ(0, automata.getCash());
}

TEST(AutomataTest, OFFFromACCEPTState) {
  Automata automata = Automata();
  automata.on();
  automata.coin(100);
  automata.off();
  ASSERT_EQ(STATES::ACCEPT, automata.getState());
  ASSERT_EQ(100, automata.getCash());
}

TEST(AutomataTest, OFFFromOFFState) {
  Automata automata = Automata();
  automata.off();
  ASSERT_EQ(STATES::OFF, automata.getState());
}

TEST(AutomataTest, ExceptionChoiceWhenAutomataOFF) {
  Automata automata = Automata();
  automata.choice("Americano");
  ASSERT_EQ(STATES::OFF, automata.getState());
  ASSERT_EQ(0, automata.getCash());
}

TEST(AutomataTest, ExceptionChangeWhenAutomataOFF) {
  Automata automata = Automata();
  automata.change();
  ASSERT_EQ(STATES::OFF, automata.getState());
  ASSERT_EQ(0, automata.getCash());
}

TEST(AutomataTest, ExceptionCancelWhenAutomataWAIT) {
  Automata automata = Automata();
  automata.on();
  automata.change();
  ASSERT_EQ(STATES::WAIT, automata.getState());
}

TEST(AutomataTest, ExceptionCoinWhenAutomataOFF) {
  Automata automata = Automata();
  automata.coin(10);
  ASSERT_EQ(STATES::OFF, automata.getState());
  ASSERT_EQ(0, automata.getCash());
}
