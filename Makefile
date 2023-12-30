TARGET=main

CC=g++
CFLAGS=-lSDL2 -lSDL2_ttf

SRC_FOLDER=src/
BUILD_FOLDER=build/

SRC=$(wildcard $(SRC_FOLDER)*.c)
OBJ=$(patsubst $(SRC_FOLDER)%.c, $(BUILD_FOLDER)%.o, $(SRC))

.PHONY: install

$(TARGET): $(OBJ)
	@echo "---> Finishing building project..."
	@$(CC) $(OBJ) -o $(TARGET) $(CFLAGS)
	@echo "---> Finished building project!"
	@echo "---> Doing some cleanup..."
	@rm $(BUILD_FOLDER)*
	@echo "---> Running compiled project..."
	@./$(TARGET)
	

$(BUILD_FOLDER)%.o: $(SRC_FOLDER)%.c
	@echo "---> Building $< into $@"
	@$(CC) -c $< -o $@ $(CFLAGS)

install:
	sudo apt update
	sudo apt install libsdl2-image-dev libsdl2-ttf-dev libsdl-ttf2.0-dev libsdl2-dev

clean:
	@rm -rf $(TARGET) $(BUILD_FOLDER)*