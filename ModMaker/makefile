APPNAME = modmaker

CXXFLAGS = -O2 -g -Wall

OBJS = mm.o
OBJS += modbuilder.o

all: $(APPNAME)
	@echo Excellent

$(APPNAME): $(OBJS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

