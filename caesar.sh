USAGE="Usage: caesar.sh [OPTIONS] TEXT"
TEXT=""
if [[ "$1" == "-h" ]]
then
	echo $USAGE
	echo "encode or decode TEXT in caesar cipher"
	echo ""
	echo "OPTIONS:"
	echo "-e encode TEXT, default behavior"
	echo "-d decode TEXT"
	exit
elif [[ "$1" == "" ]]
then
	echo $USAGE
	echo "Try 'caesar.sh -h' for more information"
	exit
elif [[ "$1" == "-d" ]]
then
	echo $2 | tr '[b-zaB-ZA]' '[a-zA-Z]'
	exit
elif [[ "$1" == "-e" ]]
then
	TEXT=$2
else
	TEXT=$1 
fi
echo $TEXT | tr '[a-zA-Z]' '[b-zaB-ZA]'
