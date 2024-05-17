clear
i=1
j=0
max=15
sp="/-\|"
echo -n "loading..."
echo -n ' '
while [ $j -lt $max ]
do
	sleep 0.1
    printf "\b${sp:i++%${#sp}:1}"
    j=$(($j+1))
done
clear
printf "OK!\n"