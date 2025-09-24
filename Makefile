NAME := libcrc32.a

CFLAGS := -Wall -Wextra -Werror -O3 -MP -MMD

BUILD := ./build/
SRCS := libcrc32.c
OBJS := $(SRCS:.c=.o)
OBJS := $(addprefix $(BUILD), $(OBJS))
DEPS := $(OBJS:.o=.d)

all: $(NAME)
$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

$(BUILD)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

test:
	@$(MAKE) -C tests all
	./tests/test_crc32

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
