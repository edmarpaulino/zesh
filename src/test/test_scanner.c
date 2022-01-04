/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_scanner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:21:24 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/04 19:32:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zesh.h"

static void	print_separation_bar(void)
{
	printf("==================================================\n");
}

static void	print_next_token(t_source *src)
{
	t_token		*tok;

	tok = tokenize(src);
	print_separation_bar();
	while (tok != &g_eof_token)
	{
		printf("token: |%s|\tsize: %d\n", tok->text, tok->text_len);
		free_token(tok);
		tok = tokenize(src);
	}
	if (tok == &g_eof_token)
		printf("end of token\n");
	print_separation_bar();
}

static void	print_source(t_source *src)
{
	print_separation_bar();
	printf("source buffer: %s\n", src->buffer);
	printf("source buffer size: %ld\n", src->buf_size);
	printf("source current position: %ld\n", src->cur_pos);
	print_separation_bar();
}

int	test_scanner(void)
{
	t_source	src;

	src.buffer = ft_strdup("ls -la | cat /etc/passwd && $(wget www.test.com)");
	if (src.buffer == NULL)
	{
		ft_putendl_fd("error: cannot create source buffer", 2);
		return (-1);
	}
	src.buf_size = ft_strlen(src.buffer);
	src.cur_pos = -1;
	print_source(&src);
	print_next_token(&src);
	print_source(&src);
	free(src.buffer);
	return (0);
}
