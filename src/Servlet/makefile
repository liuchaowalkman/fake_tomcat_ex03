

target_dir:=../bin
target:=$(target_dir)/main.exe


SRCS        += $(wildcard *.cpp)  
SO_OBJS_DIR    :=../../obj/Servlet
OBJS_DIR    :=../../obj
SRC_DIR    :=.
OBJS        := $(SRCS:.cpp=.o)  
SO_DIR:=../lib
#so_fullpath_files := $(filter-out $(SO_DIR)/Servlet.so,$(addprefix $(SO_DIR)/,$(addsuffix .so, $(notdir $(basename $(SRCS))))))
so_fullpath_files := $(addprefix $(SO_DIR)/,$(addsuffix .so, $(notdir $(basename $(SRCS)))))

OBJS_fullpath := $(addprefix $(SO_OBJS_DIR)/, $(OBJS))

objs_all        := `ls $(OBJS_DIR)/*.o`   
#vpath %.cpp ../src/

    

all:$(so_fullpath_files)
	@echo "done"

$(SO_DIR)/%.so:$(SO_OBJS_DIR)/%.o $(SO_OBJS_DIR)/Servlet.o  
	@mkdir -p "$(SO_DIR)" 
	g++   -shared  $^  $(objs_all)   -o $@ 

$(SO_OBJS_DIR)/%.o:%.cpp 
	@mkdir -p "$(SO_OBJS_DIR)" 
	g++ -fPIC -I../ -c  $^ -o $@ 










.PHONY:clean
clean:
	-rm  -rf  $(OBJS_fullpath) $(so_fullpath_files)
