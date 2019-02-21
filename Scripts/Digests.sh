#$1 -> input file
#openssl dgst <hashing algorithm> <file>
#From File
openssl dgst -sha256 $1
#From Keyboard
#echo -n "input" | openssl dgst -sha256