# Processes
- a process is a program in execution.
- a program is file containing the information of a process
    - when you start execution of the program, it is loaded into RAM and starts executing.
- each process has its own address space and (usually) one thread of control.
- Can have multiple processes executing the same program
    - BUT each process has its own copy of the program within its own address space and executes it independently of the other copies.
- processes are organized hierarchically
    - each process has a parent process which is expilcitly arranged to create it.
- the processes created by a given parent are called child processes.
    - a child imherits many of its attributes from the parent process
- system cakk is a request for service that a program makes of the kernel(the brain of operating system)
    - the service is generally something that only kernel has priviledge to do
    - sometimes called kernel calls.
- Programmers do not normally need to be concerned with system calls because there are functions in the GNU C Library to virtually everything thta system calls do
    - these functions work by making calls themselves
- each process is identified with  a unique positive called process ID (PID)
- the system call getpid() returns the process ID of the calling process
    - this call is always successful and thus no return value to indicate an error.

#include <sys/types.h>
#include <unistd.h>

pid_t getpid(void);

# Interprocess Communication
- A process can be of two types
    - Independent Process
        - not affected by the execution of other processes
        - does not interact with other programs
    - Co-operating Process
        - affected by other executing processes
        - can be used for increasing computional speed, convenience and modularity.
- what if you want to send specific data to a process or read its output?
- Interprocess Communication lets processes work together.
    - programs can be much powerful by lettting them talk to other programs on your system.
    - often referred to as IPC.
- If any process wants to communicate some information from its own address space to other processes
    - It is only possible with IPC techniques
- communication between multiple processes can be seen as a method of co-operation between them.

- Communication can be of two types
    - Between related processes initiating from only one process, such as parent and child processes.
    - Between unrelated processes, or two or more different processes.
- A process can communicate with another process in many different ways.
- Pipes (same process)
    - First process communicates with the second processes, allows flow of data in one direction only (half duplex)
- Named pipes (different processes, FIFO)
    - The first process communicate with the second process and vice versa at the same time (full duplex)
- Message Queues
    - Process will communicate with each other by posting a message and retrieving it out of a queue (full duplex)
- Shared Memory
    - Communication between 2 or more processes is achieved through shared piece of memory among all processes
- Sockets
    - Mostly used to communicate over a network between  a client and a server
- Signals
    - Communication between multiplr processes by way of signaling.
    - A source process will send a signal (recognized by a number) and the destination process will handle it accordingly.

## Pipes (named and anonymous)
- A pipe is a communication mechanism between two or more related or irrelated processes.
    - Can be either within one process or a communcation between the child and the parent processes.
- Communication can also be multi-level such as communication between a parent, the child, the grandchild, grand-grandchild and etc.
- Can be thought of filling water with the pipe in the container, say a bucket, and someone is retrieving it, say with a mug.
    - The filling process is nothing but writting in to a pipe abd reading process is nothing but retrieving from the pipe.
    - implies that one output(water) is input for other (bucket)
- Another name for a named pipe is FIFO(Fist-In-First-Out)

- system calls are used for creating and using pipes.
- Steps to utilize pipes for IPC
    1. Create a pipe
    2. Send a message to the pipe
    3. Retrieve a message from the pipe and write it to standard output.
    4. Send another message to the pipe.
    5. Retrieve the message from the pipe and write to the standard output.

## Message Queues
- All processes can exchange information through access to common system message queue.
- Message queues are a sor of mix between signals and sockets.
    - Allows to create data stream of messages which can allow one or more multiple processes to communicate between them.
    - Sending and receiving can be achieved by using a simple function.
- The sending process places a messafe(via some (OS) message parsing module) onto the queue which can be read by another process.
    - Each message is given an identification or type so that processes can select appropriate message.
    - process must share  common key in order to gain access to the queue in the first place.

- System calls are used for creating and using message queues
- Steps to perform communication using message queues
    1. the ftok() function is used to generate a unique key
    2. Create a message queue or connect to an already existing queue (msgget())
    3. Write into message queue (msgsnd())
    4. Read from message queue (msgrcv())
    5. Perform control operations on the message queue (msgctl())
## Shared Memory
- Shared memory is a memory shared between two or more processes.
- Comunication is done via this shared memory where changes can be made by one process and be viewed by another process.
- Communication between the processes requires processes to share some variable and it completely depends on how programmer will implement it.
- System calls allow to create a memory segment which can be accessed and modified by multiple resources.
    - Setting up is easy
    - Managing the given data might only be th tricky part.
- Steps to perform communication using shared memory
    1. Create the shared memory segment or use an already created shared memory segment (shmget())
    2. Attach the process to the already created shared memory segment (shmat())
    3. Detatch the process from the already attached shared memory segment(shmdt())
    4. Control operations on the shared memory segment(shmct())

## Signals
- Signals are limited form of interprocess communication (IPC), typically used in Unix like operating systems.
    - A notification to a process indicating the occurence of an event.
- Signals are a way to communicate information to a process about  a state of other processes, the operating system and hardware, so that process can take appropriate action.
- Signals are generated by the system or the user can also generate signal programmatically.
- When a signal is sent, the os interrupts the traget process' normal flow of execution to deliver the signal.
- A process can receive a particular signal asynchronously (at any time)
    - After receiving the signal, the process will interrupt its current operations
        - The process has to stop whatever it is doing and go deal with signal
            - it will either handle or ignore the signal, or in some cases terminate.
- There are fixed set of signals that can be sent to a process defined by the operating system.
- A signal is a short message which contains a single value integer.

### Examples
- When we are woekill in the shell and wish to "kill all cat programs" we type command
    - killall cat - sends a signal to all processes named cat that says "terminate."(SIGTERM)

- Signals are also used in the context of terminal signaling which is how programs stop, start or terminate
    - typing ctrl-c , same as sending SIGINT signal
    - typing ctrl-z , sames as SIGTSTP signal
    - typing fg or bg , same as SIGCONT signal
- When a program calls the fgets() function
    - OS reads the data from the keyboard, and when it see the use hit ctrl-c, sends an interrupt signal to the program.
- Some other signal events
    - illegal instructions, segmentation violations, termination orders from the os
    - floating point exceptions(division by zero or mutliplying large floating-point values)
### Default Actions
- Whenevr signal is raised (either programamatically or system generated signal), a default action is performed for some signals.

- Term - the process will terminate
- Core - the process will terminate and produce a core dump file that traces the process state at the time of termination.
- Ign - the process will ignore the signal.
- Stop - the process will stop, like with ctrl-z
- Cont - the process will continue from being stoppe

### Signal Names
- Each signal has a name, vlue and default action that a process will take in response.
    - Each signal starts with SIG
    - Available signals can be checked with the command kill -l (for listing signal names)

- Signal             Value       Action       Comment
 ------------------------------------------------------------------------------------------------------------------
 SIGHUP              1           Term       Hangup detected on controlling terminal or death of controlling process

 SIGINT              2           Term       Interrupt from keyboard

 SIGQUIT             3           Core       Quit from keyboard

 SIGILL              4           Core       Illegal Instruction

 SIGABRT             6           Core       Abort signal from abort(3)

 SIGFPE              8           Core       Floating point exception

 SIGKILL             9           Term       Kill signal

 SIGSEGV             11          Core       Invalid memory reference

 SIGPIPE             13          Term       Broken pipe: write to pipe with no readers

### Raising a Signal
- Signals can be generated by a user programmatically in addition to be sent by the OS.
- The signal handling  library <signal.h> provides capability to raise specific signals.
- a signal can be generated by calling raise() or kill() system calls.
    - raise() sends a signal to the current process
    - kill() sends a signal to a specific process.

### int raise(int sig)
- if this function is executed successfully, the signal specified in sig is generated.
- if the call us unsuccessful, raise() returns a non-zero value.

- The function raise() can only send a signal to the program that contains it
    - cannot send a signal to other processes
    - to send a signal to other processes, the system call kill() should be used.
- After raising the signal, the execution of the current process is stopped.

### alarm()
- The alarm function provides a mechanism for a process to interrupt itself in the future.
- The alarm function sets a timer
    - When the timer expires, the process recieves a signal (SIGALARM)
- If we ignore or do not catch this signal the process is terminated
    - The default action for SIGALARM is to terminate the process
- There is only one alarm clock per process
- The alarm() function wil return a value if previous alarm has been previously set.


### Handling a Signal using the signal function
- It is possible to handle or catch almost all signals in a program
- Sometimes you need to run one code when receiving a signal (handle/catch)
    - Maybe a running process has files or network connections open
    - It might want to close down and tidy up before exiting.
- It is also possible to ignored almost all signals
    - neither performing default action nor handling the signal
- A few signals cannot be ignored or handled/caught
    - SIGKILL, SIGABRT and SIGSTOP (which is why "kill 9" is the ultimate kill statement)
- Actiond peformed for signals are
    1. Default action
    2. Handle the signal
    3. Ignore the signal

### Handling/Catching a signal
- The signal handling library(<signal.h>) provides capability to catch and handle signals.
    - Signal handling can be done in 2 different ways through system calls
        - signal() or sigaction()
#### signal()
- this function is used to tell os which function it should call when  a signal is sent to a process
    - the function is used to handle a signal that is sent to it
- if there is function called foo() and one wants os to when someone sends an interrupt signal to the running process
    - pass the function name foo to the signal function as parameter.
    - foo() is called handler
- Handles are intended to be short, fast pieces of code
    - they should do just enough to deal with the signal that has been received
- signal() receives 2 args
- An integer signal number and pointer to the signal handling function
- signal() returns
    - on success the address of a function that takes an integer as argument and has no return value
    - on error returns SIG_ERR in case of error

#include <signal.h>

typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);

- The system call signal() would call registered handler(second param) upon generation of signal
- The handler (second param) can be either of
    - SIG_IGN (Ignoring the Signal)
    - SIG_DFL (Setting signal back to default mechanism)
    - or user-defined signal or function address