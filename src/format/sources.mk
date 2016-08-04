MAIN	:= conversion_formatting.c precision.c flag.c alternate_form.c positive_number.c zero_padding.c minimum_field.c\

OBJ	:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRFORMAT)/%.c $(HEAD)
	$(COMPIL)
