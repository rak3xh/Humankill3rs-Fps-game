# Humankill3rs-Fps-game

<img title="name" alt="Name" src="/images/HUM.PNG">
This project is an implementation for ncurses of a FPS that runs on the terminal like a Console Program!

## Controls

### Movement

- w and s -> horizontal movement
- q and e -> strafing in the vertical axis
- a and d -> rotating the player

### Exit

- Esc -> exits the game
- Enemy kills player -> exits the game

## Parameters

The most interesting parameters to modify are the global variables in the Humankillers.cpp file, "nScreenWidth" is the width of the screen; "nScreenHeight" is the height; "fSpeed" is the movement speed of the character; "fStepSize" is to change the step of the ray casting, decreasing it gives better resolution; "nMapWidth" and "nMapHeight" are the width and size of the map, the drawing of the map is modifieble inside the main() in the "map" string, '#' representing walls and '.' representing blank space.

## Compiling and Executing

For this project to work, you will need the ncurses library (libncurses5-dev) and to give the flag "-lncursesw" to the compiler. Like in the exemple of compiling and running bellow:

```bash
g++ -o Humankillers Humankillers.cpp -allegro5./Humankillers
```

You will probably need to resize your terminal font-size or window-size to match the program nScreenWidth and nScreenHeight, alternatively, you can change the value of these variables in the Humankillers.cpp file. Also, depending on your terminal emulator speed, you will have to change the fSpeed variable so it plays nicely on your terminal.

## ScreenShots

<img title="main" alt="Main-Menu" src="/images/MAIN.PNG">
<img title="New-game" alt="New-Game" src="/images/NEW.PNG">
<img title="pause" alt="Pause" src="/images/PAUSE.PNG">
<img title="game" alt="Enemy & HUD" src="/images/ENEMY.PNG">
