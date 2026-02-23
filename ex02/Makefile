NAME :=

CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98 -pedantic -I includes
RMDIR := rm -rf

SRCS_DIR := src
INCLUDES_DIR := includes
OBJ_DIR := obj

SRCS := $(SRC_DIR)/Bureaucrat.cpp \
				$(SRC_DIR)/Form.cpp \
				$(SRC_DIR)/PresidentialPardonForm.cpp
				$(SRC_DIR)/RobotomyRequestForm.cpp
				$(SRC_DIR)/ShrubberyCreationForm.cpp
				$(SRC_DIR)/main.cpp

OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RMDIR) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
