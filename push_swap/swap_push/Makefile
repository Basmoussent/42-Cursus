CC := c++
CFLAGS := -Wall -Wextra -Werror -g3

INCDIR := include
SRCDIR := srcs
OBJDIR := objs
LIBFTDIR := libft
LIBFT := $(LIBFTDIR)/libft.a

TARGET := push_swap
SRC :=	$(SRCDIR)/push_swap.c \
		$(SRCDIR)/stack.c \
		$(SRCDIR)/parsing.c \
		$(SRCDIR)/data.c \
		$(SRCDIR)/action_a.c \
		$(SRCDIR)/action_b.c \
		$(SRCDIR)/data.c \
		$(SRCDIR)/utils.c \
		$(SRCDIR)/edge_case.c

OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(LIBFT) $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -o $@ $^ $(LIBFT)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(OBJDIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(TARGET)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
