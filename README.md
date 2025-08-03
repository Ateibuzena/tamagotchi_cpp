# Tamagotchi - Virtual Pet in C++ with ncurses

Welcome to Tamagotchi! This project is a simple simulation of a virtual pet, programmed in C++ and presented with a console interface using the **ncurses** library.

## Features

- Management of three key pet attributes: **hunger**, **energy**, and **happiness**.
- Actions to interact with the pet: **feed**, **play**, and **sleep**.
- Simulation of time passing that affects the pet's state.
- Console interface with separate windows for status, menu, messages, and pet display.
- Messages and colors indicating the pet's status and events.
- The game ends if the pet dies or the user decides to quit.

## Requirements

- Compatible C++ compiler (GCC, Clang, etc).
- **ncurses** library installed on your system.
  - On Ubuntu/Debian: `sudo apt-get install libncurses5-dev libncursesw5-dev`

## How to compile

```bash
make
```
## How to run

```bash
./tamagotchi_ncurses
```

## Controls

  1 — Feed the Tamagotchi

  2 — Play with it

  3 — Put it to sleep

  4 — Let time pass without action

  q or Q — Quit the game

## Code Structure

Tamagotchi is the main class that manages the pet’s state and actions.

Uses ncurses windows to separate the interface: status, menu, messages, and pet drawing.

Controls the main loop with periodic updates and user input handling.

## Future Improvements

Add more actions and random events.

Improve the pet’s visual representation.

Save and load the game state.
