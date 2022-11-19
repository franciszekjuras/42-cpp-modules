NAME = zombie

CLASES = \
	Zombie

HFILES := $(CLASES:%=%.hpp)

FILES := $(CLASES)

FILES += \
	main newZombie randomChump

OFILES := $(FILES:%=%.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
OPTIM = -ggdb3
LIBS=

all: $(NAME)

$(NAME): $(OFILES)
	g++ $(OFILES) $(LIBS) -o $@

$(OFILES): %.o: %.cpp $(HFILES)
	g++ $(CPPFLAGS) $(OPTIM) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
