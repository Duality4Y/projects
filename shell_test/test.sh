#!/bin/bash
current_tty=$(tty)
needed_tty="/dev/tty1"
echo $current_tty
echo $needed_tty
if [ "$current_tty" = "$needed_tty" ];
then
	echo "succes!"
else
	echo "Fail"
fi
