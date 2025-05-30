EMPTY = 
SPACE = $(EMPTY) $(EMPTY)

# Get SFML directory, ensuring it is formatted correctly in case its directory contains spaces
SFML_DIR ?=
S_DIR = $(subst $(SPACE),\$(SPACE),$(SFML_DIR))

# -------[[ BUILD CONFIGURATION ]]-------
# Assume that we are building the debug build
DEBUG ?= TRUE

# -------[[ USED DIRECTORIES ]]-------

# Add any additional include directories here
USER_INCLUDE_DIRS = -Iinclude -I$(S_DIR)/include

# Add any additional library directories
LIB_DIRS = -L$(S_DIR)/lib


# -------[[ USED LIBRARIES AND SOURCE FILES ]]-------

# Libraries used during linking
ifeq ($(DEBUG), TRUE)
	LIBS = -lsfml-graphics-s-d -lsfml-window-s-d -lsfml-audio-s-d -lsfml-system-s-d -lGL -lX11 -lXi -lXrandr -lXcursor -lrt -lm -ludev -lopenal -lvorbis -logg -lvorbisenc -lFLAC -lvorbisfile -lfreetype
else
	LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s
endif

# Add any additional source files to here
SRCS =	Framework_Managers/AudioManager.cpp Framework_Managers/FontManager.cpp Framework_Managers/InputManager.cpp Framework_Managers/TextureManager.cpp Framework_Managers/SaveManager.cpp \
		Gamestate_Operators/Static/HitboxManager.cpp Gamestate_Operators/Static/LevelManager.cpp Gamestate_Operators/Static/MapManager.cpp Gamestate_Operators/Static/PlayerManager.cpp Gamestate_Operators/Static/ScoreManager.cpp \
		Gamestate_Operators/Instanced/PauseMenuOperator.cpp \
		Gamestate_Operators/Instanced/TitleScreenActorOperator.cpp \
		Gamestate_Operators/Instanced/EndingCutsceneActorOperator.cpp \
		Gamestate_Operators/Instanced/GameOverTextOperator.cpp \
		Enemy.cpp EnemyManager.cpp  \
		BirdEnemy.cpp DogEnemy.cpp DogEnemy2.cpp RatEnemy.cpp \
		Player.cpp NPC.cpp \
		Gamestates/PlayMainGameState.cpp Gamestates/PauseGameState.cpp Gamestates/TitleScreenGameState.cpp Gamestates/EndingCutsceneGameState.cpp Gamestates/GameOverGameState.cpp \
		Entry.cpp

# Prepend src/ to the source files and create list of object files
SRCS := $(addprefix src/, $(SRCS))
OBJS = $(SRCS:src/%.cpp=obj/%.o)


# -------[[ BUILD FLAGS ]]-------

ifeq ($(DEBUG), TRUE)
	CXX_FLAGS_BASE = -Wall -Wextra -Werror -g -Og -std=c++20 -DDEBUG
else
	CXX_FLAGS_BASE = -Wall -Wextra -Werror -O3 -std=c++20 -DNDEBUG
endif

CXX_FLAGS = $(CXX_FLAGS_BASE) \
$(LIB_DIRS) \
$(LIBS) \
$(USER_INCLUDE_DIRS)



# -------[[ TARGETS & RULES ]]-------

.DEFAULT_GOAL := all

all: $(OBJS) Project

Project: $(OBJS)
	@mkdir -p bin
	@echo "\nLinking final executable $@...\n"
	@$(CXX) $(OBJS) $(CXX_FLAGS) -o bin/$@
	@echo "\nInstalling assets to binary directory...\n"
	@cp -r assets bin
	@echo "\n\nDONE!!\n\n"

$(OBJS): obj/%.o: src/%.cpp
	@echo "\nBuilding translation unit for $<...\n"
	@mkdir -p $(dir $(OBJS))
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -rf obj
	rm -rf bin
