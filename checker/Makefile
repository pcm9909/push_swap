all :
	make re -C ../utils/utils/get_next_line
	make re -C ../utils/utils/libft
	cc -g -fsanitize=address -o checker *.c ../utils/*.c ../utils/func/*.c  ../utils/utils/libft/libft.a ../utils/utils/get_next_line/get_next_line.a
