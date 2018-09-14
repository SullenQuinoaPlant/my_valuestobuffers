ifndef ROOT
	ROOT = ../..
	include $(ROOT)/make_vars.mk
endif

BUILD_DIR = cmocka_build
SOURCE_DIR = cmocka_source

cmocka : $(BUILD_DIR) $(SOURCE_DIR)
	cd $(BUILD_DIR) && cmake ../$(SOURCE_DIR) && make;
	cp $(SOURCE_DIR)/include/cmocka.h $(LIBS_I)/
	cp $(BUILD_DIR)/src/libcmocka* $(LIBS_L)/
	rm -rf $(BUILD_DIR) 
	rm -rf $(SOURCE_DIR) 

$(BUILD_DIR) :
	if ! [ -d $(BUILD_DIR) ];\
	then mkdir $(BUILD_DIR);\
	fi

$(SOURCE_DIR) :
	if [ -d $(SOURCE_DIR) ];\
	then rm -rf $(SOURCE_DIR);\
	fi
	git clone \
		--depth 1 \
		git://git.cryptomilk.org/projects/cmocka.git \
		$(SOURCE_DIR)
#hack to get buggy doxygen to shut up:
	echo "" > $(SOURCE_DIR)/doc/CMakeLists.txt
