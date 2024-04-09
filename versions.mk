GIT_TAG ?= $(patsubst v%,%,$(shell git describe --tags 2>/dev/null))
GIT_COMMIT ?= $(shell git describe --match="" --dirty --long --always --abbrev=40 2> /dev/null || echo "")

LIB_NAME := libxdxct-container

# Your tag must look like 1.0.0-rc.1, Dont use ~
PARTS := $(subst -, ,$(GIT_TAG))
build_start = 2
build_end = $(words $(PARTS))
ifeq ($(LIB_VERSION),)
# If LIB_VERSION is not already set we infer all versions from the git tag
auto_version = yes
LIB_VERSION ?= $(word 1,$(PARTS))
ifeq ($(LIB_TAG),)
ifneq ($(patsubst rc.%,%,$(word 2,$(PARTS))),$(word 2,$(PARTS)))
LIB_TAG = $(word 2,$(PARTS))
build_start = 3
endif
endif
endif

ifeq ($(auto_version),yes)
empty :=
space := $(empty) $(empty)
LIB_BUILD ?= $(subst $(space),.,$(strip $(wordlist $(build_start),$(build_end),$(PARTS))))
endif

VERSION_PARTS := $(subst ., ,$(LIB_VERSION))
MAJOR := $(word 1,$(VERSION_PARTS))
MINOR := $(word 2,$(VERSION_PARTS))
PATCH := $(word 3,$(VERSION_PARTS))

VERSION := $(LIB_VERSION)
TAG := $(LIB_TAG)
BUILD := $(LIB_BUILD)
# VERSION_STRING := $(LIB_VERSION)$(if $(TAG),-$(TAG),)$(if $(BUILD),+$(BUILD),)
VERSION_STRING := $(LIB_VERSION)$(if $(TAG),-$(TAG),)
