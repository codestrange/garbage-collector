garbage_file = garbage.txt
movement_file = movement
movement_lib = fdm.so

run: 
	./bin/main ${garbage_file} lib/${movement_lib}

compile: compile_utils_lib
	gcc src/main.c lib/utils.so src/logic_game.c -o bin/main -ldl

compile_utils_lib:
	gcc -shared -fPIC -o lib/utils.so src/utils/utils_file.c src/utils/utils_list.c src/utils/utils_matrix.c

compile_movement_funtion:
	gcc -shared -fPIC src/export/${movement_file}.c -o lib/fdm.so