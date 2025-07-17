#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

#define MONEY_VALUE 5

double calculateReward(int current, string choice) {
    if (current == 1 || current == 9) return 1.01;
    if (current == 2 || current == 8)
        return ((choice == "DOWN" && current == 8) || (choice == "UP" && current == 2)) ? 1.1 : 25.0;
    if (current == 3 || current == 7)
        return ((choice == "DOWN" && current == 7) || (choice == "UP" && current == 3)) ? 1.2 : 10.0;
    if (current == 4 || current == 6)
        return ((choice == "DOWN" && current == 6) || (choice == "UP" && current == 4)) ? 1.3 : 5.0;
    if (current == 5) return 1.05;
    return 0;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    bool playAgain = true;

    while (playAgain) {
        double balance = 1.0;
        int round = 1;
        int currentNumber = rand() % 9 + 1;
        string message;

        cout << "==== UP OR DOWN GAME ====" << endl;

        while (true) {
            double rewardDown = calculateReward(currentNumber, "DOWN");
            double rewardUp = calculateReward(currentNumber, "UP");

            cout << fixed << setprecision(2);
            cout << "\nROUND: " << round;
            cout << "\nCurrent Number: " << currentNumber;
            cout << "\nBalance: $" << balance * MONEY_VALUE;
            cout << "\nIf you pick DOWN, possible next balance: $" << balance * rewardDown * MONEY_VALUE;
            cout << "\nIf you pick UP, possible next balance: $" << balance * rewardUp * MONEY_VALUE;
            cout << "\n(1) DOWN  (2) UP  (0) GIVE UP: ";

            int choice;
            do {
                cin >> choice;
                if (choice != 0 && choice != 1 && choice != 2)
                    cout << "Invalid input. Please enter 0, 1, or 2: ";
            } while (choice != 0 && choice != 1 && choice != 2);

            if (choice == 0) {
                cout << "\nYou gave up. Final Balance: $" << balance * MONEY_VALUE << endl;
                break;
            }

            int nextNumber;
            do {
                nextNumber = rand() % 9 + 1;
            } while (nextNumber == currentNumber);

            string choiceStr = (choice == 1) ? "DOWN" : "UP";
            double reward = calculateReward(currentNumber, choiceStr);

            if ((choice == 1 && nextNumber < currentNumber) || (choice == 2 && nextNumber > currentNumber)) {
                balance *= reward;
                currentNumber = nextNumber;
                round++;
                cout << "\nCorrect! New number is " << nextNumber << endl;
            } else {
                cout << "\nWrong! Number was " << nextNumber << ". You lost.";
                balance = 0;
                break;
            }
        }

        int again;
        cout << "\nDo you want to play again? (1: Yes / 0: No): ";
        cin >> again;
        playAgain = (again == 1);
    }

    cout << "\nThanks for playing!" << endl;
    return 0;
}
