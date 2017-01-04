while [ "$1" -ne $( date | awk '{print $4}' | sed 's/:.*//') ]
do
true
done
mplayer "alarm.mp3"

