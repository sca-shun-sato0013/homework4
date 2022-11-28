#include <iostream>
using namespace std;

class Critter {
public:
  Critter(int hunger = 0, int boredom = 0);
  void Talk();
  void Eat(int food = 4);
  void Play(int fun = 4);
  void Work(int enjoy = 4);

private:
  int m_Hunger;
  int m_Boredom;

  int GetMood() const;
  void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom)
    : m_Boredom(hunger), m_Hunger(boredom) {}

inline int Critter::GetMood() const { return (m_Hunger + m_Boredom); }

void Critter::PassTime(int time) {
  m_Hunger += time;
  m_Boredom += time;
}

void Critter::Work(int enjoy) {

  cout << "fun workplace"
       << ": " << enjoy << endl;
}

void Critter::Play(int fun) {
  cout << "Wheee!" << endl;

  m_Boredom -= fun;
  if (m_Boredom < 0) {
    m_Boredom = 0;
  }
  PassTime();
}

void Critter::Talk() {
  cout << "Im a critter and I feel";

  int mood = GetMood();
  if (mood > 15) {
    cout << "mad" << endl;
  } else if (mood > 10) {
    cout << "frustrated" << endl;
  } else if (mood > 5) {
    cout << "okay" << endl;
  } else {
    cout << "happy" << endl;
  }
  PassTime();
}

void Critter::Eat(int food) {
  cout << "Brruppp" << endl;
  m_Hunger -= food;
  if (m_Hunger < 0) {
    m_Hunger = 0;
  }
  PassTime();
}

int main() {
  Critter crit;
  crit.Talk();
  int choice;

  do {
    cout << "Critter Caretaker" << endl << endl;

    cout << "0 - Quit" << endl;

    cout << "1 - Quit" << endl;

    cout << "2 - Feed your critter" << endl;

    cout << "3 - Play with your critter" << endl;

    cout << "4 - critter doing a job" << endl << endl;

    cout << "Choice" << endl;
    cin >> choice;

    switch (choice) {
    case 0:

      cout << "Good-bye" << endl;
      break;

    case 1:
      crit.Talk();
      break;
    case 2:
      crit.Eat();
      break;
    case 3:
      crit.Play();
      break;
    case 4:
      crit.Work();
      break;
    default:
      cout << "Sorry, but" << choice << "isnt a valid choice" << endl;
    }
  } while (choice != 0);
  return 0;
}