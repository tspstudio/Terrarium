TARGET=main

CC=g++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC_FOLDER=src/
BUILD_FOLDER=build/

SRC=$(wildcard $(SRC_FOLDER)*.cpp)
OBJ=$(patsubst $(SRC_FOLDER)%.cpp, $(BUILD_FOLDER)%.o, $(SRC))

.PHONY: install upload

$(TARGET): $(OBJ)
	@echo "---> Finishing building project..."
	@echo "---> Building $(OBJ) int $(TARGET)"
	@$(CC) $(OBJ) -o $(TARGET) $(CFLAGS)
	@echo "---> Finished building project!"
	@echo "---> Doing some cleanup..."
	@rm $(BUILD_FOLDER)*
	@echo "---> Running compiled project..."
	@./$(TARGET)
	

$(BUILD_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	@echo "---> Building $< into $@"
	@$(CC) -c $< -o $@ $(CFLAGS)

install:
	@echo "---> Updating apt lists..."
	@sudo apt update
	@echo "---> Installing deps"
	@sudo apt install libsfml-dev
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