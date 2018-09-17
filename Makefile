.PHONY : def
def : targets
	$(MAKE) all


############
#VARIABLES :
ifndef ROOT
 ROOT := .
endif
include $(ROOT)/make_vars.mk


#######
#CORE :
include $(ROOT)/core.mk


########################
#TARGETS & DEPENDENCIES:
include $(SRC_DIR)/Makefile

#######
#LIBS :
include $(LIB_DIR)/Makefile

########
#TESTS :
include $(TEST_DIR)/Makefile


##########
#RELEASE :
.PHONY : release
release : $(RELEASE_DIR)

.PHONY : $(RELEASE_DIR)
$(RELEASE_DIR) :
	-rm -rf $@/;\
	git clone \
		--single-branch \
		-b release \
		$(GIT_REPO) \
		$@
	cd $@ && git rm -rf *
	cp $(ROOT)/auteur $@/
	mkdir $@/sources
	cp $(SRCS) $@/sources
	mkdir $@/includes
	cp $(INCS) $@/includes
	cp $(ROOT)/targets.mk $@/make_vars.mk
	cat $(ROOT)/release_vars.mk >> $@/make_vars.mk
	cp $(ROOT)/core.mk $@/Makefile
	cp $(patsubst %,$(LIBS_I)/%.h,$(DEPENDENCIES)) \
		$@/includes
	cd $(RELEASE_DIR) && \
		git add * && \
		git commit -m make_release && \
		git push
