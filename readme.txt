Tiny Digital Invader - 7-segment display

## Description
Tiny Digital Invader is Casio MG-880 Calculator(1980) game clone.
This game use only 8 * 7-segment display.


Original Video.(another contributor)
https://www.youtube.com/watch?v=taunkRbE3eE


## Installation
Request : Arduino IDE 1.8.x

1. download from github
2. pls edit test.bat(windows) or test.sh(osx) for your computer.
   or use Arduboy Manager, Arduboy Game Loader.


## Rule
total stage : 18(2 part * 9 pattern)

1 pattern   : 16 enemys, 30 bullets, 3 hit points.

UFO("n")    : destory number of total % 10 == 0.
              if you destory 2 3 5, next enemy is UFO.

score       : near is too low.
              1 part - 10 20 30 40 50 60(6 digits)
              2 part - 20 40 60 80 100(5 digits)
              UFO +300

game over   : 0 hit point or 0 bullets


## Controls
Left : select
B    : fire


## Development
compiler        : windows Arduino IDE 1.8.0(avr-gcc) + 1.0.6(make.exe)
image converter : python 2.6 + Pillow
etc             : Visual Studio 2015 C#


## Todo
sound function


## History
v1.00 2016/12/24    first version


## License
GNU General Public License


Arduboy 1.0 infomation.

AVR Memory Usage
----------------
Device: atmega32u4

Program:   13484 bytes (41.1% Full)
(.text + .data + .bootloader)

Data:       1384 bytes (54.1% Full)
(.data + .bss + .noinit)
