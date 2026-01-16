.PHONY: all clean run runverb view version


PGM := main
COMPOUND := $(PGM)Compound

GENERATOR_PARAMS := test_pap_1.txt
# Packages path
PPATH := ../Packages

# Packages names
PNAMES :=Procedures FileStuff Base VirtualFunctions

BIPSOURCES := $(shell find $(PPATH) -name '*.bip')
CPPSOURCES := $(shell find $(PPATH) -name '*.cpp')
CPPOBJ := $(shell find $(PPATH) -name '*.o')
HPPSOURCES := $(shell find $(PPATH) -name '*.hpp')
PDIRS := $(foreach n, $(PNAMES),$(PPATH)/$n)

INCLUDE_BIP_PACKAGES := $(foreach n, $(PDIRS), -I $n)
INCLUDE_CPP_PACKAGES := $(foreach d, $(PDIRS), --gencpp-cc-I $d)
CPP_EXTRA_OBJ := $(foreach o, $(CPPOBJ), --gencpp-ld-extra-obj $o)


COLOR_RESET := \033[0m
COLOR_RED := \033[31m
COLOR_GREEN := \033[32m
COLOR_GOLDEN := \033[33m
COLOR_BLUE := \033[34m

# Compilation
all: output/build/system

version:
	$(COMPILER_DISTRIB_PATH)/bipc.sh --version

generator: generateMain.cpp
	g++ $< -o $@

main.bip: generator 
	./$< $(GENERATOR_PARAMS) > main.bip

# Compile $(PGM)
output/build/system: $(PGM).bip $(BIPSOURCES) $(CPPSOURCES)
	mkdir -p output/build
	$(MAKE) -C $(PPATH)
	bipc.sh -p $(PGM) -d "$(COMPOUND)()" $(INCLUDE_BIP_PACKAGES) $(INCLUDE_CPP_PACKAGES) \
		--genbip-follow-used-packages \
		--gencpp-follow-used-packages \
		$(CPP_EXTRA_OBJ)\
		--gencpp-output output
	cd output/build && cmake .. -Wno-dev
	$(MAKE) -C output/build

clean:
	@echo "$(COLOR_RED)rm -rf output$(COLOR_RESET)"
	@rm -rf output
	@rm main.bip


run: output/build/system
	@rm -f output/*.csv
	@echo "$(COLOR_BLUE)Running program...$(COLOR_RESET)"
	@./output/build/system --silent 1> output/stdout.log 2>output/stderr.log
	@echo "$(COLOR_BLUE)Running complete!$(COLOR_RESET)"

generatexmi:
	bipc.sh -p $(PGM) -d "$(COMPOUND)()" $(INCLUDE_BIP_PACKAGES) $(INCLUDE_CPP_PACKAGES) \
		--genbip-follow-used-packages \
		--profile --v FINER -so output -s xmi