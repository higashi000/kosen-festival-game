#!bin/sh

_ip="127.0.0.1"
_port="8081"
_maxTurn="30"
_thinkingTime="10000"

cd ../Sarah/

gnome-terminal -- ./main &

sleep 1s

cd ../Mari/

gnome-terminal -- go run main.go $_ip $_port 1 30 8080 1 1 kousenFes &

sleep 1s

cd ../Kanan/

gnome-terminal -- ./kanan $_ip $_port $_maxTurn $_thinkingTime
cd ../Dia
