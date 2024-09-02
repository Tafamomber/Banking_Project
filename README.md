# Banking_Project

# Banking_Project

## Description
Banking_Project is a simple C-based command-line program designed for users to interact with their bank accounts. The program requires users to enter a user number and PIN to gain access to their account. After successful authentication, users can choose to check their balance, deposit money, or withdraw money.

## Features
- **User Authentication:** Users must enter a correct user number and PIN to access their account. The program allows up to three PIN attempts before terminating.
- **Basic Banking Operations:** Once logged in, users can choose to view their balance, deposit money, or withdraw money.
- **Error Handling:** The program handles incorrect user numbers and PINs, ensuring unauthorized access is prevented.

## How to Use

1. **Compile the Program:**
   Use a C compiler like `gcc` to compile the program:
   ```bash
   gcc -o banking_project banking_project.c -lm
