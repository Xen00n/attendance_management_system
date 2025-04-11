# Student Attendance Management System 📚

This is a simple **Student Attendance Management System** built entirely in **C** using **basic file handling**. It's my first ever solo project, created while I'm still in 11th grade. No advanced libraries, no frameworks — just raw C and `.txt` files!

## ✨ Features

-  Create and save student lists by Class-Section
-  Basic encryption of names and castes for privacy
-  Take daily attendance and save it with date
-  Edit, add, or remove students
-  View full student list
-  Delete entire class list
-  Password-protected access (first time asks to set a password)

## 💡 How It Works

Each class-section has its own file (e.g., `11-A.txt`) and all lists are tracked in a `detail.txt` file. When you take attendance, the result is saved in a new file like `11-A-10-04-2025.txt`.

All names and castes are **encrypted** while saving, and **decrypted** when reading.

## 🛠️ Technologies Used

- Programming Language: **C**
- File Storage: `.txt` files
- Concepts used:
  - Structures
  - Functions
  - Arrays
  - Loops and conditionals
  - Basic string manipulation
  - File I/O (`fopen`, `fscanf`, `fprintf`, `fclose`)
  - Encryption (simple Caesar cipher)

## 🏃 How to Run

1. Compile using GCC:
   ```bash
   gcc main.c -o attendance
   ```

2. Run the program:
   ```bash
   ./attendance
   ```

3. Follow the menu options!

## 📌 Notes

- This was built as a fun learning project while self-learning C in high school.
- It uses a very simple Caesar cipher (shift by 3) to encrypt names and castes.
- Password is stored in `allok.txt` and is encrypted too.


