CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPENSSL_PREFIX = $(shell brew --prefix openssl@3)
INCLUDES = -I$(OPENSSL_PREFIX)/include
LDFLAGS = -L$(OPENSSL_PREFIX)/lib
LIBS = -lcrypto
SRC = add_credential.c basics_functions.c free_credential.c main.c write_credential.c verif_site_format.c list_credential.c connexion.c first_connexion.c encrypted_credential.c
OBJ = $(SRC:.c=.o)
TARGET = password_manager

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.c basic_function.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

re: clean all

.PHONY: all clean re
