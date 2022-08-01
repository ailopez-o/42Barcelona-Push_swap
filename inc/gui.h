int	key_press(int key, void *param);
int	terminate_program(void *param);
int	draw_line(t_meta *meta, t_point start, t_point end);
int	my_putpixel(t_meta *meta, t_point pixel);
int	generate_background(t_meta *meta, int backcolor);
int	draw_bar(t_meta *meta, t_point start, t_point end, int with);
int	draw_stack_a(t_meta *meta);
int	draw_stack_b(t_meta *meta);
int draw_push_swap(t_meta *meta);