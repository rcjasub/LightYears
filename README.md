# Light Years

### Introduction to the Game

A 2D spaceship game where you play as the hero and defeats the evil.
This game is written in ```C++``` and the following:
* [SFML](https://www.sfml-dev.org/) 
* [Box2D](https://box2d.org/)


The Game Support Windows, MacOS, and Linux.


### How to Build
The project uses ```cmake``` to configure the project and dependencies. Make sure your system have ```cmake``` and ```gcc/g++``` installed:
|Build Tools          |Version|
|---------------------|------|
|cmake version:       |3.27.7|
|C++ version:         |C++ 14|
|Generator:           |Ninja | 

The build process is very generic:

1, Open the folder with command prompt, and configure with cmake:
```
cmake -S . -B build -G Ninja
```
2, Build with cmake:
```
cmake --build build
```
3, open the game:
```
./build/LightYearsGame/LightYearsGame.exe