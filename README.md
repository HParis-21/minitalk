 minitalk
 
 
Minitalk is a project aimed at understanding how to work with signals. The project consists of two parts - client and server.

The server accepts messages from the client. At startup, the server prints its PID to the console and enters standby mode. In standby mode, it receives signals from the client.

The client sends messages to the server. It takes two parameters, the PID of the server and the message to be sent. At the same time, there is a basic validation of PID values, if the PID contains something other than digits or exceeds the values allowed for PIDs, the client will report an error.

At the same time, according to the terms of the project, no signals other than SIGUSR1 and SIGUSR2 can be used, because of this it is necessary to send messages bit by bit. Also, due to the peculiarities of the signals, it is necessary to make some kind of delay before sending signals, otherwise the signals can overlap each other, in my case this is implemented using usleep.
