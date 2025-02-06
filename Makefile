# 定义变量  
CMAKE = cmake  
MAKE = make   
$(info Current directory: $(CURDIR))
INSTALL_PREFIX_BASE = $(CURDIR)




# 项目列表，按照构建顺序列出  
PROJECTS = \
    SimpleSpice 

# 每个项目所需的 CMake 选项，假设以路径形式指定  
# PROJECTB 依赖于 ProjectA 的输出，PROJECTC 依赖于 ProjectB 的输出  
#CMAKE_OPTIONS_SimpleSpice = -DCMAKE_INSTALL_PREFIX=$(INSTALL_PREFIX_BASE)/install 
	
# 创建一个构建目录  
define BUILD_PROJECT  
	@echo "Building project: $1"  
	mkdir -p build  
	cd build && $(CMAKE) .. $(CMAKE_OPTIONS_$1) -DCMAKE_BUILD_TYPE=Debug  
	cd build && $(MAKE) -j12  
endef  

.PHONY: all clean $(PROJECTS)  

# 默认目标，按顺序构建所有项目  
all: $(PROJECTS)  

# 按顺序构建每个项目  
$(PROJECTS):   
	$(call BUILD_PROJECT,$@)  



# 清理所有项目的构建文件  
clean:  
	@echo "Cleaning up all projects..."  
	for proj in $(PROJECTS); do \
		rm -rf $$proj/build; \
	done