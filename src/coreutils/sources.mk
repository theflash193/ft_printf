MAIN	:= bit_display.c recovered_bit.c is_conversion.c is_flag.c \
			is_length_modifier.c set_flag.c reinitialize_flags_conversion.c \
			add_to_format.c ft_itoa_long.c ft_capitalize.c \
			ft_wtos.c ft_wtoa.c ft_itoa_base.c padding_left.c padding_right.c ft_joinclr.c\
			ft_strclean2.c

OBJ	:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRCOREUTILS)/%.c $(HEAD)
	$(COMPIL)
