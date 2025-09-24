NAME := test_crc32
TEST_SUBJ := ../libcrc32.a

CFLAGS := -Wall -Wextra -Werror -O3 -MP -MMD

BUILD := ./build/
SRCS := test_crc32.c
OBJS := $(SRCS:.c=.o)
OBJS := $(addprefix $(BUILD), $(OBJS))
DEPS := $(OBJS:.o=.d)

all: $(NAME)
$(NAME): $(OBJS) $(TEST_SUBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(TEST_SUBJ)
$(TEST_SUBJ):
	@$(MAKE) -C .. all


$(BUILD)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(TEST_SUBJ)
