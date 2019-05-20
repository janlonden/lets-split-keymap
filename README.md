# lets-split-keymap

## flash

run `sudo make lets_split/rev2:jan:avrdude` from qmk-firmware root folder.

## clean build folder

run `make clean`

## Problems

Problem: `avrdude: error: programmer did not respond to command: set addr`
Solution: `systemctl stop ModemManager.service`

## old stuff

~~ls /dev/tty*~~
~~sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -e~~
~~sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U eeprom:w:../../.build/eeprom-righthand.eep~~
~~sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:../../.build/lets_split_rev2_jan.hex~~
