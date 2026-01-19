# Typing Speed Tester

A commandline ""Typing Speed Tester"" written in C++ designed to measure typing performance over a fixed time duration.
The program evaluates WPM, CPM, accuracy, tracks mistyped word, and stores session analytics for future reference and analysis.
This project focuses on clean modular design, file handling, and time-based input processing using standard C++ libraries.


<img width="700" height="550" alt="image" src="https://github.com/user-attachments/assets/23338db4-b52e-4800-b8a6-a1ba31807123" />


<img width="650" height="600" alt="image" src="https://github.com/user-attachments/assets/35e0df91-8b05-4ea4-a781-8acd78ebca37" />


<img width="650" height="600" alt="image" src="https://github.com/user-attachments/assets/a49a967e-d7bf-4d0b-9443-e52e589e3857" />


<img width="650" height="450" alt="image" src="https://github.com/user-attachments/assets/c99436e4-8e42-4ab9-980b-08d10946aa4a" />


<img width="600" height="450" alt="image" src="https://github.com/user-attachments/assets/74019607-7835-45df-9875-c6cc82ebd367" />


* **Core Features**
  - User selected:
    - Time duration
    - Difficulty
    - No of words to be diplayed per line

  - Time-based typing test
    - Random word display
    - User input tracking (until timer expires)
    
  - Analytics computation
    - Words Per Minute (WPM- Raw and net)
    - Characters Per Minute (CPM - Raw and net)
    - Word accuracy( in %)
    - Character accuracy (in %)
    - Incorrect words tracking
  
  - Persistent storage
    - Session analytics stored in CSV format
    - Incorrect words stored in a text file

  - Leaderboard Display
    - Displays the top N wpm typing sessions for the respective difficulty

* **Project Structure**
  - main.cpp (Program flow, timing logic, and session control)
  - input_output.h / input_output.cpp  (User interaction and display logic)
  - timer.h / timer.cpp (handles time related logic)
  - analytics.h / analytics.cpp (Typing performance calculations)
  - file_handler.h / file_handler.cpp (File I/O for reading words and storing session data and displaying leaderboard)

  -  (stores session analytics in csv file)
  - speed_type_tester_incorrect_words.txt (Stores the mistyped words in txt file)

  - Word source files for typing tests:
    - easy_words.txt
    - medium words.txt
    - hard_words.txt
    - ultrahard_words.txt

  - README.md


* ** Data Storage Format **

  - speed_type_tester_analytics.csv
    Stores one row per session with the following :
    ```
    date_time,timestamp,difficulty_level,net_wpm,raw_wpm,net_cpm,raw_cpm,accuracy_words,accuracy_chars
    ```

  - incorrect_words.txt
    Stores mistyped words per session in the format :
    ```
    <date_time> word1 word2 word3 ...
    ```


* **C++ Concepts used(C++17 standard)**:
  * <iostream> for input- output
  * <chrono> for timing
  * <fstream> for file handling
  * <vector>, <string>, <tuple> for data structures
  * Usage of <struct>
  * <random> for word selection


* **Learning Experience**
  * Understanding multi-file C++ projects
  * Practicing const-correctness and references
  * Learning time-based program execution
  * Applying clean separation of concerns
  * Handling real-world file I-O
  * Defensive programmming 
  * Design choices for robusteness and scalability

* **Future Improvements**
  - Adaptive word selection based on past mistakes
  - Further data analysis and live improvement  feedback
  - Improved non-blocking input handling
  - Better session analytics visualization
  - GUI version
  - Refactoring analytics into structured data types
  - Additional features - stroring the most mistyped character

