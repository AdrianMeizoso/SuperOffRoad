# Super Off Road

This is my tribute to Super Off Road, first released for arcade in 1989. This is a version of the Sega Genesis Console.

## PROJECT INFORMATION

Full project at github: [https://github.com/AdrianMeizoso/SuperOffRoad](https://github.com/AdrianMeizoso/SuperOffRoad) 

*Author*: Adrián Meizoso

Contact: adrian.meizoso@est.fib.upc.edu

License: GNU GENERAL PUBLIC LICENSE

## Gameplay video
You can find a little example of the gameplay below:
<iframe width="560" height="315" src="https://www.youtube.com/embed/9s7Z5lA8xJE" frameborder="0" allowfullscreen></iframe>

Also you can see it in the next link: [https://youtu.be/9s7Z5lA8xJE](https://youtu.be/9s7Z5lA8xJE)

Currently the game include one circuit of the original version. There are other 3 cars that compete against you in order to finish the laps. There are some effects like dust, water, flags movement, etc.

## Commands

* **NITRO:** (Player 1: C / Player 2: Ctrl Right)
* **ACCELERATE:** (Player 1: Space / Player 2: Shift right)
* **ROTATE RIGHT:** (Player 1: D / Player 2: Right Key)
* **ROTATE LEFT:** (Player 1: A / Player 2: Left Key)

## Debug mode
Pressing one of each keys you can access to differents debug modes:

* F1: Show colliders: Player, Npc and items colliders are shown in green.
Also Player and Npc road checkpoints are shown in blue.
* F3: More nitro: Pressing this button will augment your nitro in 1.

## How to Build the game:
To build the game, you just need to compile it in Visual Studio. If you want to play it inside Visual Studio, you will have to modify the Execution folder under the debug settings of the Super Off Road project, and make it point to $(SolutionDir)Game.

## How to finish the game:
When any of the car (Player and Npc) arrive to 4 laps, the game will restart again (More Circuit will be available in the future).
