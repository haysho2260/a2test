# Define the names of all the binaries we want created
ALL=fs_simulator
# Tell make what to build if we just type `make`
all: $(ALL)


# The name before the : is the name of the rule, this should be the file created
# The files after the colon are the dependencies, Make will compare the
#   timestamps of the depedencies and the rule to determine if it needs to rebuild
# The things on the following lines are the actions to take to build the file
# $@ is the meta character that means "name of the rule"
# $^ is the meta character that means "all of the dependencies"
fs_simulator: fs_simulator.c find_dir.c init_sim.c ls.c uint32_to_str.c cd.c file_path.c touch.c make.c mkdir.c
	gcc -o $@ $^ -Wall

