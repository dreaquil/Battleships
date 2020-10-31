# Battleships

Battleships game server. Uses "CRUD" service (UserService) built with Oat++.

## Rules for BattleShip (a Milton Bradley Game)

### Game Objective
The object of Battleship is to try and sink all the other player's ships before they sink all of
yours. All the other player's ships are somewhere on his/her board. You try and hit them by
calling out the coordinates of one of the squares on the board. The other player also tries to
hit your ships by calling out coordinates. Neither you nor the other player can see the other's
board so you must try to guess where they are. Each board in the physical game has two grids:
the lower (horizontal) section for the player's ships and the upper part (vertical during play)
for recording the player's guesses.
Starting a New Game
Each player places the 5 ships somewhere on their board. The ships can only be placed
vertically or horizontally. Diagonal placement is not allowed. No part of a ship may hang off
the edge of the board. Ships may not overlap each other. No ships may be placed on another
ship.
Once the guessing begins, the players may not move the ships.
The 5 ships are: Carrier (occupies 5 spaces), Battleship (4), Cruiser (3), Submarine (3), and
Destroyer (2).

### Playing the Game
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

---

### Endpoints 

#### HTML

|HTTP Method|URL|Description|
|---|---|---|
|`GET`|http://localhost:8000/ | Root page |
|`GET`|http://localhost:8000/swagger/ui | Swagger UI page |

#### User Service

|HTTP Method|URL|Description|
|---|---|---|
|`POST`|http://localhost:8000/users | Create new User |
|`PUT`|http://localhost:8000/users/{userId} | Update User by ID |
|`GET`|http://localhost:8000/users/{userId} | Get User by ID |
|`DELETE`|http://localhost:8000/users/{userId} | Delete User by ID |
|`GET`|http://localhost:8000/users/offset/{offset}/limit/{limit} | Get All Users with Paging |
