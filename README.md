#Flappybird Copyright by Tran Thanh Vinh, Student ID: 20020503 University of Engineering and Technology

I apologize in advance, my code is quite convoluted.
If and when things go wrong, Google is your best bet.
Feel free to contact me at Vinitran124@gmail.com for any questions!

Introduce Game:
- Flappy Bird was a side-scrolling mobile game featuring 2D retro style graphics.
The objective was to direct a flying bird, named "Faby", who moves continuously to the right, between sets of Mario-like pipes. 
If the player touches the pipes, they lose.
- The original version of Flappy Bird was created by Ha Dong Nguyen and was removed from the app stores on 9.2.2014.

Requirements:
- Visual Studio or Code block

Rule:
- You must left click on mouse, or use your spacebar to get started. 
Fly the bird as far as you can without hitting a pipe.

Source code:
- I use the Simple DirectMedia Layer - SDL version 2.0.14.
You can download these libraries from https://www.libsdl.org/download-2.0.php.
Also i use the random, string and time.h library. 

Some basic memberships in Game:
- Bird
- Mario-like pipe
- Base
- Background
- Transcript

Role of each programs in Game:
- Texture Manager: Use to load Texture
- Bird:
  - Provide the path of Image Birds
  - Load all images in Memory of computer 
  - Save all data of Bird as: Coordinates of x and y Bird on screen; How to Waving wings;...	
- Map: 
  - Provide the path of Image Backgrounds, Pipes and Bases
  - Load all images in Memory of computer 
  - Save all data of Map as: Position of all Mario-like pipes, Bases, Backgrounds
- Point:
  - Provide the path of Image Point
  - Load all images in Memory of computer
  - Save all data of Point as: Player scores and High Score,...
- Sound:
  - Provide the path of WAV file as: Sound Click, Sound Hit, Sound Swoosh, Sound Wing,Sound Point,...
  - Load all WAV files in Memory of computer
- List-Coordinates: Load file txt where contain data Coordinates of Photo border's Bird
- Check_collision: It take data of Position all memberships in game and Check When Bird collisions with pipe and base
- Main: 
  - Use to run all file and loop Game
  - Save all data of memberships in game as: Position, Sound,...
