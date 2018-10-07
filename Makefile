args = garbage.txt pepito

run: 
	./bin/main ${args}

compile: compile_utils_lib
	gcc src/main.c lib/utils.so src/logic_game.c src/movement.c -o bin/main

compile_utils_lib:
	gcc -shared -fPIC -o lib/utils.so src/utils/utils_file.c src/utils/utils_list.c src/utils/utils_matrix.c