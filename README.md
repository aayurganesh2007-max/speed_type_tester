# speed_type_tester
Typing Speed Tester:(implemented in c++)
measures WPM,calculates typing accuracy, and tracks improvement over multiple sessions 
---

# ⌨️ Typing Speed Tester (C++)

A command-line **Typing Speed Tester** written in **C++**, designed to measure typing performance over a fixed time duration.
The program evaluates **WPM, CPM, accuracy**, tracks **mistyped words**, and stores session analytics for future reference.

This project focuses on **clean modular design**, **file handling**, and **time-based input processing** using standard C++ libraries.

---

## ✨ Features

* ⏱️ **Time-based typing test**
* 📝 **Random word display** from a word list file
* ⌨️ **User input tracking** until timer expires
* 📊 **Analytics computation**

  * Words Per Minute (WPM)
  * Characters Per Minute (CPM)
  * Word accuracy (%)
  * Character accuracy (%)
* ❌ **Incorrect words tracking**
* 💾 **Persistent storage**

  * Session analytics stored in CSV format
  * Incorrect words stored in a text file
* 🧩 **Modular code structure** (analytics, file handling, I/O separated)

---

## 🗂️ Project Structure

```
.
├── analytics.h / analytics.cpp
│   └── Typing performance calculations (WPM, accuracy, etc.)
│
├── file_handler.h / file_handler.cpp
│   └── File I/O for reading words and storing session data
│
├── input_output.h / input_output.cpp
│   └── User interaction and display logic
│
├── main.cpp
│   └── Program flow, timing logic, and session control
│
├── words.txt
│   └── Word source file for typing tests
│
├── analytics.csv
│   └── Stored session analytics
│
├── incorrect_words.txt
│   └── Mistyped words per session
│
└── README.md
```

---

## 🧠 How It Works

1. User selects:

   * Typing duration (seconds)
   * Number of words displayed per line
2. Words are randomly selected from a file and displayed
3. User types words until the timer expires
4. Program:

   * Collects all displayed words
   * Collects all typed words
5. Analytics are computed
6. Results are:

   * Displayed on the terminal
   * Saved to files for later analysis

---

## 📁 Data Storage Format

### 📊 `analytics.csv`

Stores one row per session with:

```
date_time, timestamp, wpm, cpm, accuracy_words, accuracy_chars, most_mistyped_char
```

### ❌ `incorrect_words.txt`

Stores mistyped words per session in the format:

```
<date_time> word1 word2 word3 ...
```

---

## 🛠️ Technologies Used

* **C++ (C++17 standard)**
* Standard libraries:

  * `<chrono>` for timing
  * `<fstream>` for file handling
  * `<vector>`, `<string>`, `<tuple>` for data structures
  * `<random>` for word selection

---

## 🚀 How to Compile and Run

### Compile

```bash
g++ -std=c++17 -Wall -Wextra *.cpp -o typing_test
```

### Run

```bash
./typing_test
```

---

## 📌 Current Limitations

* Command-line interface only
* Blocking input (typing continues until Enter is pressed)
* No adaptive difficulty yet
* No GUI (planned for future versions)

---

## 🔮 Future Improvements (Planned)

* Adaptive word selection based on past mistakes
* Improved non-blocking input handling
* Better session analytics visualization
* GUI version
* Refactoring analytics into structured data types

---

## 📚 Learning Goals of This Project

* Understanding multi-file C++ projects
* Practicing const-correctness and references
* Learning time-based program execution
* Applying clean separation of concerns
* Handling real-world file I/O

---

## 🧑‍💻 Author

Developed as a learning project to strengthen **C++ programming**, **software design**, and **problem-solving skills**.

---
## 🤖 AI Assistance Disclosure

AI tools were used only for **code review and design feedback**, not for writing code.  
All implementation, debugging, and integration were done manually by the author.


