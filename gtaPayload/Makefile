COMPILER := gcc
OBJCOPY	 :=	objcopy
ODIR	 :=	build
SDIR	 :=	source
IDIRS	 :=	include
LDIRS	 :=	lib
CFLAGS	 :=	-I$(IDIRS) -L$(LDIRS) -O3 -s -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-builtin -nostartfiles -nostdlib -masm=intel -march=btver2 -mtune=btver2 -m64 -mabi=sysv -mcmodel=small -fpie -fpermissive
LFLAGS	 :=	-Xlinker -T linker.x -Wl,--build-id=none
SFLAGS	 :=	-nostartfiles -nostdlib -masm=intel -march=btver2 -mtune=btver2 -m64 -mabi=sysv -mcmodel=large
CFILES	 :=	$(wildcard $(SDIR)/*.cpp)
SFILES	 :=	$(wildcard $(SDIR)/*.s)
OBJS	 :=	$(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(CFILES)) $(patsubst $(SDIR)/%.s, $(ODIR)/%.o, $(SFILES))


TARGET =  $(shell basename $(CURDIR)).bin

$(TARGET): $(ODIR) $(OBJS)
	$(COMPILER) crt0.s $(ODIR)/*.o -o temp.t $(CFLAGS) $(LFLAGS)
	$(OBJCOPY) -O binary temp.t $(TARGET)
	rm -f temp.t

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(COMPILER) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.s
	$(COMPILER) -c -o $@ $< $(SFLAGS)

$(ODIR):
	@mkdir $@

.PHONY: clean

clean:
	rm -f $(TARGET) $(ODIR)/*.o