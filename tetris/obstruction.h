typedef struct obstruction {
	char type_str[20];
	char piece[4][4];             // 4x4 grid of characters, piece[x][y]
	int upper_left_x;
	int upper_left_y;
	char draw_char;
	char color[3];
} obstruction_t;

extern const obstruction_t obstruction_types[7];
