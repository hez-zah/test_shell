#include "../../headers/minishell.h"

void	close_pip_file(t_pip *pip)
{
	if (pip->pip_in > 1)
		close(pip->pip_in);
	if (pip->pip_out > 1)
		close(pip->pip_out);
}

void	close_file(t_pip *pip)
{
	if (pip->access)
		close(pip->herd_in);
	else if (pip->pip_infile > 0)
		close(pip->pip_infile);
	if (pip->pip_outfile != 1)
		close(pip->pip_outfile);
}