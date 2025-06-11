# 🍬 Candy Crush - PF Project

This project is a simplified clone of **Candy Crush**, developed in **C++** using **OpenGL GLUT**, as a semester project for the **Programming Fundamentals (PF)** course at FAST Islamabad.

---

## 🧠 Features

- 🎮 Interactive Grid (5x5) with match-3 logic  
- 💥 Candy types: square, circle, triangle (3 types/colors)  
- 🔄 Swap adjacent candies by clicking  
- 🧠 Hints available (press 'H')  
- ⏸️ Pause/Resume game with Spacebar  
- ⏳ Live score and timer display  
- 🎲 Random candy generation  
- 🧽 Automatic match checking, removal, and refill  
- 👤 Player name input and display  

---

## 🗂 File Structure

```
/CandyCrush-PF-Project
│
├── candycrush.cpp        # Main game code
├── util.h                # Utility functions header (GLUT wrappers)
├── README.md             # This file
```

---

## ⚙️ How to Build & Run

### 🛠 Requirements

- C++ Compiler (`g++`, `clang++`, MSVC)
- **OpenGL** and **GLUT/freeglut** installed

### ✅ Compile on Linux/macOS

```bash
g++ candycrush.cpp -o candycrush -lGL -lGLU -lglut
./candycrush
```

### ✅ Compile on Windows (MinGW)

```bash
g++ candycrush.cpp -o candycrush.exe -lfreeglut -lopengl32 -lglu32
candycrush.exe
```

---

## ⌨️ Controls

| Key        | Action                          |
|------------|---------------------------------|
| `ENTER`    | Start the game from menu        |
| `ESCAPE`   | Exit from the menu screen       |
| `SPACEBAR` | Pause / Resume the game         |
| `H`        | Show possible move (hint)       |
| 🖱️ Click   | Select and swap adjacent candies |

---

## 📊 Game Logic

- Match 3 or more adjacent candies (horizontal/vertical)  
- Matching candies are removed and replaced with new ones  
- Score increases with each match  
- Hints find possible swaps that result in matches  

---

## 🖼️ UI Screens

- **Menu Screen**
  - Options to start the game or view high scores
- **Game Screen**
  - Grid with colorful candies
  - Timer and Score bar
  - Hint button displayed on screen

---

## 🧑‍🎓 Project Info

- 🎓 Course: Programming Fundamentals (PF)  
- 🏫 Institute: FAST - National University of Computer and Emerging Sciences  
- 📅 Semester: Spring/Fall 2024–25

---

## 📜 License

This project is built for educational and academic purposes only. Not intended for commercial use.

