TARGET=main

CC=g++
CFLAGS=-lSDL2 -lSDL2_ttf -lSDL2_image

SRC_FOLDER=src/
BUILD_FOLDER=build/

SRC=$(wildcard $(SRC_FOLDER)*.c)
OBJ=$(patsubst $(SRC_FOLDER)%.c, $(BUILD_FOLDER)%.o, $(SRC))

.PHONY: install upload

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
	@echo "---> Updating apt lists..."
	@sudo apt update
	@echo "---> Installing deps"
	@sudo apt install libsdl2-image-dev libsdl2-ttf-dev libsdl-ttf2.0-dev libsdl2-dev
	@echo "---> Setting up git"
	@git config --global user.name "tspstudio"
	@git config --global user.email "serhiiremeniuk@gmail.com"
	@git init
	@git remote add origin https://github.com/tspstudio/Terrarium.git
	@echo "---> All deps has been installed. Git has been configured."

upload:
	@echo "---> Git add"
	git add .
	@echo "---> Git commit"
	git commit -m "Commit via makefile"
	@echo "---> Git push"
	git push -u origin master --force
	@echo "---> Project has been uploaded to GitHub."

clean:
	@rm -rf $(TARGET) $(BUILD_FOLDER)*