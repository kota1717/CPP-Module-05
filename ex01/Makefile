TARGET := sign_form
OBJ_DIR := obj

CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98
RMDIR := rm -rf

SRCS := Bureaucrat.cpp \
				Form.cpp \
				main.cpp

OBJS := $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RMDIR) $(OBJ_DIR)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=reachable --track-origins=yes ./$(TARGET)

.PHONY: all clean fclean re valgrind
