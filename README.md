# filler

In this game, two players fight each other. They play one after the other.

• The goal is to collect as many points as possible by placing the highest number of
pieces on the the game board.

• The board is defined by X columns and N lines, it will then become X*N cells.

• At the beginning of each turn, you will receive your game piece.

• A game piece is defined by X columns and N lines, so it will be X*N cells. Inside
each game piece, will be included a shape of one or many cells.

• To be able to place a piece on the board, it is mandatory that one, and only one
cell of the shape (in your piece) covers the cell of a shape placed previously (your
territory).

• The shape must not exceed the dimensions of the board

• When the game starts, the board already contains one shape.

• The game stops at the first error: either when a game piece cannot be placed
anymore or it has been wrongly placed.


Example:

$>./filler_vm -p1 user1 -p2 user2 -v -f samples/w1.flr

$$$ exec p1 : [user1]

$$$ exec p2 : [user2]

Plateau 14 30:

012345678901234567890123456789

000 ..............................

001 ..............................

002 ..............................

003 ..............................

004 ......X.......................

005 ..............................

006 ..............................

007 ..........................O...

008 ..............................

009 ..............................

010 ..............................

011 ..............................

012 ..............................

013 ..............................

Piece 3 6:

.****.

**....

*.....

<got (O) : [7 24] (7,24)
