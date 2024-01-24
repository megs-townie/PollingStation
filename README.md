# Simple Polling System in C

## Overview

This C program implements a basic polling system, designed to simulate a voting process. It features user roles like voters, polling officers, and administrators, each with different capabilities. Voters can vote for candidates, polling officers can manage candidate listings, and administrators can reset passwords.

## Features

- **User Authentication**: Login system with username and password.
- **Role-Based Access Control**: Different panels and capabilities for voters, polling officers, and administrators.
- **Voting Mechanism**: Voters can cast their votes for candidates.
- **Candidate Management**: Polling officers can add or remove candidates.
- **Admin Functions**: Admins can reset user passwords.
- **Result Declaration**: Polling officers can declare the winner based on votes.

## Installation

### Prerequisites

- A C compiler (like GCC)
- A text editor or an IDE (like Visual Studio Code or Code::Blocks)

### Steps to Compile and Run

1. Copy the provided C code into a file named `polling_system.c`.
2. Open a terminal or command prompt.
3. Navigate to the directory containing `polling_system.c`.
4. Compile the program:
   - On Linux/Mac: `gcc polling_system.c -o polling_system`
   - On Windows: `gcc polling_system.c -o polling_system.exe`
5. Run the executable:
   - On Linux/Mac: `./polling_system`
   - On Windows: `polling_system.exe`

## Usage

- **Login**: Choose the 'Login' option and enter your username and password.
- **Voter Panel**: Vote for your preferred candidate.
- **Polling Officer Panel**: Add or remove candidates, and declare the winner.
- **Admin Panel**: Reset user passwords.

## Contributing

Contributions to the Simple Polling System are welcome. Please follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b my-feature`.
3. Make your changes and commit: `git commit -am 'Add some feature'`.
4. Push to the branch: `git push origin my-feature`.
5. Submit a pull request.

## License

This project is open-sourced and free to use. Modify and distribute as you see fit.
