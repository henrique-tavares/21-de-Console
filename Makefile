# Nome do projeto
NOME_PROJ=21-De-Console

# Compilador
CC=gcc

# Flags para o compilador
CC_FLAGS=-W -Wall

# arquivos .c
C_SOURCE=$(wildcard ./src/*.c)

# arquivos .h
H_SOURCE=$(wildcard ./headers/*.h)

# arquivos objeto (.o)
OBJ=$(subst .c, .o,$(subst src, build, $(C_SOURCE)))

# Compilação
all: $(NOME_PROJ)

$(NOME_PROJ): $(OBJ)
	@ echo 'Compilando o binário final: $@'
	$(CC) -o ./$(NOME_PROJ) $^
	@ echo 'Compilação concluída: $@'
	@ echo ' '

./build/%.o: ./src/%.c ./src/%.h
	@ echo 'Compilando o arquivo: $<'
	$(CC) -o $@ -c $< $(CC_FLAGS)
	@ echo ' '

./build/main.o: ./src/main.c $(H_SOURCE)
	@ echo 'Compilando o arquivo: $<'
	$(CC) -o $@ -c $< $(CC_FLAGS)
	@ echo ' '

buildFolder:
	@ mkdir -p build

clean:
	@ rm -rf ./build/%.o ./$(NOME_PROJ)
	@ rmdir build
