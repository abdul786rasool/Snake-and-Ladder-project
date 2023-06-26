# Snake-and-Ladder-project
I have created a code that enables finding the path with the fewest number of moves, or dice rolls, required to reach the target square in the game. By using this code, you can determine the optimal sequence of moves to take in order to reach the target square in the shortest amount of time. This allows for efficient navigation through the game board and maximizes the chances of winning.
Snake and Ladder Game:
-----------------------
The Snake and Ladder Game is a classic board game where players aim to reach the final position on the board by rolling a dice and moving their game piece accordingly. The board consists of numbered squares from 1 to 100. The game includes various attributes associated with certain squares, which add excitement and unpredictability to the gameplay. 

The main attributes in the game are:

1)Ladders (L): Ladders allow players to climb up to a higher-numbered square in a single move. When a player lands on a square with a ladder Ln, they immediately move to the higher-numbered square n, skipping the squares in between.

2)Snakes (S): Snakes are obstacles in the game that bring players down to a lower-numbered square. When a player lands on a square with a snake Sn, they slide down to the lower-numbered square n, bypassing the squares in between.

3)Move Restrictions (R): Move restrictions impose limitations on the possible moves a player can make from a particular square. The attribute Rn denotes that players can make any move except n. It restricts the player from making a specific move, adding a strategic element to the game.

4)Special Moves (M): Special moves allow players to make only a specific move from a square. The attribute Mn indicates that players can only make a move of size n from that square. This adds additional challenges and decision-making to the gameplay.

Code Description:
------------------
The provided code implements the Snake and Ladder Game using Dijkstra's Algorithm. It includes the following main components:

1.Game Initialization: The code initializes the game by setting up the game board, represented by the game_box vector. Each element in the vector corresponds to a square on the board and contains an attribute. Ladders are denoted by Ln, snakes by Sn, move restrictions by Rn, and special moves by Mn.

2.Input Generation: The code randomly generates attributes for a random number of squares on the board. The attributes include ladders (L), snakes (S), move restrictions (R), and special moves (M). These attributes are stored in the game_box vector, associating them with the respective squares. For simplicity square 1 and 100 not given any attribute.The print_input function is used to display the attributes of the game.

3.Intution of using graphs:The game board is represented as a graph, where each square is a node with its own attributes. Rolling the dice and moving to an adjacent square is treated as an edge in the graph, and the edge weight is set to 1 for regular moves. However, when encountering a snake or ladder, the player can directly move to a different square without rolling the dice, making the edge weight 0.The adjacent function returns a vector of pairs representing the adjacent nodes and their edge weights based on the attributes of the current node. In this way, the graph captures the movement and attributes of the game, allowing us to apply graph algorithms such as Dijkstra's algorithm to find the shortest path from the start to the finish.

4.Dijkstra's Algorithm:The snake_ladder function implements Dijkstra's algorithm to find the shortest path from the start (node 1) to the finish (node 100).The algorithm maintains a distance vector to store the minimum distance from the start node to each node, and a parent vector to track the path.The algorithm uses a priority queue to process the nodes in order of their distances.

5.Game Execution: The code executes the game by calling the snake_ladder function. It generates a valid random attribute configuration, calculates the minimum moves using the Dijkstra's algorithm, and prints the result. In a valid attribute configuration , each square is assigned to atmost one attribute.

6.Output and Path Calculation: The code displays the minimum number of moves required to reach square 100 and prints the path taken. It iterates through the board, considering ladder and snake attributes, and selects the next square based on the minimum moves from the current position. There may be multiple paths with minimum no of moves but code prints only one of the path.



