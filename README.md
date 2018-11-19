Homework 02
===========

Activity 1:
1. I have a for loop run through each argument and an if statement 
checks if the argument exists, the if statement evaluates as true, and 
the appropriate action is taken, if it is false, then the function 
displays the appropriate message
2. I used the textbook and google to find the commmands for each type of 
file
3. I found the hardest part to be reading in and manipulating the 
arguments. I overcame this issue by referencing the example on the 
reading quiz

Activity 2:
1. I used the shuf process to randomly select one of the several given 
phrases. The model was based on the example shown in class.
2. I wrote a "special" function that is called by the trap when any of 
the appropriate signals are called
3. I used the "read" command to read in a value for the question 
variable
4. The most challengeing part was figuring out to read the input in and 
have the program reprompt when receiving blank input. I overcame the 
issue by referencing the guessing game program demonstrated in class.

### Activity 3: Meeting with Oracle
1. First I wrote a shell script to try to access every port 
between 9000 and 10000 in xavier.h4x0r.space

#!/bin/sh

for ((a=9000; a<= 10000; a++)); do
   PORT=$a
   curl xavier.h4x0r.space:$PORT
done

Most ports I could not access
curl: (7) Failed to connect to xavier.h4x0r.space port 9511: 
Connection refused
curl: (7) Failed to connect to xavier.h4x0r.space port 9512: 
Connection refused
curl: (7) Failed to connect to xavier.h4x0r.space port 9513: 
Connection refused
curl: (7) Failed to connect to xavier.h4x0r.space port 9514: 
Connection refused
curl: (7) Failed to connect to xavier.h4x0r.space port 9515: 
Connection refused
curl: (7) Failed to connect to xavier.h4x0r.space port 9516: 
Connection refused
curl: (7) Failed to connect to xavier.h4x0r.space port 9517: 
Connection refused
curl: (7) Failed to connect to xavier.h4x0r.space port 9518: 
Connection refused
curl: (7) Failed to connect to xavier.h4x0r.space port 9519: 
Connection refused
curl: (7) Failed to connect to xavier.h4x0r.space port 9520: 
Connection refused
curl: (7) Failed to connect to xavier.h4x0r.space port 9521: 
Connection refused

However I found a port at 9104 that produced: 
/ Halt! Who goes there?                  \
|                                        |
| If you seek the ORACLE, you must come  |
| back and _request_ the DOORMAN at      |
| /{NETID}/{PASSCODE}!                   |
|                                        |
| To retrieve your PASSCODE you must     |
| first _find_ your LOCKBOX which is     |
| located somewhere in                   |
| ~pbui/pub/oracle/lockboxes.            |
|                                        |
| Once the LOCKBOX has been located, you |
| must use your hacking skills to        |
| _bruteforce_ the LOCKBOX program until |
| it reveals the passcode!               |
|                                        |
\ Good luck!                             /
 ----------------------------------------
   \
    \
               |    .
           .   |L  /|
       _ . |\ _| \--+._/| .
      / ||\| Y J  )   / |/| ./
     J  |)'( |        ` F`.'/
   -<|  F         __     .-<
     | /       .-'. `.  /-. L___
     J \      <    \  | | O\|.-'
   _J \  .-    \/ O | | \  |F
  '-F  -<_.     \   .-'  `-' L__
 __J  _   _.     >-'  )._.   |-'
 `-|.'   /_.           \_|   F
   /.-   .                _.<
  /'    /.'             .'  `\
   /L  /'   |/      _.-'-\
  /'J       ___.---'\|
    |\  .--' V  | `. `
    |/`. `-.     `._)
       / .-.\
 VK    \ (  `\
        `.\


and this at 9522
< Hello, who may you be? >
 ------------------------
    \
     \
      \
  ___       _____     ___
 /   \     /    /|   /   \
|     |   /    / |  |     |
|     |  /____/  |  |     |
|     |  |    |  |  |     |
|     |  | {} | /   |     |
|     |  |____|/    |     |
|     |    |==|     |     |
|      \___________/      |
|                         |
|                         |
NAME?  ___________________________________
/ Hmm... GET / HTTP/1.1?            \
|                                   |
| That name sounds familiar... what |
\ message do you have for me?       /
 -----------------------------------
    \
     \
      \
  ___       _____     ___
 /   \     /    /|   /   \
|     |   /    / |  |     |
|     |  /____/  |  |     |
|     |  |    |  |  |     |
|     |  | {} | /   |     |
|     |  |____|/    |     |
|     |    |==|     |     |
|      \___________/      |
|                         |
|                         |
MESSAGE?  _________________________________________
/ I'm sorry sugar, but I don't understand \
| this message:                           |
|                                         |
| Host: xavier.h4x0r.space:9522           |
|                                         |
| Perhaps, it wasn't meant for you.       |
|                                         |
| Why don't you go back to the DOORMAN or |
\ BOBBIT?                                 /
 -----------------------------------------
    \
     \
      \
  ___       _____     ___
 /   \     /    /|   /   \
|     |   /    / |  |     |
|     |  /____/  |  |     |
|     |  |    |  |  |     |
|     |  | {} | /   |     |
|     |  |____|/    |     |
|     |    |==|     |     |
|      \___________/      |
|                         |
|                         |



2. Then at the direction of the result of port 9104, I attempted to find my lockbox
I moved to the directory mentioned

$ cd ~pbui/pub/oracle/lockboxes

after runnin $ ls   , I realized the challenge of sorting through the many 
directories

3. I ran 
  $ find ~pbui/pub/oracle/lockboxes | grep mmacknig

which produced 

/nd.edu/user15/pbui/pub/oracle/lockboxes/dc42d557/12f78b33/bff0d0df/42eb00b5/e02a5913/mmacknig.lockbox

4. I copied the mmacknig.lockbox executable over to my home directory and after 
hours of trial, I finally arrived at the script

#!/bin/sh

for string in echo $(strings mmacknig.lockbox);
do
./mmacknig.lockbox $string;
done

which produced:

9ef09090362d0fd219701bcd62e17a1aa2fdb5f1

5. I then went entered the address in the curl statement:

curl xavier.h4x0r.space:9104/mmacknig/9ef09090362d0fd219701bcd62e17a1aa2fdb5f1

which produced the doorman who told me to verify my identity with my ID and 
passcode to bobbit

bobbit in turn gave me a message to give to the oracle

I accesseed the oracle with the command:

nc xavier.h4x0r.space 9522

and I gave him Bobbit's message and I was congratulated
# lab3
