GO ?= go
RM ?= rm
MKDIR ?= mkdir
INSTALL ?= install

DESTDIR ?=
VERSION ?= devel
MAJOR   ?= 1

PKG_NAME := nvcgo

LIB_NAME    ?= libxdxct-container-go
LIB_SHARED  ?= $(LIB_NAME).so.$(VERSION)
LIB_SONAME  ?= $(LIB_NAME).so.$(MAJOR)

OBJ_NAME := $(LIB_NAME).so
HDR_NAME := $(LIB_NAME).h
CTYPES_H := ctypes.h

CGO_CFLAGS  := -std=gnu11 -O2
CGO_LDFLAGS := -Wl,--gc-sections -Wl,-s -Wl,-soname,$(LIB_SONAME)

build: $(OBJ_NAME)

$(OBJ_NAME): $(wildcard $(CURDIR)/*.go) $(wildcard */*.go)
	export CGO_CFLAGS="$(CGO_CFLAGS)"; \
	export CGO_LDFLAGS="$(CGO_LDFLAGS)"; \
	$(GO) build -o $(@) -ldflags "-s -w" -buildmode=c-shared .

install: $(OBJ_NAME)
	$(INSTALL) -d -m 755 $(addprefix $(DESTDIR),$(libdir) $(includedir)/$(PKG_NAME))
	$(INSTALL) -m 755 $(OBJ_NAME) $(DESTDIR)$(libdir)/$(LIB_SHARED)
	$(INSTALL) -m 644 $(HDR_NAME) $(DESTDIR)$(includedir)/$(PKG_NAME)/$(PKG_NAME).h
	$(INSTALL) -m 644 $(CTYPES_H) $(DESTDIR)$(includedir)/$(PKG_NAME)/$(CTYPES_H)

clean:
	$(RM) -f $(OBJ_NAME) $(HDR_NAME)

.PHONY: build clean install
