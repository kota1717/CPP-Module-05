NAME := bureaucrat
OBJ_DIR := obj

CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98 -pedantic
RMDIR := rm -rf

SRCS := Bureaucrat.cpp \
				main.cpp

OBJS := $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RMDIR) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
