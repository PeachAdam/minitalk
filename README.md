# 42 minitalk

Score: 115/100

This project is about creating communication between processes using only 2 signals.

## Usage

`make` to compile the project

In one terminal run the server `./server`

In another terminal run the client `./client [server's PID] [your message]`

## How It Works

The client program takes the message and sends it using only SIGUSR1 and SIGUSR2. In my code SIGUSR1 represents 1 and SIGUSR2 represents 2. This way we can send the message's bits to the server and the server can recreate the string with its bits.
