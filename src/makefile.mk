GKRELLM_OBJ += src/main.o \
               src/IMonitorModule.o \
               src/IMonitorDisplay.o \
               src/DisplayModule/ImgUI.o \
               src/DisplayModule/Ncurses/Ncurses.o \
               src/MonitorModule/CPU.o \
               src/MonitorModule/Hostname.o \
               src/MonitorModule/OSInfo.o \
               src/MonitorModule/RAM.o \
               src/MonitorModule/Time.o \
               src/MonitorModule/Network.o \
               src/MonitorModule/Disk.o

$(eval $(call target_bin,ft_gkrellm,GKRELLM_OBJ,GKRELLM_BIN))
$(GKRELLM_BIN): $(IMGUI_LIB)
$(GKRELLM_BIN): INCLUDE += src $(IMGUI_INCLUDE)
$(GKRELLM_BIN): LDLIBS  += ncurses allegro allegro_primitives
