ifndef ROOT 
 ROOT := ../..
 include $(ROOT)/Makefile
endif

AUX_DIR = $(ROOT)/tests/libaux
AUX_SRCS := $(wildcard $(AUX_DIR)/*.c)
AUX_OBJS := $(patsubst %.c,%.o,$(AUX_SRCS))

.PHONY : libaux
libaux : $(LIBS_L)/libaux.a $(OUT_DIR_H)/libaux.h

$(OUT_DIR_H)/libaux.h : $(AUX_DIR)/aux.h
	sed \
		-e'4s@\($(NAME)\.h\)   @lib\1@' \
		-e'13s@ @ LIB@' \
		-e'14s@\( define \)@\1LIB@' \
		$(AUX_DIR)/aux.h > \
		$(OUT_DIR_H)/libaux.h

$(OUT_DIR_LIB)/$(LIBNAME).a : $(AUX_OBJS)
	-ar rcs $@ $^


#specific file dependencies:

#compilation :
$(AUX_DIR)/%.o : $(AUX_DIR)/%.c
	$(CC) $(CFLAGS)\
		-I $(LIBS_I)\
		-I $(INC_DIR)\
		-o $@ -c $<
