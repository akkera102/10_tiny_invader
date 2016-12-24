@echo off
set PATH="C:\Program Files (x86)\Arduino\hardware\tools\avr\bin";%PATH%
SET CONFFILE="C:/Program Files (x86)/Arduino/hardware/tools/avr/etc/avrdude.conf"


:loop
del test.*
make
if exist test.hex goto usb

:miss
pause
cls
goto loop

:usb
..\tool\reset COM3
avrdude -C%CONFFILE% -v -patmega32u4 -cavr109 -PCOM4 -b57600 -D -Uflash:w:test.hex:i
avr-size test.elf -C --mcu=atmega32u4

pause
cls
goto loop
