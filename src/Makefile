TARGET = s21_brick_game
CC = gcc
SRCS = s21_brickGame.c s21_rotation.c s21_possibility_of_mov.c s21_random_figure.c s21_getchar.c s21_count_points.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) gmon.out

rebuild: clean all

.PHONY: all clean rebuild



