NAME = phonebook

FILES = \
	main PhoneBook Contact

OFILES = $(FILES:%=%.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
OPTIM = -ggdb3
LIBS=

all: $(NAME)

$(NAME): $(OFILES)
	g++ $(OFILES) $(LIBS) -o $@

$(OFILES): %.o: %.cpp
	g++ $(CPPFLAGS) $(OPTIM) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
