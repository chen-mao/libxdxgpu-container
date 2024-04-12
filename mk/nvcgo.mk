include $(MAKE_DIR)/common.mk

##### Source definitions #####

PREFIX         := nvcgo
SRCS_DIR       := $(DEPS_DIR)/src/$(PREFIX)
VERSION        := $(VERSION)

##### Public rules #####

.PHONY: all install clean

build:
	$(RM) -rf $(SRCS_DIR)
	$(CP) -R $(CURDIR)/src/$(PREFIX) $(SRCS_DIR)
	$(MAKE) -C $(SRCS_DIR) VERSION=$(VERSION) clean
	$(MAKE) -C $(SRCS_DIR) VERSION=$(VERSION) build

install: build
	$(MAKE) -C $(SRCS_DIR) install DESTDIR=$(DESTDIR)

clean:
	$(MAKE) -C $(SRCS_DIR) clean
