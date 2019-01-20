# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#              #
#    Updated: 2019/01/20 17:35:10 by alucas-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

# ------------------------------------------------------------------------------
# Configuration
# ------------------------------------------------------------------------------

CXX    := clang++
LDX    := clang++
AR     := ar
CFLAGS += -std=c++98

ifeq ($(DEBUG),)
  CONFIG   = release
  CFLAGS  += -flto -O3
  LDFLAGS += -flto
  CFLAGS  += -Wall -Wextra -Werror
else
  CONFIG         = debug
  TARGET_SUFFIX  = -debug
  CFLAGS        += -g3 -O0
  ifneq ($(SAN),)
    CONFIG         = san
    TARGET_SUFFIX  = -san
    CFLAGS        += -fsanitize=address
    LDFLAGS       += -fsanitize=address
  endif
endif

BUILD_DIR  ?= build
BUILD_PATH ?= $(BUILD_DIR)/$(CONFIG)
OUTLIB_DIR ?= $(BUILD_DIR)/lib
OUTBIN_DIR ?= $(BUILD_DIR)/bin

# ------------------------------------------------------------------------------
# Sources & Target
# ------------------------------------------------------------------------------

all:

define set_define =
  $(addprefix $(BUILD_PATH)/,$(1)): DEFINE+=$(2)
endef

define set_config =
  $(addprefix $(BUILD_PATH)/,$(1)): DEFINE+=$(2)=$($(2))
endef

define target
  $(eval $(3) := $($(5))/$(1)$(TARGET_SUFFIX)$(6))
  $($(3)): $(addprefix $(BUILD_PATH)/,$($(2)))
  $(eval $(4) += $($(3)))
  $(eval OBJ += $($(2)))
  $(1): $($(3))
endef

define target_lib
  $(eval $(call target,$(1),$(2),$(3),TARGET_LIB,OUTLIB_DIR,.a))
endef

define target_bin
  $(eval $(call target,$(1),$(2),$(3),TARGET_BIN,OUTBIN_DIR,))
endef

include makefile.mk

lib: $(TARGET_LIB)
bin: $(TARGET_BIN)

all: lib bin

MAKE_DEPS := $(MAKEFILE_LIST)

# ------------------------------------------------------------------------------
# Rules
# ------------------------------------------------------------------------------

V ?= @

-include $(addprefix $(BUILD_PATH)/,$(patsubst %.o,%.d,$(OBJ)))

$(BUILD_PATH)/%.o: %.cc $(MAKE_DEPS)
	@mkdir -p $(dir $@)
	@echo "  CXX     $(notdir $<)"
	$(V)$(CXX) $< -c $(CFLAGS) $(addprefix -I,$(INCLUDE)) \
	  $(addprefix -D,$(DEFINE)) -MMD -MF $(@:.o=.d) -o $@

$(BUILD_PATH)/%.o: %.cpp $(MAKE_DEPS)
	@mkdir -p $(dir $@)
	@echo "  CXX     $(notdir $<)"
	$(V)$(CXX) $< -c $(CFLAGS) $(addprefix -I,$(INCLUDE)) \
	  $(addprefix -D,$(DEFINE)) -MMD -MF $(@:.o=.d) -o $@

$(TARGET_LIB): | $(DEPS) $(MAKE_DEPS)
	@mkdir -p $(dir $@)
	@echo "  AR      $(notdir $@)"
	$(V)$(AR) rcs $@ $^

$(TARGET_BIN): | $(DEPS) $(MAKE_DEPS)
	@mkdir -p $(dir $@)
	@echo "  LDX     $(notdir $@)"
	$(V)$(LDX) $^ $(LDFLAGS) $(addprefix -L,$(LDDIRS)) \
	  $(addprefix -l,$(LDLIBS)) -o $@
	$(V)ln -sf $@ ./$(notdir $@)

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -rf $(TARGET_LIB) $(TARGET_BIN)

re: clean all
