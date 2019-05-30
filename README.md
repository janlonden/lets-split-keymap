# Lets-split-keymap

## Flash

Run `sudo make lets_split/rev2:jan:avrdude` from qmk-firmware root folder.

## Clean build folder

Run `sudo make clean`

## Problems

Problem: `avrdude: error: programmer did not respond to command: set addr`

Solution: `systemctl stop ModemManager.service`

Problem: 'avrdude: Error: butterfly programmer uses avr_write_page() but does not provide a cmd() meth' and '***failed;'

Solution: `systemctl stop ModemManager.service`
