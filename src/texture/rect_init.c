#include "../include/include.h"

void	init_rect_wall(t_game *all)
{
    ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(0, 0, 16, 16, "block"));
    ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(0, 0, 16, 16, "rock alone"));
    ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(0, 0, 32, 32, "antonio"));
    ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(0, 0, 1920, 1080, "bg"));
    ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(586, 302, 746, 486, "home"));
}