Individual Reflection
=====================

Imperial Login : pvk16

Group Name : wayneluk

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

> I suggested that we use method A to build the test-bench, as I
> thought it would have benefit B. While it worked well enough,
> in future I might choose to do C, because D. 

There is no "right" answer, and there is no particular
requirement on how "big" each thing is, either in concept
size or the number of words. There is also no bias towards
whether a strength or weakness is better - either could be
relevant. The only requirements are that the answers should be:

- Specific to you

- Specific to this coursework

- Be some sort of genuine reflection on your practice

- Related to the specific topic

This will be assessed, and is not just a tick box exercise.

Submission
----------

This should be submitted individually via blackboard (not
via the group repo).

Group working
-------------

Jordan and I have worked together before on different projects and work quite 
well together. We knew what the other was working on and had regular contact 
with each other. We worked quite efficiently, overcoming challenges.
We did not follow agile development techniques as there were 
only 2 people working on this project and the overhead would slow us down.

There were times during the project, where communication had 
broken down. For example, I had a fix for a bug in my local changes and had not 
communicated that with Jordan, which meant that Jordan spent time fixing a bug, 
that was already fixed (commit hash - 6da7f728).

In the future, I would incorporate reviewing each other's commits before they 
are pushed to master so that we can quickly identify bugs.

Time management
---------------

Our group was quite well organized. I set aside an entire weekend 
before the formative to focus on this project and try to finish as much of the project.
We worked together and helped each other with our blockers and were able to 
implement the basic structure of the project and get most of the basic functions implemented. 

I did underestimate how long the project would take as the weekend was not enough
and it was quite difficult to find a long period of time to work together on the project.
So we set goals and organized time to meet each other to discuss the project, 
help with any blockers we had. This approach was quite successful, as we met our 
goals that we set and were able to finish implementing all the functions 
and have tests for them well before the deadline. This meant that we could spend 
the time checking functionality and adding more tests.


Software skills (e.g. debugging, design, coding)
------------------------------------------------

We initially started out with quite a complex design, having abstract classes and 
void function pointers which were unnecessary to what we were trying to achieve. 
So we simplified our design to get the opcode and call the relevant functions. 

We initially had everything in the CPU class but it was getting cluttered so we 
decided to refactor out any memory related functionality to it's own class which 
helped with readability and with debugging.

One of the improvements I would make to our design is to replace our current single 
execute cycle with a fetch, decode, execute cycle. This will remove all the code 
duplication of the increment pc.

Another improvement I would make, is to write tests before coding any of the functions. 
By doing so, we didn't have to waste time debugging our code (commit hash - d39f6135).


Tools and Infrastructure (e.g. OS, automation, ...)
---------------------------------------------------

Jordan and I have different Operating systems. We initially thought that it 
would fine but we quickly ran into problems with binaries. So we decided to 
set up a virtual machine with Ubuntu 16.04 (same as the testing service). 

One thing we realized was that python was not available by default on the 
test machines, so we decided to use PyInstaller which packages 
python programs into standalone executables.

In the future, I would set up Continuous Integration so that we can immediately 
identify bugs as the CI pipeline would fail. This would have helped speed up 
our development process.


Understanding of computer architecture
--------------------------------------

During my first year, I built an ARM assembler and emulator. Working on this 
project was a very good refresher on the the architecture material that was 
taught during my first year.

One of the things that confused me were branch delays. When testing the 
functionality of jump, I noticed that the assembler was reordering the instructions. 
After reading about it from various resources and books, I better understood 
what branch delay slots were and the benefit of using pipelining.
