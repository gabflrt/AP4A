CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

SRCS = Scheduler.cpp Server.cpp Sensors.cpp Sensor.cpp  main.cpp
OBJ_DIR = objets
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))
EXEC = simulateur

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

$(OBJ_DIR)/%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /S /Q objets\\*.o