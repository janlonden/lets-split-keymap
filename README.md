# lets-split-keymap

## find keyboard port

ls /dev/tty*

## erase flash

sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -e

## flash eeprom

sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U eeprom:w:../../.build/eeprom-righthand.eep

## flash

sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:../../.build/lets_split_rev2_jan.hex
