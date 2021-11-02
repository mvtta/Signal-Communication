<h2 align="center">
Minitalk

</h2>
<h6 align="center">
The purpose of this project is to code a small data exchange program using  
UNIX signals.  
by: mvaldeta  
</h6>

<h2>
</h2>

![IMG_COVER](https://64.media.tumblr.com/71a7f8f06087fc9d1ab8514122913cce/405d958ed3eacd98-da/s1280x1920/b3feb5675935dbd8edaf88cdf73f3596fe7a658b.jpg)

###### About signals | Intro

```
Linux commands are actually individual commands that are able to combine and transmit data to each other   through inter-process communication mechanisms.  
Linux provides several mechanisms for communication between processes called IPC (Inter-Process   Communication):  
Signals handling – Communicate by signal  
Pipe – Exchange by the pipe mechanism  
Message Queues – Exchange through message queues  
Shared Memory – Exchange by shared memory segment  
Communication via socket  
Synchronous communication using semaphore  

```

###### Images

| | | |
|:-------------------------:|:-------------------------:|:-------------------------:|
|<img src="https://64.media.tumblr.com/c5b04f340576ce5859ac69e6401450e3/6dab6b5c26e26f6c-30/s1280x1920/4b3d1abd358d41def4dbfb5b8d5ae40254d0cc88.jpg" width="200"> sub here|<img src="https://64.media.tumblr.com/33dbe83c6197a3cd6ad4310a0a5486bd/2176a82ead6fd58d-91/s1280x1920/beee5984a9e174ca46131c6196b61cc562744bb4.jpg" width="200"> sub here|<img src="https://64.media.tumblr.com/8da44fb8814ac1482f4a909f99f8ca41/2176a82ead6fd58d-89/s1280x1920/a16611cf91e0ba0ab41823313ff41dc4eb0cf3da.jpg" width="200"> sub here|<img src="https://64.media.tumblr.com/30b98071c89271d8b2de5f8caeb60885/27d8b878f7373bc3-45/s1280x1920/33724b1b0f3bf754bcb9b1613026e853d6c09be1.jpg" width="300"> sub here|

###### Signal handling 

```
Signals is one of the oldest methods of interprocess communication used by Unix / Linux systems. They are used to signal asynchronous events for one or more processes. Each signal can have a combination or have a signal handler available. The signal interrupts the processing of the process, forcing the system to switch to calling the signal processor immediately. At the end of signal processing, execution resumes.
Each signal is defined with an integer in /urs/include/signal.h. A list of system constants can be viewed using the kill –l command. For example :

1) SIGHUP 2) SIGINT 3) SIGQUIT 4) SIGILL 5) SIGTRAP  
6) SIGABRT 7) SIGBUS 8) SIGFPE 9) SIGKILL 10) SIGUSR1  
11) SIGSEGV 12) SIGUSR2 13) SIGPIPE 14) SIGALRM 15) SIGTERM  
16) SIGSTKFLT 17) SIGCHLD 18) SIGCONT 19) SIGSTOP 20) SIGTSTP  
21) SIGTTIN 22) SIGTTOU 23) SIGURG 24) SIGXCPU 25) SIGXFSZ  
26) SIGVTALRM 27) SIGPROF 28) SIGWINCH 29) SIGIO 30) SIGPWR  
31) SIGSYS 34) SIGRTMIN 35) SIGRTMIN+1 36) SIGRTMIN+2 37) SIGRTMIN+3  
38) SIGRTMIN+4 39) SIGRTMIN+5 40) SIGRTMIN+6 41) SIGRTMIN+7 42) SIGRTMIN+8  
43) SIGRTMIN+9 44) SIGRTMIN+10 45) SIGRTMIN+11 46) SIGRTMIN+12 47) SIGRTMIN+13  
48) SIGRTMIN+14 49) SIGRTMIN+15 50) SIGRTMAX-14 51) SIGRTMAX-13 52) SIGRTMAX-12  
53) SIGRTMAX-11 54) SIGRTMAX-10 55) SIGRTMAX-9 56) SIGRTMAX-8 57) SIGRTMAX-7  
58) SIGRTMAX-6 59) SIGRTMAX-5 60) SIGRTMAX-4 61) SIGRTMAX-3 62) SIGRTMAX-2  
63) SIGRTMAX-1 64) SIGRTMAX  

In addition, when executing the man 7 signal command,  
we can see the function as well as the instruction manual of each signal type.    

```

###### Ways to send Signals 

```
From the keyboard
Ctrl + C : sends INT signal (SIGINT) to the process, interrupt the process immediately.  
Ctrl + Z : send TSTP signal (SIGTSTP) to process, suspend.  
Ctrl + / : sends signal ABRT (SIGABRT) to process, immediately terminates process (abort).  
From the command line  
The kill command is often used to stop the execution of a process.  
The kill command can send any signal to a process, but by default it sends signal 15,  
TERM (which is the end of program). like kill -9  
 
```

###### 2 Signals means using a unit of two

| | | |
|:-------------------------:|:-------------------------:|:-------------------------:|
H E L O
each char is 1 byte | 8 bits

H | E | L | O
72 |
68 |
76 |
79 |
01001000|
01000101|
01001100|
01001111|

###### get char bit to send: 

```c 
r = ((message[k] >> i) & 1);
```

###### transform char bit back into the right position: 

```c 
c = 00000000
if (signum == SIGUSR1)
	c += (1 << (6 - i));
```

###### A table in case you need it 

| info one | info two |
|:---------:|:-----------------:|
|one | :) |
|two | :) |
|three| :) |
|four| :) |
|five| :) |

###### Code block II

```bash
$ echo The value of variable x = $x
```

###### Links 

>[LINK1](https://)  
>[LINK2](https://)  
>[LINK3](https://)  
>[LINK4](https://)  

###### Block 3 

```
Final notes. 
Sure, a real-life Epstein drive is still a few  
breakthroughs away. But the rocket-building game  
lets you pilot a fusion-propelled craft right now.
```
###### Languages used (extended version)
[![Top Langs](https://github-readme-stats.vercel.app/api/top-langs/?username=m4r11&langs_count=8&layout=compact&theme=dark&align="center")](https://github.com/m4r11/github-readme-stats)
---  

###### Badges
![shell](https://img.shields.io/badge/Shell_Script-121011?style=for-the-badge&logo=gnu-bash&logoColor=white)
![sql](https://img.shields.io/badge/MySQL-00000F?style=for-the-badge&logo=mysql&logoColor=white)
![mark](https://img.shields.io/badge/Markdown-000000?style=for-the-badge&logo=markdown&logoColor=white)

![c](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![py](https://img.shields.io/badge/Python-14354C?style=for-the-badge&logo=python&logoColor=white)
![php](https://img.shields.io/badge/PHP-777BB4?style=for-the-badge&logo=php&logoColor=white)

[![GitHub Stars](https://img.shields.io/github/stars/IgorAntun/node-chat.svg)](https://github.com/m4r11/Template-Project)
[![GitHub Issues](https://img.shields.io/github/issues/IgorAntun/node-chat.svg)](https://github.com/m4r11/Template-Project/issues)
[![Current Version](https://img.shields.io/badge/version-1.0.7-green.svg)](https://github.com/m4r11/Template-Project)
[![Live Demo](https://img.shields.io/badge/demo-online-green.svg)](https://github.com/m4r11/Template-Project)
[![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://github.com/m4r11/Template-Project?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)
![madebash](https://img.shields.io/badge/Made%20with-Bash-1f425f.svg)
