/*
 * PROJECT
 *
 * ~Julia and Mandelbrot
 * ~Infinite Zoom
 * ~Able to take command line args to disipline
 * 		which fractal render
 * ~Able to take command line args to shape Julia, i.e x y coordinates
 * ~ESC closes the process with no leaks
 * ~Click on the X window, closes the process leaks free
 *
 * * 🚨 Code has to be norminetted 🚨
 * 		~there are comments everywhere for clarity
 * 		~i go always on the next line to better see the function inputs
 * 		tldr->Don't git clone and push.

*/

#include "fractol.h"
#include "minilibx-linux/mlx.h"

/*
 * I HAVE 2 KINDA PROMPTS
 * 		~./fractol mandelbrot
 * 		~./fractol julia <real> <i>
 *
 * 	The main function is a TL,DR
 * 	of your application
 *
*/
int	main(int ac, char **av)
{
	t_fractal	fractal;


	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)
		|| 4 == ac && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		//TL;DR
		//Prompt correct, kick off the application
		//1)
		fractal_init(&fractal);
		//2)
		fractal_render(&fractal);
		//3)
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
