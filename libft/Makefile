NAME := libft.a

override BUILDDIR := .build/

override OBJDIR := $(addprefix $(BUILDDIR), objs/)

override DEPDIR := $(addprefix $(BUILDDIR), deps/)

override SRCDIR := srcs/

BASENAME := ft_isalpha \
		   ft_isascii \
		   ft_isdigit \
		   ft_isprint \
		   ft_isspace \
		   ft_isalpha \
		   ft_isupper \
		   ft_toupper \
		   ft_tolower \
		   ft_isalnum \
		   ft_bzero \
		   ft_memset \
		   ft_memcpy \
		   ft_memmove \
		   ft_memcmp \
		   ft_memchr \
		   ft_strlen \
		   ft_strchr \
		   ft_strrchr \
		   ft_strncmp \
		   ft_strnstr \
		   ft_strlcpy \
		   ft_strlcat \
		   ft_calloc \
		   ft_strdup \
		   ft_atoi \
		   ft_strtol \
		   ft_substr \
		   ft_putchar_fd \
		   ft_putstr_fd \
		   ft_putendl_fd \
		   ft_putnbr_fd \
		   ft_strmapi \
		   ft_striteri \
		   ft_itoa \
		   ft_strjoin \
		   ft_strtrim \
		   ft_split \
		   ft_lstnew \
		   ft_lstadd_front \
		   ft_lstsize \
		   ft_lstlast \
		   ft_lstadd_back \
		   ft_lstdelone \
		   ft_lstclear \
		   ft_lstiter \
		   ft_lstmap \
		   ft_sqrt

override SRCS := $(addprefix $(SRCDIR), $(addsuffix .c, $(BASENAME)))

override OBJS := $(addprefix $(OBJDIR), $(addsuffix .o, $(BASENAME)))

override DEPS := $(addprefix $(DEPDIR), $(addsuffix .d, $(BASENAME)))

CC := cc

CFLAGS := -Wall -Wextra -Werror

override CPPFLAGS := -I

override INCS := ./includes

override DEPSFLAGS := -MD -MP -MF

override AR := ar

override ARFLAGS := rcs

override RM := rm -rf

override MAKEFLAGS += --no-print-directory

COMPFLAGS :=

all:
	@$(MAKE) COMPFLAGS="$(COMPFLAGS)" $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo ""
	@echo "libft.a created."

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCS) $(DEPSFLAGS) $(DEPDIR)$*.d -c $< -o $@ ${COMPFLAGS}

$(OBJDIR) $(DEPDIR):
	mkdir -p $@

clean:
	$(RM) $(BUILDDIR)

fclean: clean
	$(RM) $(NAME) $(SONAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
