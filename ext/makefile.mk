# ------------------------------------------------------------------------------
# ImgUI
# ------------------------------------------------------------------------------

IMGUI_DIR = ext/imgui.git
$(IMGUI_DIR): CLONE_URL = https://github.com/ocornut/imgui.git
$(IMGUI_DIR): CLONE_TAG = master

IMGUI_INCLUDE := $(IMGUI_DIR)
IMGUI_OBJ += $(IMGUI_DIR)/imgui_draw.o \
             $(IMGUI_DIR)/imgui.o \
             $(IMGUI_DIR)/imgui_widgets.o

$(eval $(call target_lib,libimgui,IMGUI_OBJ,IMGUI_LIB))
$(IMGUI_DIR)/imgui_draw.cpp: $(IMGUI_DIR)
$(IMGUI_LIB): INCLUDE += $(IMGUI_INCLUDE)

# ------------------------------------------------------------------------------
# Fetching rules
# ------------------------------------------------------------------------------

ext/%.git:
	@echo "  CLONE   $(notdir $(CLONE_URL))"
	$(V)git clone --quiet --no-checkout $(CLONE_URL) $@
	$(V)cd $@ && git fetch
	$(V)cd $@ && git checkout --quiet $(CLONE_TAG)
