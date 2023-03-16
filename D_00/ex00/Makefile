MCU	= atmega328p

SRC 	= main

SRCC	= main.c

BIN		= $(SRC).bin

HEX		= $(SRC).hex

CC		= avr-gcc 

F_CPU	= 200000

CFLAGS	= -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)
	
all: hex flash

# je ne mets pas l'option -c car je ne veux pas juste creer des fichiers de compilation 
hex:
	$(CC) $(CFLAGS) -o $(BIN) $(SRCC) #l'option -o permet de sauvegarder le fichier compile dans un fichier x
	avr-objcopy -O ihex $(BIN) $(HEX)
#-p donne le type de mcu -P est le port (rechercher avec un script random script -b voir sujet -U indique ce que je veux faire cest flash en ecriture 
flash: 
	avrdude -p $(MCU) -c arduino -P /dev/ttyUSB0 -b 115200 -U flash:w:$(HEX)

clean: 
	rm -f $(BIN) $(HEX)
