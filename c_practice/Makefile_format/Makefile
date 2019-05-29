SUBDIRS = call_make

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@
clean:
	$(MAKE) -C $@

.PHONY: $(SUBDIRS)
