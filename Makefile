NAME := fdf

BONUSNAME := fdf_bonus

override SRCDIR := srcs/

override BONUSSRCDIR := $(addprefix bonus/, $(SRCDIR))

override BUILDDIR := .build/

override BONUSBUILDDIR := $(addprefix bonus/, $(BUILDDIR))

override OBJDIR := $(addprefix $(BUILDDIR), objs/)

override BONUSOBJDIR := $(addprefix bonus/, $(OBJDIR))

override DEPDIR := $(addprefix $(BUILDDIR), deps/)

override BONUSDEPDIR := $(addprefix bonus/, $(DEPDIR))

BASENAME := main parsing parsing_utils get_next_line_utils get_next_line \
			memory_utils rendering mlx_utils hook

BONUSBASENAME := main parsing pipex error_utils fcntl_utils memory_utils \
				 get_next_line get_next_line_utils heredoc

override SRCS := $(addprefix $(SRCDIR), $(addsuffix .c, $(BASENAME)))

override BONUSSRCS := $(addprefix $(BONUSSRCDIR), $(addsuffix .c, $(BONUSBASENAME)))

override OBJS := $(addprefix $(OBJDIR), $(addsuffix .o, $(BASENAME)))

override BONUSOBJS := $(addprefix $(BONUSOBJDIR), $(addsuffix .o, $(BONUSBASENAME)))

override DEPS := $(addprefix $(DEPDIR), $(addsuffix .d, $(BASENAME)))

override BONUSDEPS := $(addprefix $(BONUSDEPDIR), $(addsuffix .d, $(BONUSBASENAME)))

MLXDIR := minilibx-linux/

MLX := $(addsuffix libmlx, $(MLXDIR))

override LIBFT := libft/libft.a

override LDFLAGS := -lft -lm -lXext -lX11 -lz -lmlx

override LDLIBS := -L libft/ -L$(MLXDIR)

CC := cc

CFLAGS := -Wall -Wextra -Werror

CPPFLAGS := -Iincludes -Ilibft/includes -I$(MLXDIR)

DEPSFLAGS := -MD -MP -MF

LIBFLAGS := -lft

COMPFLAGS :=

MAKEFLAGS += --no-print-directory

.DEFAULT_GOAL = all

-include $(DEPS)

.PHONY: all
all:
	@$(MAKE) COMPFLAGS="$(COMPFLAGS)" $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CLAGS) $(CPPFLAGS) $(OBJS) $(LDLIBS) $(LDFLAGS) -o $(NAME) $(COMPFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(BUILDDIR) $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) $(DEPDIR)$*.d -c $< -o $@ $(COMPFLAGS)

$(LIBFT): force
	@$(MAKE) COMPFLAGS="$(COMPFLAGS)" -C libft/

$(MLX): force
	@$(MAKE) -C $(MLXDIR)

.PHONY: force
force:

-include $(BONUSDEPS)

.PHONY: bonus
bonus:
	@$(MAKE) $(BONUSNAME) INCS="bonus/$(INCS)"

$(BONUSNAME): $(BONUSOBJS) $(LIBFT)
	$(CC) $(CLAGS) $(CPPFLAGS) $(BONUSOBJS) $(LDLIBS) $(LDFLAGS) -o $(BONUSNAME) -g3

$(BONUSOBJDIR)%.o: $(BONUSSRCDIR)%.c | $(BONUSBUILDDIR) $(BONUSOBJDIR) $(BONUSDEPDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) $(BONUSDEPDIR)$*.d -c $< -o $@ -g3

$(BUILDDIR) $(OBJDIR) $(DEPDIR) $(BONUSBUILDDIR) $(BONUSDEPDIR) $(BONUSOBJDIR):
	mkdir -p $@

.PHONY: clean
clean:
	@$(MAKE) clean -C libft/
	rm -rf $(BUILDDIR)

.PHONY: bonusclean
bonusclean:
	@$(MAKE) clean -C libft/
	rm -rf $(BONUSBUILDDIR)

.PHONY: fclean
fclean: clean
	@$(MAKE) fclean -C libft/
	rm -f $(NAME)

.PHONY: bonusfclean
bonusfclean: bonusclean
	@$(MAKE) fclean -C libft/
	rm -f $(BONUSNAME)

.PHONY: re
re: fclean all
