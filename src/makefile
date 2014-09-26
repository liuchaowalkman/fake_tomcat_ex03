

target_dir:=../bin
target:=$(target_dir)/main.exe


SRCS        += $(wildcard *.cpp)  
OBJS_DIR    :=../obj
SRC_DIR    :=.
OBJS        := $(SRCS:.cpp=.o)  



OBJS_fullpath := $(addprefix $(OBJS_DIR)/, $(OBJS))

#vpath %.cpp ../src/

all:$(OBJS_fullpath)
	g++ $(OBJS_fullpath)  -o $(target) 

$(OBJS_DIR)/%.o:%.cpp
	g++ -c  $< -o $@









.PHONY:clean
clean:
	-rm  -rf  $(OBJS_fullpath) $(target)
