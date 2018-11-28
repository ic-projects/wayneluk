Individual Reflection
=====================

Imperial Login : js4416

Group Name : WayneLuk

Guidance
--------

The aim is to get you to think about specific things that you
have learnt, or things that went well or less well. For each
of the areas identified below, write (at most) 100 words on how
well that area went. Examples of things that you might address
are:

- Some kind of concept or approach that became clearer

- A skill or tool that you found useful

- Identifying where some choices were poor

- A change in approach that improved your solution

- Changes in strategy that could help in future projects



You should identify things specific to you and this coursework,
not just general things, and link them to specific features or
activities of the coursework. In some cases you may want to refer
to classes, functions, or source files in your submission,
and/or highlight specific commits (e.g. by hash) in order to
show changes.

For example, these is quite generic and doesn't tell us anything:

> I learnt how to use classes more effectively.

> I hadn't used the command line much before, and now have got used to it.

Whereas these are more specific (don't use these as a template, you
have to word):

> Originally I wasn't sure how to map part A of the simulator into
> structs, so I originally thought about mapping each B to an
> struct. However, this turned out to be the wrong approach
> because C, so we ended up using D.

> I suggested that we use method A to build the testbench, as I
> thought it would have benefit B. While it worked well enough,
> in future I might choose to do C, because D.

There is no "right" answer, and there is no particular
requirement on how "big" each thing is, either in concept
size or the number of words. There is also no bias towards
whether a strength or weakness is better - either could be
relevant. The only requirements are that the answers should be:

- Specific to you

- Specific to this coursework

- Be some sort of genuine reflection on your practise

- Related to the specific topic

This will be assessed, and is not just a tick box exercise.

Submission
----------

This should be submitted individually via blackboard (not
via the group repo).

Group working
-------------

In previous group assignments, we have always worked in groups of at least 4.
In those groups, we needed feature branches in Git to avoid conflicts.
We discovered this was overkill for a pair, since
conflicts were rare, so we pushed directly to `master`.

What became more important was making sure that I knew what Pranav was doing and vice versa.
E.g. at one point, Pranav had a bugfix (6da7f7) for J and JAL in his local repo,
but didn't push it. This slowed us down, as I discovered the same bug when writing tests
and fixed it again myself. More frequent communication and pushing of code would have
resolved this.

Time management
---------------

I think our group's time management skills were good. We agreed to set
aside a full weekend *before the formative* to complete a significant
chunk of the project - aiming to set up the infrastructure for the
simulator and testbench, and support basic instructions.

This approach was successful.
Development was quick, as we were together and had no other distractions,
meaning we could concentrate fully and provide help when we were blocked.
Being able to discuss ideas and collaborate easily also improved our design.

One thing that I would improve in the future would be to write tests earlier,
using them to guide development of the simulator, i.e. following TDD. This might
have allowed us to spot the branch delay issue earlier, saving us from having to
rewrite as much code.

Software skills (e.g. debugging, design, coding)
------------------------------------------------

Our original design was too complex. We had an `Instruction` class, with an abstract
`execute(CPU)` method, and three implementations (J/I/R). However,
in order to execute an instruction, you need access to registers and memory.
It was cleaner and made more sense to have one `execute(Instruction)` method for `CPU`
than different `execute()` methods for `Instruction`s.

We minimised duplication by extracting common functionality into methods,
but some code, such as mapping opcodes to instructions, was repetitive.
We auto-generated these parts, which worked well.
With hindsight, I would also write some code to auto-generate tests
based on patterns and tables of inputs, rather than writing sources by hand.
I would also do this earlier, as tests were the best way to find bugs.

Tools and Infrastructure (e.g. OS, automation, ...)
---------------------------------------------------

My machine runs Ubuntu 18.04 and Pranav's runs OSX.
The different `gcc` versions caused inconsistent builds,
so we both moved to virtualised installations of Ubuntu 16.04.

I used CLion, which provides refactoring and debugging tools which
were really useful.
However, CLion uses `cmake` by default. We switched from `make` to `cmake`
which was a good idea: `cmake` config was easier to update, and could be run
directly from the IDE. And a short script made it just as easy to use in a terminal.

I would use CI in future projects to check that we don't push commits that
break existing functionality (e.g. 0e3f15, which fixed some tests but broke others).

Understanding of computer architecture
--------------------------------------

The one thing that really tripped us up was branch delays:
we were somewhat confused when the MIPS assembler was
re-ordering our branch instructions. This led us to read up on pipelining in MIPS,
giving us a better understanding on how pipelined datapaths work, compared
to the single-cycle datapath that we had seen in lectures.

Having written an ARM emulator in first year, the importance of a simple ISA,
with a few common formats became clearer to me.

I also discovered, when assembling tests, how useful pseudo-instructions are
for making programs easy to write without having to implement many instructions.
