//
// Created by Lowell Zima on 6/1/22.
//

#define ALPHA_UP 		1
#define ALPHA_DOWN 		2
#define NUM				3
#define S_QUOTE			39
#define D_QUOTE			34
#define SPACE_SEP		6
#define SPACE			32
#define B_SLASH			92
#define SLASH			47
#define S_TO_BIG		60
#define BIG_TO_S		62
#define ROUND_OPEN		40
#define ROUND_CLOSE		41
#define MONEY			36
#define SEMICOLON		59

typedef struct s_token
{
	int				id;
	char			*var;
	struct s_token	*next;
}	t_token;

typedef struct s_id
{
	char *alpha_up;				/* 	ABCDEFGHIJKLMNOPQRSTUVWXYZ 					*/
	char *alpha_down; 			/* 	abcdefghijklmnopqrstuvwxyz 					*/
	char *num;					/* 	0123456789 									*/
	char *s_quote;				/* 	' 											*/
	char *d_quote;				/* 	" 											*/
	char *space_separator;		/* 	\t \v \n \f \r 								*/
	char *space;				/* 	' ' 										*/
	char *b_slash;				/* 	\ 											*/
	char *slash;				/* 	/ 											*/
	char *s_to_big_chevron;		/* 	< 											*/
	char *big_to_s_chevron;		/* 	> 											*/
	char *round_open;			/* 	( 											*/
	char *round_close;			/* 	) 											*/
	char *dollar;				/* 	$											*/
	int	 *indexs;
}	t_id;

