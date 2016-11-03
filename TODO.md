# Welcome


## Assignment Distributions
    https://docs.google.com/presentation/d/1erU0YXT62InqGgwJXr0ciD6Q4WoGCZoC-MmCXd3nF_E/edit#slide=id.p

## Pearls of wisdom for debugging
    
    [Thanks Yoda !](https://pdfs.semanticscholar.org/58b5/0c02dd0e688e0d1f630daf9afc1fe585be4c.pdf)

    * Reproduce the problem

    * Don't assume things work the way they are meant to

    * Be clear in mind about correct behaviour

    * Fix one problem at a time

    * Get your code to help you (logs)

    * Learn GDB or any debugger (MS Visual Studio, Eclipse, CodeBlocks, CodeLite)

    * Test [try automated, but also manual] - Don't forget edge cases


## Debuggigng using GDB

    * Compile with -g flag

    * run (first thing when in gdb)

    * list (show code)

    * step  (into code)

    * next  (next line) [does not step into funtions]

    * print (also p)

    * set variables (set x = 3) or (p x = 3)

    * finish (return from a function)


