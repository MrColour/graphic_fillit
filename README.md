# graphic_fillit

Graphical output of fillit! Have fun. The last part with commands was coded fast just to get the functionality
so don't break it.

1. First make the executable, git clone the repo to where you want then in that directory do `make`
2. Then you do `./fillit <file>` where file is the name of a file with tetriminos.

These will change the speed of how fast the pieces are placed. So if you want to follow along, you
can use slow.

```
-<speed>
  ./fillit -slow <file>
  ./fillit -fast <file>
```

This will use an optimization that skips redundant checks (reduces search space). They are done by
only placing a piece of the same type after another. The reasoning is that pieces of the same type
have already checked the valid places before it. 

```
-<optimization>
  ./fillit -yes <file>
  ./fillit -no <file>
```
  
I have included a global counter that displays the amount of times a piece verification is attempted.
Using the optimization we can see the amount by which the optimization reduces the search space. 

When using multiple commands please do:

`./fillit -<speed> -<optimization> <file>`

Below is a example of the program:

<br>
<img height="250" src="https://github.com/MrColour/graphic_fillit/blob/master/resources/fillit_visualizer.gif" />
<br>
