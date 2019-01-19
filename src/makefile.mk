GKRELLM_OBJ += src/main.o \
               src/IMonitorModule.o \
               src/IMonitorDisplay.o \
               src/Monitor.o

$(eval $(call target_bin,ft_gkrellm,GKRELLM_OBJ,GKRELLM_BIN))
$(GKRELLM_BIN): INCLUDE += src
$(GKRELLM_BIN): LDLIBS  += ncurses
