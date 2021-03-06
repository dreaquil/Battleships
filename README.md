# Battleships

Battleships game server built with Oat++.

## Rules for BattleShip (a Milton Bradley Game)

### Game Objective
The object of Battleship is to try and sink all the other player's ships before they sink all of
yours. All the other player's ships are somewhere on his/her board. You try and hit them by
calling out the coordinates of one of the squares on the board. The other player also tries to
hit your ships by calling out coordinates. Neither you nor the other player can see the other's
board so you must try to guess where they are. Each board in the physical game has two grids:
the lower (horizontal) section for the player's ships and the upper part (vertical during play)
for recording the player's guesses.

#### Starting a New Game
Each player places the 5 ships somewhere on their board. The ships can only be placed
vertically or horizontally. Diagonal placement is not allowed. No part of a ship may hang off
the edge of the board. Ships may not overlap each other. No ships may be placed on another
ship.
Once the guessing begins, the players may not move the ships.
The 5 ships are: Carrier (occupies 5 spaces), Battleship (4), Cruiser (3), Submarine (3), and
Destroyer (2).

#### Playing the Game
Player's take turns guessing by calling out the coordinates. The opponent responds with "hit"
or "miss" as appropriate. Both players should mark their board with pegs: red for hit, white
for miss. For example, if you call out F6 and your opponent does not have any ship located at
F6, your opponent will respond with "miss". You record the miss F6 by placing a white peg on
the lower part of your board at F6. Your opponent records the miss by placing a white peg on
the upper part of their board.
When all the squares that one of your ships occupies have been hit, the ship will be sunk. You
should announce "hit and sunk". In the physical game, a red peg is placed on the top edge of
the vertical board to indicate a sunk ship. This indicates how many ships have been sunk.
As soon as all of one player's ships have been sunk, the game ends.


## Overview

### **Notes For Assessor:** 
Still a couple of hours of work to do - that's been 4 days - it needs a little more time to complete/clean/consolidate...
- The program requires Docker, - see instructions to run a container below...
- ...otherwise - anyone who wants to run it might need to tweak the build scripts
- It's a server application - I thought a CLI wouldn't be right
- I avoided a rushed solution - the idea was to showcase maintainable extensible code albeit there's no testing
- there's gratuitous use of a framework (no injection)
- there's loads of enums for some reason?! I'm more used to numerical code - not sure if this is bad?
- I've used swagger so the api is documented and can be played with on port 8000: "localhost:8000"
- I've not tested it - I would have done a simple frontend using react but that was never gonna happen
- ... consequently it'll be buggy as anything however, the defensive checks will turn up bugs quickly

References:
- https://www.tutorialspoint.com/http/http_methods.htm

---

### Build and Run

#### Using CMake

##### Pre Requirements

- `oatpp` 
- `oatpp-swagger`
- `oatpp-sqlite` with `-DOATPP_SQLITE_AMALGAMATION=ON` cmake flag.

**Note:** You may run `utility/install-oatpp-modules.sh` script to install required oatpp modules.

##### Build Project

```
$ mkdir build
$ cd build
$ cmake ..
$ make 
$ ./battleships-exe        # - run application.
```

#### In Docker

```
$ docker build -t battleships .
$ docker run -p 8000:8000 -t battleships
```
