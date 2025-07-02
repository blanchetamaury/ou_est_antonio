#include "../include/include.h"

void	init_rect_wall(t_game *all)
{
    ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(0, 0, 16, 16, "block"));
}