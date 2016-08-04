MAIN	:= conversion_s.c conversion_c.c modulo.c conversion_o.c \
			conversion_u.c conversion_x.c conversion_di.c

OBJ	:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRCONVERSION)/%.c $(HEAD)
	$(COMPIL)
