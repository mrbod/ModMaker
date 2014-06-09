CXXFLAGS = -O2 -g -Wall

OBJS = mm.o
OBJS += ModMaker.o

all: $(APPNAME)

$(APPNAME): $(OBJS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

