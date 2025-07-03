
#include "../include/include.h"

void	init_texture_wall_stone(t_game *all)
{
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/stone/1stone_wall_at_the_top_left.png", all->window->renderer), "stone tl"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/stone/1stone_top_middle_wall.png", all->window->renderer), "stone tm"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/stone/1stone_top_right_wall.png", all->window->renderer), "stone tr"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/stone/1stone_wall_in_the_left_middle.png", all->window->renderer), "stone ml"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/stone/1stone_wall_in_the_right_middle.png", all->window->renderer), "stone mr"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/stone/1stone_wall_at_the_bottom_left.png", all->window->renderer), "stone bl"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/stone/1stone_bottom_middle_wall.png", all->window->renderer), "stone bm"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/stone/1stone_wall_at_the_bottom_right.png", all->window->renderer), "stone br"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/stone/1stone_wall_at_the_middle.png", all->window->renderer), "stone mm"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/add_structure/4rockalone.png", all->window->renderer), "rock alone"));
}

void	init_texture_wall_grass(t_game *all)
{
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/earth/2earth_at_the_top_left.png", all->window->renderer), "earth tl"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/earth/2earth_at_the_top_middle.png", all->window->renderer), "earth tm"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/earth/2earth_at_the_top_right.png", all->window->renderer), "earth tr"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/earth/2middle_earth_to_the_left.png", all->window->renderer), "earth ml"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/earth/2middle_earth_to_the_middle.png", all->window->renderer), "earth mm"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/earth/2middle_earth_to_the_right.png", all->window->renderer), "earth mr"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/earth/2earth_at_the_bottom_left.png", all->window->renderer), "earth bl"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/earth/2earth_bottom_middle.png", all->window->renderer), "earth bm"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/earth/2earth_at_the_bottom_right.png", all->window->renderer), "earth br"));
}

void    init_character_left(t_game  *all)
{
	t_texture   *tmp;

    tmp = malloc(sizeof(t_texture));
	tmp = NULL;
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_left/character_left_1.png", all->window->renderer), "character_l1"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_left/character_left_2.png", all->window->renderer), "character_l2"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_left/character_left_3.png", all->window->renderer), "character_l3"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_left/character_left_4.png", all->window->renderer), "character_l4"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_left/character_left_5.png", all->window->renderer), "character_l5"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_left/character_left_6.png", all->window->renderer), "character_l6"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_left/character_left_7.png", all->window->renderer), "character_l7"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_left/character_left_8.png", all->window->renderer), "character_l8"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_left/character_left_9.png", all->window->renderer), "character_l9"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_left/character_left_10.png", all->window->renderer), "character_l10"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_left/character_left_11.png", all->window->renderer), "character_l11"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_left/character_left_12.png", all->window->renderer), "character_l12"));
	all->player->animation_player_left = animation_init(all->player->animation_player_left, tmp);
}

void    init_character_right(t_game  *all)
{
	t_texture   *tmp;

    tmp = malloc(sizeof(t_texture));
	tmp = NULL;
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_right/character_right_1.png", all->window->renderer), "character_r1"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_right/character_right_2.png", all->window->renderer), "character_r2"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_right/character_right_3.png", all->window->renderer), "character_r3"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_right/character_right_4.png", all->window->renderer), "character_r4"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_right/character_right_5.png", all->window->renderer), "character_r5"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_right/character_right_6.png", all->window->renderer), "character_r6"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_right/character_right_7.png", all->window->renderer), "character_r7"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_right/character_right_8.png", all->window->renderer), "character_r8"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_right/character_right_9.png", all->window->renderer), "character_r9"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_right/character_right_10.png", all->window->renderer), "character_r10"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_right/character_right_11.png", all->window->renderer), "character_r11"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/run_right/character_right_12.png", all->window->renderer), "character_r12"));
	all->player->animation_player_right = animation_init(all->player->animation_player_right, tmp);
}

void    init_character_no_move_right(t_game  *all)
{
	t_texture   *tmp;

    tmp = malloc(sizeof(t_texture));
	tmp = NULL;
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_right/f1.png", all->window->renderer), "f1"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_right/f2.png", all->window->renderer), "f2"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_right/f3.png", all->window->renderer), "f3"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_right/f4.png", all->window->renderer), "f4"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_right/f5.png", all->window->renderer), "f5"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_right/f6.png", all->window->renderer), "f6"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_right/f7.png", all->window->renderer), "f7"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_right/f8.png", all->window->renderer), "f8"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_right/f9.png", all->window->renderer), "f9"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_right/f10.png", all->window->renderer), "f10"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_right/f11.png", all->window->renderer), "f11"));
	all->player->animation_player_no_move_right = animation_init(all->player->animation_player_no_move_right, tmp);
}

void    init_character_no_move_left(t_game  *all)
{
	t_texture   *tmp;

    tmp = malloc(sizeof(t_texture));
	tmp = NULL;
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_left/f1.png", all->window->renderer), "f1"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_left/f2.png", all->window->renderer), "f2"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_left/f3.png", all->window->renderer), "f3"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_left/f4.png", all->window->renderer), "f4"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_left/f5.png", all->window->renderer), "f5"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_left/f6.png", all->window->renderer), "f6"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_left/f7.png", all->window->renderer), "f7"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_left/f8.png", all->window->renderer), "f8"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_left/f9.png", all->window->renderer), "f9"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_left/f10.png", all->window->renderer), "f10"));
	ft_lstadd_back_texture(&tmp, ft_lstnew_texture(LoadTexture("src/texture/image/player/idle_left/f11.png", all->window->renderer), "f11"));
	all->player->animation_player_no_move_left = animation_init(all->player->animation_player_no_move_left, tmp);
}

void	init_jump(t_game	*all)
{
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("bg.png", all->window->renderer), "bg"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/home.png", all->window->renderer), "home"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/player/Jump.png", all->window->renderer), "jump"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/player/Fall.png", all->window->renderer), "fall"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("src/texture/image/player/antonio.png", all->window->renderer), "antonio"));

}
