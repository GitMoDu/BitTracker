## BitTracker
Bit wise, memory efficient tracker.

Example running:



Bit Tracker Example
Bit Tracker 8 
Clear all: [0 0 0 0 0 0 0 0]
Set all pending: [1 1 1 1 1 1 1 1]
Reading 8 bits took 5 us per bit.
Writing 8 bits took 6 us per bit.
Random clear walk...
[1 1 1 1 1 1 1 1]
[1 1 1 1 1 1 0 1]
[1 1 0 1 1 1 0 1]
[1 0 0 1 1 1 0 1]
[1 0 0 1 1 0 0 1]
[1 0 0 1 1 0 0 0]
[1 0 0 0 1 0 0 0]
[0 0 0 0 1 0 0 0]
[0 0 0 0 0 0 0 0]
... done.

Bit Tracker 16
Clear all: [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
Set all pending: [1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
Reading 16 bits took 5 us per bit.
Writing 16 bits took 6 us per bit.
Random clear walk...
[1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
[1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1]
[0 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1]
[0 1 1 1 1 1 1 1 0 1 1 1 1 0 1 1]
[0 1 1 0 1 1 1 1 0 1 1 1 1 0 1 1]
[0 1 0 0 1 1 1 1 0 1 1 1 1 0 1 1]
[0 1 0 0 1 1 1 1 0 0 1 1 1 0 1 1]
[0 1 0 0 1 1 1 1 0 0 1 1 0 0 1 1]
[0 0 0 0 1 1 1 1 0 0 1 1 0 0 1 1]
[0 0 0 0 1 1 1 1 0 0 1 1 0 0 0 1]
[0 0 0 0 1 1 1 0 0 0 1 1 0 0 0 1]
[0 0 0 0 0 1 1 0 0 0 1 1 0 0 0 1]
[0 0 0 0 0 1 1 0 0 0 1 0 0 0 0 1]
[0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1]
[0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0]
[0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0]
[0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
... done.

Bit Tracker 32
Clear all: [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
Set all pending: [1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
Reading 32 bits took 5 us per bit.
Writing 32 bits took 6 us per bit.
Random clear walk...
[1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1]
[1 1 0 1 1 1 1 1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1]
[1 1 0 1 1 1 1 1 0 1 0 0 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1]
[1 1 0 1 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1]
[1 1 0 1 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 1 1 1 0 1 0 1 1 1 1 1 1 1]
[1 1 0 1 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 1 1 1 0 1 0 1 1 0 1 1 1 1]
[1 1 0 1 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 1 1 1 0 1 0 1 1 0 1 1 0 1]
[1 1 0 1 1 1 1 1 0 1 0 0 1 1 1 0 1 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1]
[1 1 0 1 1 1 1 1 0 1 0 0 1 1 1 0 1 1 0 1 0 1 0 1 0 1 1 0 1 1 0 1]
[1 1 0 1 1 1 1 1 0 1 0 0 1 1 1 0 1 1 0 1 0 1 0 0 0 1 1 0 1 1 0 1]
[1 1 0 1 1 1 1 1 0 1 0 0 1 1 1 0 1 1 0 1 0 1 0 0 0 1 1 0 0 1 0 1]
[1 1 0 1 1 1 1 1 0 1 0 0 1 1 0 0 1 1 0 1 0 1 0 0 0 1 1 0 0 1 0 1]
[1 1 0 1 1 1 1 0 0 1 0 0 1 1 0 0 1 1 0 1 0 1 0 0 0 1 1 0 0 1 0 1]
[1 1 0 1 1 1 1 0 0 1 0 0 1 1 0 0 1 1 0 0 0 1 0 0 0 1 1 0 0 1 0 1]
[1 0 0 1 1 1 1 0 0 1 0 0 1 1 0 0 1 1 0 0 0 1 0 0 0 1 1 0 0 1 0 1]
[1 0 0 1 1 1 1 0 0 1 0 0 1 1 0 0 1 1 0 0 0 1 0 0 0 1 0 0 0 1 0 1]
[1 0 0 1 1 1 1 0 0 1 0 0 1 1 0 0 1 1 0 0 0 0 0 0 0 1 0 0 0 1 0 1]
[1 0 0 1 1 1 1 0 0 1 0 0 1 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 1]
[1 0 0 1 1 1 1 0 0 0 0 0 1 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 1]
[1 0 0 1 1 1 1 0 0 0 0 0 1 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0]
[1 0 0 1 1 1 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0]
[1 0 0 0 1 1 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0]
[1 0 0 0 1 1 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0]
[1 0 0 0 1 1 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0]
[1 0 0 0 1 1 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[1 0 0 0 0 1 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[1 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
... done.

Bit Tracker 64
Clear all: [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
Set all pending: [1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
Reading 64 bits took 5 us per bit.
Writing 64 bits took 6 us per bit.
Random clear walk...
[1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
[1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
[1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
[1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
[1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0 0 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
[1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0 0 1 1 1 1 1 1 1 1 1 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0 0 1 1 1 1 1 1 1 1 1 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0 0 1 1 1 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0 0 1 1 1 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0 0 1 1 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1 1 1 0 1 1 1 1 1 1 0 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 0 0 1 1 1 1 1 0 0 1 1 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1 1 1 0 1 1 1 1 1 1 0 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 1 1 0 0 1 1 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1 1 1 0 1 1 1 1 1 1 0 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0 1 0 1 0 0 1 1 1 1 1 0 0 1 1 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1 1 1 0 1 1 1 1 1 1 0 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1 0 1 0 0 1 1 1 1 1 0 0 1 1 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1 1 1 0 1 1 1 1 1 1 0 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1 0 1 0 0 1 1 1 1 1 0 0 1 1 0 1 1 1 1 1 1 0 0 1 1 1 1 0 0 1 1 1 0 1 1 1 1 1 1 0 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1 0 1 0 0 1 1 1 0 1 0 0 1 1 0 1 1 1 1 1 1 0 0 1 1 1 1 0 0 1 1 1 0 1 1 1 1 1 1 0 1 1 1 1]
[1 1 0 1 1 1 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1 0 1 0 0 1 1 1 0 1 0 0 1 1 0 0 1 1 1 1 1 0 0 1 1 1 1 0 0 1 1 1 0 1 1 1 1 1 1 0 1 1 1 1]
[1 1 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 1 1 0 1 0 1 0 0 1 1 1 0 1 0 0 1 1 0 0 1 1 1 1 1 0 0 1 1 1 1 0 0 1 1 1 0 1 1 1 1 1 1 0 1 1 1 1]
[1 1 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 1 1 0 1 0 1 0 0 1 1 1 0 1 0 0 1 1 0 0 1 1 1 1 1 0 0 1 1 1 1 0 0 1 1 1 0 1 1 1 1 1 1 0 1 1 0 1]
[1 1 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 1 1 0 0 0 1 0 0 1 1 1 0 1 0 0 1 1 0 0 1 1 1 1 1 0 0 1 1 1 1 0 0 1 1 1 0 1 1 1 1 1 1 0 1 1 0 1]
[1 1 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 0 1 0 0 0 1 0 0 1 1 1 0 1 0 0 1 1 0 0 1 1 1 1 1 0 0 1 1 1 1 0 0 1 1 1 0 1 1 1 1 1 1 0 1 1 0 1]
[0 1 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 0 1 0 0 0 1 0 0 1 1 1 0 1 0 0 1 1 0 0 1 1 1 1 1 0 0 1 1 1 1 0 0 1 1 1 0 1 1 1 1 1 1 0 1 1 0 1]
[0 1 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 0 1 0 0 0 1 0 0 1 1 1 0 1 0 0 1 1 0 0 1 1 1 1 1 0 0 1 1 1 1 0 0 1 1 1 0 1 1 0 1 1 1 0 1 1 0 1]
[0 1 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 0 1 0 0 0 1 0 0 1 1 1 0 1 0 0 1 1 0 0 1 1 1 1 1 0 0 1 0 1 1 0 0 1 1 1 0 1 1 0 1 1 1 0 1 1 0 1]
[0 1 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 0 1 0 0 0 1 0 0 1 1 1 0 1 0 0 1 0 0 0 1 1 1 1 1 0 0 1 0 1 1 0 0 1 1 1 0 1 1 0 1 1 1 0 1 1 0 1]
[0 1 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 0 1 0 0 0 1 0 0 1 1 1 0 1 0 0 1 0 0 0 1 1 1 1 1 0 0 1 0 1 1 0 0 1 1 1 0 1 0 0 1 1 1 0 1 1 0 1]
[0 1 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 0 1 0 0 0 1 0 0 1 1 1 0 1 0 0 1 0 0 0 1 1 1 1 1 0 0 1 0 1 1 0 0 0 1 1 0 1 0 0 1 1 1 0 1 1 0 1]
[0 1 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 0 1 0 0 0 1 0 0 1 1 0 0 1 0 0 1 0 0 0 1 1 1 1 1 0 0 1 0 1 1 0 0 0 1 1 0 1 0 0 1 1 1 0 1 1 0 1]
[0 0 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 0 1 0 0 0 1 0 0 1 1 0 0 1 0 0 1 0 0 0 1 1 1 1 1 0 0 1 0 1 1 0 0 0 1 1 0 1 0 0 1 1 1 0 1 1 0 1]
[0 0 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 0 1 0 0 0 1 0 0 1 1 0 0 1 0 0 1 0 0 0 1 1 1 1 1 0 0 1 0 1 1 0 0 0 1 1 0 1 0 0 1 1 0 0 1 1 0 1]
[0 0 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 0 1 0 0 0 1 0 0 1 1 0 0 1 0 0 1 0 0 0 1 1 1 1 1 0 0 1 0 1 1 0 0 0 1 1 0 1 0 0 1 1 0 0 1 1 0 0]
[0 0 0 1 1 1 1 1 0 1 1 1 0 0 1 1 1 0 1 0 0 0 1 0 0 1 1 0 0 1 0 0 1 0 0 0 1 1 1 1 0 0 0 1 0 1 1 0 0 0 1 1 0 1 0 0 1 1 0 0 1 1 0 0]
[0 0 0 1 1 1 1 1 0 1 1 1 0 0 1 1 0 0 1 0 0 0 1 0 0 1 1 0 0 1 0 0 1 0 0 0 1 1 1 1 0 0 0 1 0 1 1 0 0 0 1 1 0 1 0 0 1 1 0 0 1 1 0 0]
[0 0 0 1 1 1 1 1 0 1 1 1 0 0 1 1 0 0 1 0 0 0 1 0 0 1 1 0 0 1 0 0 1 0 0 0 1 1 1 1 0 0 0 1 0 1 1 0 0 0 1 1 0 1 0 0 0 1 0 0 1 1 0 0]
[0 0 0 1 1 1 1 1 0 1 1 1 0 0 1 1 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 1 0 0 0 1 1 1 1 0 0 0 1 0 1 1 0 0 0 1 1 0 1 0 0 0 1 0 0 1 1 0 0]
[0 0 0 1 1 1 1 1 0 1 1 1 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 1 0 0 0 1 1 1 1 0 0 0 1 0 1 1 0 0 0 1 1 0 1 0 0 0 1 0 0 1 1 0 0]
[0 0 0 1 1 1 1 1 0 1 1 1 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 1 0 0 0 1 1 1 1 0 0 0 1 0 1 0 0 0 0 1 1 0 1 0 0 0 1 0 0 1 1 0 0]
[0 0 0 1 1 1 1 1 0 1 1 1 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 1 0 0 0 1 1 1 1 0 0 0 1 0 1 0 0 0 0 1 1 0 1 0 0 0 0 0 0 1 1 0 0]
[0 0 0 0 1 1 1 1 0 1 1 1 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 1 0 0 0 1 1 1 1 0 0 0 1 0 1 0 0 0 0 1 1 0 1 0 0 0 0 0 0 1 1 0 0]
[0 0 0 0 1 1 1 0 0 1 1 1 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 1 0 0 0 1 1 1 1 0 0 0 1 0 1 0 0 0 0 1 1 0 1 0 0 0 0 0 0 1 1 0 0]
[0 0 0 0 1 1 1 0 0 1 1 1 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 1 0 0 0 0 1 1 1 0 0 0 1 0 1 0 0 0 0 1 1 0 1 0 0 0 0 0 0 1 1 0 0]
[0 0 0 0 1 1 1 0 0 1 1 1 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 1 0 0 0 0 1 1 0 0 0 0 1 0 1 0 0 0 0 1 1 0 1 0 0 0 0 0 0 1 1 0 0]
[0 0 0 0 1 1 1 0 0 1 1 1 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 1 0 0 0 0 1 1 0 1 0 0 0 0 0 0 1 1 0 0]
[0 0 0 0 1 1 1 0 0 1 1 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 1 0 0 0 0 1 1 0 1 0 0 0 0 0 0 1 1 0 0]
[0 0 0 0 1 1 1 0 0 1 1 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 1 1 0 0]
[0 0 0 0 1 1 1 0 0 1 1 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 0 0]
[0 0 0 0 1 0 1 0 0 1 1 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 0 0]
[0 0 0 0 1 0 1 0 0 1 1 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 0 0]
[0 0 0 0 1 0 1 0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 0 0]
[0 0 0 0 1 0 1 0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 0 0]
[0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 0 0]
[0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0]
[0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0]
[0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0]
[0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0]
[0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0]
[0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0]
[0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
... done.

Bit Tracker 128 with only 10 used bits
Clear all: [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
Set all pending: [1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
Reading 128 bits took 5 us per bit.
Writing 128 bits took 3 us per bit.
Random clear walk...
[1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[1 1 1 1 1 1 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[1 1 0 1 1 1 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[1 1 0 1 1 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[1 1 0 1 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[1 1 0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 1 0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
[0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
... done.


Bit Tracker Test Complete
