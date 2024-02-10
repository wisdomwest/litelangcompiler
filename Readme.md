Building a language to do fizzbuzz

## The Basics of a Compiler's Job

The job of a compiler is to translate input in one language (usually
a high-level language) into a different output language (usually a
lower-level language than the input). The main steps are:

![](Figs/parsing_steps.png)

 + Do [lexical analysis](https://en.wikipedia.org/wiki/Lexical_analysis)
to recognise the lexical elements. In several languages, `=` is different
to `==`, so you can't just read a single `=`. We call these lexical
elements *tokens*.
 + [Parse](https://en.wikipedia.org/wiki/Parsing) the input, i.e. recognise
the syntax and structural elements of the input and ensure that they
conform to the *grammar* of the language. For example, your language
might have this decision-making

## LLC features
I added statements to the language, specifiacally "print".
Usage:

```
   print 2 + 6 * 5;
   print 18 - 18/3 + 10*2;
```

Each statement starts with the keyword `print` and is terminated with a semicolon. I have borrowed some ideas from the SubC compiler written by Nils M Holm. His code can be found online including a very awesome book

## Resources

There's a lot of compiler resources out on the Internet. Here are the ones
I'll be looking at.

### Learning Resources

If you want to start with some books, papers and tools on compilers,
I'd highly recommend this list:

  + [Curated list of awesome resources on Compilers, Interpreters and Runtimes](https://github.com/aalhour/awesome-compilers) by Ahmad Alhour

### Existing Compilers

While I'm going to build my own compiler, I plan on looking at other compilers:
  + [SubC](http://www.t3x.org/subc/) by Nils M Holm
  + [Swieros C Compiler](https://github.com/rswier/swieros/blob/master/root/bin/c.c) by Robert Swierczek
  + [fbcc](https://github.com/DoctorWkt/fbcc) by Fabrice Bellard
  + [tcc](https://bellard.org/tcc/), also by Fabrice Bellard and others
  + [catc](https://github.com/yui0/catc) by Yuichiro Nakada
  + [amacc](https://github.com/jserv/amacc) by Jim Huang
  + [Small C](https://en.wikipedia.org/wiki/Small-C) by Ron Cain,
    James E. Hendrix, derivatives by others

## Setting Up the Development Environment

```
  $ sudo apt-get install build-essential
```

install nasm for the asm code.

## Trying It Out

The language is very simple, but here try it out:
```
$ make
$ make test
```

## What's Next

Adding loops, variables and if statments. The goal really is to do fizzbuzz in my language
