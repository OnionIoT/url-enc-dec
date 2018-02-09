BINDIR := bin

LIB := -lcurl

all: urlencode urldecode b64decode

%: %.c
	@mkdir -p $(BINDIR)
	@echo "Compiling"
	$(CC) $(CFLAGS) $(LDFLAGS) $(INC) $(LIB) -o $(BINDIR)/$@ $<

clean:
	rm -rf $(BINDIR)
