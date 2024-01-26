folder=$(/home/snue/code/sdu-nav/sdu-nav $1)
parentdir=$(dirname "$1")
mypath="${parentdir}/${folder}"
cd $mypath
clear
echo "------ ${folder} ----------"
ls
