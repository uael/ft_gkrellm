# ------------------------------------------------------------------------------
# ImgUI
# ------------------------------------------------------------------------------

IMGUI_DIR = ext/imgui.git
$(IMGUI_DIR): CLONE_URL = https://github.com/uael/imgui.git
$(IMGUI_DIR): CLONE_TAG = master

IMGUI_INCLUDE := $(IMGUI_DIR) $(IMGUI_DIR)/examples
IMGUI_SRC += $(IMGUI_DIR)/imgui.cpp \
             $(IMGUI_DIR)/imgui_draw.cpp \
             $(IMGUI_DIR)/imgui_widgets.cpp \
             $(IMGUI_DIR)/examples/imgui_impl_allegro5.cpp
IMGUI_OBJ := $(patsubst %.cpp,%.o,$(IMGUI_SRC))

$(eval $(call target_lib,libimgui,IMGUI_OBJ,IMGUI_LIB))
$(IMGUI_SRC): $(IMGUI_DIR)
$(IMGUI_LIB): INCLUDE += $(IMGUI_INCLUDE)

# ------------------------------------------------------------------------------
# Fetching rules
# ------------------------------------------------------------------------------

ext/%.git:
	@echo "  CLONE   $(notdir $(CLONE_URL))"
	$(V)git clone --quiet --no-checkout $(CLONE_URL) $@
	$(V)cd $@ && git fetch
	$(V)cd $@ && git checkout --quiet $(CLONE_TAG)
