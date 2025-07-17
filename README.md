# 🎲 Up or Down - C++ Console Game

A simple number prediction game recreated in **C++** for the terminal, originally inspired by the iOS SwiftUI version.

---

## 🎮 How to Play
- A random number between **1 and 9** appears.
- You predict whether the next number will go **UP** or **DOWN**.
- The next number is always **different** from the current number.
- Correct guesses multiply your balance based on difficulty:
    - **Safer choices** give lower rewards.
    - **Riskier choices** give higher rewards.
- You can gain up to **25X OR MORE** if you get 5 correct in a row.

  
You can **"GIVE UP"** at any time to secure your current balance,  
but if your guess is wrong the game ends with **NO REWARD AND YOUR BALANCE RESET TO ZERO**.

---

## 💡 Features
- Random numbers from **1 to 9**
- Ensures the next number is **never the same** as the current
- Balance grows based on risk/reward
- Clear round counter display
- Shows possible rewards for both **UP** and **DOWN**
- Simple and clean **console-based interface**
- Option to restart the game after losing

---

## 🚀 Technologies Used
- **C++**
- **Standard Library:** `iostream`, `cstdlib`, `ctime`, `iomanip`

---

## 🔧 How to Run
### 💻 Using `g++` (Terminal):
```bash
g++ main.cpp -o UpOrDown
./UpOrDown
