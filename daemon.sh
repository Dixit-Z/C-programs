#!/bin/bash

while true
	do
		var=`date +%k`
		if [ "$var" -ge 8 ] && [ "$var" -le 20 ]; then
			rm *.avi
			./register &
			sleep 900
			kill $(pgrep register)
			mv surveillance.avi tosend.avi
			scp tosend.avi pi@192.168.1.34:Projet_Surveillance
		else
			sleep 43200
		fi
done

