# 3D-Tic-Tac-Toe
<p><b>Magic Cube Generation:</b></p>
<p>•	Initialized position of 1 at (0,1,2) in a 3d array.</p> 
<p>•	An algorithm was used to enter succeeding numbers at a point by decrementing layer and column by one.</p>
<p>•	If that position is already taken by some other number, then we move it to another position by decrementing row index and incrementing column index by 1 in that particular layer</p>
<p>•	And still if that position is occupied then we take an empty position by incrementing row by 1 and layers by 2.</p>
<p>•	This process is repeated until all of the cube's positions are filled and a MagicCube is created.</p>
<p><b>Tic Tac Toe:</b></p>
<p>•	Generate a Magic Cube</p>
<p>•	Create a struct coordinate to define coordinate type</p> 
<p>•	collinearitycheck () is a utility to check if 3 points are collinear</p>
<p>•	make_2() this function finds computers next move if it does not have a possibility to form a collinear line or block the human</p>
<p>•	possWin() is a utility to find whether if a win is possible or not</p>
<p>•	scoredPoint() this utility check if the human is able to score a point</p>
<p><b>Stratergy:</b></p>
<ul type="square">
  <li>
    Used computerFirst() if computer makes the first move and use humanFirst() if human makes the first move
  </li>
  <li>
    If computer makes the first move, then it takes the centre in first move and in next move it takes a corner and so on
  </li>
  <li>
    If human makes the first move, then computer will take centre if possible else it will take a corner
  </li>
  <li>
    The computer always has a priority order, first it will try to score if it doesn’t have a chance it will try to block the human from scoring or else it will make a move according to make_2()
  </li>
  <li>
    If suppose human takes the first chance his moves are stored in HMoves() and his moves are marked in movesMade[] if human scores a point the it is added to Hscore then its computer turn if it and human made only one move each it has no possibility to win or block so it’s make a move according to make_2()  else if makes a move according to the priority order above its moves are stored in CMoves() and its moves are marked in movesMade[] if computer scores a point it is added to Cscore
  </li>
  <li>
    If suppose computer makes the first move the it always takes the centre and then it moves to corners then it moves according to the priority order first it will try to score according to possWin() else it will try to block else it will make according to make_2() its moves are stored in CMoves() and its moves are marked in movesMade[] thin in the humans turn he make moves according to his will if he scores a point it is checked by scorePoint() and is added to Hscore
  </li>
  <li>
    Finally, if Hscore is equal to 10 then the winner is human else if Cscore is equal to 10 then the winner is computer else it is a draw it is printed at the end after all the 27 moves are made and the game will end
  </li>
</ul>
</p>
