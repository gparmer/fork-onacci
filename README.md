# Fork-onacci

Having fun with fork!
Or at least burning some cycles.

Today, we're going back to 1112, and mastering recursion.
Remember good 'ol fibonacci:

```haskell
fib(0) = 0
fib(1) = 1
fib(n) = fib(n - 1) + fib(n - 2)
```

If it is good enough for the golden ratio, it's good enough for a class exercise!

## Task 1

Implement `fib` in C.
I know, real hard.

## Task 2

Use `fork`, `exit`, and `wait` to calculate fib...**fibork!**
Each "call" to `fibork` should be in a new process.
You'll have to think about how `fork` works to figure out how to pass the argument.
To "return", you'll need to `exit`, and to pass the return value, the `exit` value will need to percolate to `wait`.

You can use `man` to figure out how to use these calls appropriately.

## Task 3

Change the optimization settings from `-O0` to `-O3`, and recompile (make sure to run `make clean`).
Form a *hypothesis*:

- What will happen to the performance of each implementation?
- How much will they improve?

Then execute the system.
Does it match your hypothesis?
Why or why not?

## Task 4

Remember our old friend, `objdump`?
Lets figure out why the performance changed?
Use `objdump -S` and look at your function's implementation.
If you want to more easily search through `objdump`'s output, you might consider outputting to a file (e.g., `objdump -S bin > output.txt`).
What made it faster?
