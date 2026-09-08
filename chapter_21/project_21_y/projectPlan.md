
# Programm structur

## what does the programm need to do

Board things:
    - Display the game
    - check if game is in winning state
    - generate new random games


User things:
    - Get command from the user
    - validate command from user
    - allow to quit the game


---------------

Primary classes / namespace

class Board
    - Display the Board
    - hold state of the board
    - move options of the board
        - check winning state
        - check invalid moves
    - members
        - 2d array of tile

function main
    - generate new board game
    - allow user to quit

class Tile
    - Display an individual tile
    - members
        - int display number

namespace UserInput
    - get command from user
    - handle invalid input


--
Helper classes

class Point
    - indexing int x-axir and y-axis
    - maybe just use std::tuple

class Direction
    - enum direction
    - make working with directional commands easier and more intuitive

