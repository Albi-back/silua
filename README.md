new variables that were added to the lua script 
in main.cpp:
ufocounter variable, counts how many ufos are still on the screen, sets the start value in lua and is manipulated through C++
playerlaser variable, is the file adress of the player laser sprite for when the player shoots, this makes the file easily adjustable without changing the source code 
mothershipsprite variable, is the file adress of the mothership sprite, this makes the file easily adjustable without changing the source code 

mothership.cpp
m_lives variable, is the starting amount of lives that the mothership can have initially set by lua and manipulated in C
M_xpos variable, is the starting xposition of the mothership 
m_ypos variable, is the starting y position of the mothership

new luafunctions in added and suported in the lua script 

in player.cpp
right function, moves the player right after being checked by CallMoveRight function in C to check if it is valid 
left function, moves the player left after being checked bt CallMovLeft founction in C to check validity


new C funtions called by lua 

reiterated in a defferent place callMessage2 displays a different message to the original callMessage and is used in a different place


startMessage takes the flashing message at the start of the game and implements it and makes it changeable by lua at any time and the time it is displayed can me lengthened or shortened 




