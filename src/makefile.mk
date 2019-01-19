GKRELLM_OBJ += src/main.o \
               src/IMonitorModule.o \
               src/IMonitorDisplay.o \
               src/DisplayModule/ImgUI.o

$(eval $(call target_bin,ft_gkrellm,GKRELLM_OBJ,GKRELLM_BIN))
$(GKRELLM_BIN): $(IMGUI_LIB)
$(GKRELLM_BIN): INCLUDE += src $(IMGUI_INCLUDE)
$(GKRELLM_BIN): LDLIBS  += ncurses allegro allegro_primitives
