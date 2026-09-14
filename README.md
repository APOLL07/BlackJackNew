# BlackJack

![C++](https://img.shields.io/badge/C%2B%2B-console%20application-00599C?logo=cplusplus&logoColor=white)
![Visual Studio](https://img.shields.io/badge/Visual%20Studio-2022-5C2D91?logo=visualstudio&logoColor=white)
![Platform](https://img.shields.io/badge/platform-Windows-0078D4?logo=windows&logoColor=white)

A console-based Blackjack game written in C++ for one player against an automated dealer. The game supports chip betting, hitting, standing, doubling down, splitting pairs, and persistent player statistics.

## Features

- Play against an automated dealer
- Place bets in multiples of 5 chips
- Hit, stand, double down, or split a pair
- Play two separate hands after a split
- Automatic dealer draw until 17 points
- Dynamic Ace scoring as either 11 or 1
- Track wins, losses, draws, and completed games
- Track Blackjacks, highest chip balance, and hand-size records
- Save the player's balance and statistics between sessions

## Implemented Rules

- A new player starts with **20 chips**.
- A bet cannot exceed the current balance and must be a multiple of 5.
- The dealer draws cards while the dealer's score is below 17.
- Jacks, Queens, and Kings are worth 10 points. An Ace is worth 11 or 1.
- A hand can be split only when its first two cards have the same rank—for example, two Sevens or two Kings.
- Double down is available immediately after the initial deal when the player has enough chips for a second bet.
- A regular win pays 1:1, while a draw returns the bet.
- When the balance falls below 10 chips, it can be restored to 20 from the balance menu.

> [!NOTE]
> In the current implementation, every card is generated independently at random. A previously dealt card can therefore appear again during the same game; cards are not removed from the deck after being dealt.

## Requirements

- Windows 10 or later
- Visual Studio 2022 with the **Desktop development with C++** workload
- MSVC Platform Toolset `v143`
- Windows 10 SDK

The project has no third-party dependencies.

## Run with Visual Studio

1. Clone the repository:

   ```bash
   git clone https://github.com/APOLL07/BlackJack.git
   cd BlackJack
   ```

2. Open `ConsoleApplication1.sln` in Visual Studio 2022.
3. Select `Debug` or `Release` and choose either the `x64` or `Win32` platform.
4. Build the project with **Build → Build Solution**.
5. Press `Ctrl+F5` to run the game.

## Build from the Developer Command Prompt

Run the following command from a Visual Studio Developer Command Prompt:

```powershell
msbuild ConsoleApplication1.sln /p:Configuration=Release /p:Platform=x64
```

After the build completes, run the generated `BlackJack.exe`. The application is designed for the Windows console and its in-game interface is displayed in Russian.

## Controls

Main menu:

| Command | Action |
| --- | --- |
| `1` | Start a new game |
| `2` | View the chip balance and refill it when available |
| `3` | View player statistics |
| `0` | Exit the application |

During a game, the console displays the actions currently available:

| Command | Action |
| --- | --- |
| `1` | Take another card |
| `2` | Double the bet, take one card, and end the turn |
| `3` | Split the starting pair into two hands |
| `0` | Stand and let the dealer play |

Commands `2` and `3` are shown only when the corresponding action is available.

## Saved Statistics

The application stores player data in `PlayerStatistic.txt` using a binary format. Despite its `.txt` extension, this file is not intended to be edited manually. It contains:

- Current and highest chip balance
- Total wins, losses, and draws
- Total games played
- Wins and losses involving Blackjack
- Wins by a one-point margin
- Maximum number of cards held in the left hand, right hand, and both hands combined

The file path is relative to the application's current working directory. If the file is deleted, the game starts with default values and creates a new statistics file the next time data is saved.

## Project Structure

```text
BlackJack/
├── ConsoleApplication1.sln
└── ConsoleApplication1/
    ├── BlackJack.cpp            # Entry point and console menu
    ├── Card.h / Card.cpp        # Card rank, suit, value, and output
    ├── Deck.h / Deck.cpp        # Random card generation
    ├── Player.h / Player.cpp    # Hands, chips, splitting, and statistics
    ├── Game.h / Game.cpp        # Dealing, dealer logic, and game results
    ├── PlayerStatistic.txt      # Persisted player data
    └── ConsoleApplication1.vcxproj
```

## Architecture

- `Card` represents a playing card and calculates its Blackjack value.
- `Deck` generates cards with standard ranks and suits.
- `Player` manages up to two hands, the chip balance, and accumulated statistics.
- `Game` contains the dealing, scoring, dealer, payout, and winner-detection logic.
- `BlackJack.cpp` connects the components through the console application's main loop.

## Current Limitations

- The application and project configuration are intended for Windows.
- The repository does not contain automated tests.
- Text input validation is minimal; menu prompts expect numeric input.
- The statistics file depends on the binary representation of `int` used by the current build.
- The source code does not currently include a license.

## Author

[APOLL07](https://github.com/APOLL07)

