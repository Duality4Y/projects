the code based on adafruit dht11 code is buggy has leaks in it.
has to do with the arrays that are declared outside of the function.
probably a boundery problem.
placing the bits and data arrays inside the function fixes it.
because they are reinitialized everytime the function is called.
