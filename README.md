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

| 1 | 2 | 3|
|:-------------------------:|:-------------------------:| :-------------------------:|
|<img src="https://github.com/m4r11/02.minitalk/blob/main/xtra/72.png.crdownload" width="200"> | <img src="https://github.com/m4r11/02.minitalk/blob/main/xtra/How%2BSignals%2BWork%2BProcess%2BSignal%2BGenerated%2BSignal%2BMask%2BSignal%2Bdelivered.jpeg" width="200"> | <img src="https://github.com/m4r11/02.minitalk/blob/main/xtra/Scheme%2Bof%2Bsignal%2Bprocessing.jpeg" width="200">|

###### Signal handling 

```
Signals is one of the oldest methods of interprocess communication used by Unix / Linux systems.  
They are used to signal asynchronous events for one or more processes.  
Each signal can have a combination or have a signal handler available.  
The signal interrupts the processing of the process, forcing the system to  
switch to calling the signal processor immediately. At the end of signal processing,  
execution resumes.
Each signal is defined with an integer in /urs/include/signal.h.  
A list of system constants can be viewed using the kill –l command. For example :  
  
SIGHUP  
SIGINT  
SIGQUIT  
SIGILL  
SIGTRAP    
SIGABRT  
SIGBUS  
SIGFPE  
SIGKILL  
SIGUSR1    
SIGSEGV  
SIGUSR2   
  
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

each char is 1 byte | 8 bits

| H | E | L | O |
|:-------------------------:|:-------------------------:|:-------------------------:|:-------------------------:|
|72 | 68 | 76 | 79 | 
| 01001000 | 01000101 | 01001100 | 01001111 |

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
###### Usage

```bash
$ make 
$ ./server #pid will be displayed
$ ./client <pid> <message> #pref in a new window
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
