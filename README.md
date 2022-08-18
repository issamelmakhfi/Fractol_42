# Fractol_42

## Summary
The term fractal was first used by mathematician Benoit Mandelbrot in 1974. He based
it on the Latin word fractus which means "broken" or "fractured".
A fractal is an abstract mathematical object, like a curve or a surface, which pattern
remains the same at every scale.


<img align="center" src="https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjpOd2uDDC4cPG5hW5-6xlGCe6BSZGk4-IZFPypGs3KaTXG7UiqXtqfaM-74MC5BR7ju-rmSSPUDUW05NjvnYHPwU-1aDbKZvdFeJX8GnQO07qxiR5J0Js12HXXIXHniwlnikfoOHSgmAIJRzeCBbjwthkus_8ChY32bzAK_hmSwK7o4nSJbnRqo5sM/s1024/fractol.jpg">

## Functions
* Switch between fractls : Mandelbrot, Julia, Phoenix, Barnsley, Flowerbrot, Buddha.
* Increase and decrease max iteration for shape calculation.
* Zoom and unzoom.
* Different colors patterns.
* Random color patterns with random variable not using time stamp.


## Compiling and running
Run `make`. An executable will compile. Runs on OS X and Linux.

Run it with `./fractol [fractal]`. Possible fractals are: `mandelbrot`, `julia`,
`burningship`. Cycle color-schemes with `1-9` on the top row. Increase/decrease
maximum iterations with `*` and `/` on the numpad. Zoom in and out with the
mousewheel or with `+` and `-`. Press `Enter` on the numpad to switch between
smooth coloring and linear coloring.

### Installing the MLX library

* ``Linux``

If you're not using a MacOS device from 42, you'll need to install the libraries manually. Please refer to the [official github](https://github.com/42Paris/minilibx-linux) for more details. To install it, do the following (requires root access):

```shell
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux/
make
sudo cp mlx.h /usr/include
sudo cp libmlx.a /usr/lib
```

* ``MacOS``

To install the library, you will need to first install a package manager like homebrew (check [here](https://brew.sh/)) to then install the X11 package with ``brew install Xquartz``. After that you must extract the minilibx file called ``minilibx_opengl.tgz``. then install it to your system with the following commands (requires sudo as well):

```shell
cd minilibx_opengl
make
sudo cp mlx.h /usr/local/include
sudo cp libmlx.a /usr/local/lib
sudo reboot
```
Note: A reboot is necessary to ensure that the ``Xquartz`` is working properly. You can test if it is by running a test example with the command ``xeyes``.

### Installing the manuals

If you want quick access to the mlx manuals, it is recommended that you copy the files from the ``man`` folder in [minilibx-linux](https://github.com/42Paris/minilibx-linux) to your system manuals:

* ``Linux``
```shell
sudo cp man/man3/* /usr/share/man/man3/
```
Note: Depending on your Linux configuration, to get the manuals working (e.g. ``man mlx``) you will need to individually gzip all the manual files you just copied, e.g. ``sudo gzip /usr/share/man/man3/mlx.3``.

* ``MacOS``
```shell
sudo cp man/man3/* /usr/X11/share/man/man3
```


## Credits
* http://stackoverflow.com/questions/24852345/hsv-to-rgb-color-conversion
* Wikipedia : Julia Set, Mandelbrot etc.
* http://stackoverflow.com/questions/24852345/hsv-to-rgb-color-conversion
* http://csharphelper.com/blog/2014/07/draw-a-barnsley-fern-fractal-in-c
* http://flam3.com/flame_draves.pdf
* http://tigerprints.clemson.edu/cgi/viewcontent.cgi?article=2704&context=all_theses
