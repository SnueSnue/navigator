folder=$(/home/snue/code/navigator/sdu-nav $1)
parentdir=$(dirname "$1")
mypath="${parentdir}/${folder}"
cd $mypath
clear
echo "------ ${folder} ----------"
ls
