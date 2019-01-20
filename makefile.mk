# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#              #
#    Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq (,$(OUTLIB_DIR))
  $(error Must precise OUTLIB_DIR)
endif

INCLUDE += $(HOME)/.brew/include
LDDIRS  += $(HOME)/.brew/lib

include ext/makefile.mk
include src/makefile.mk
