#$1 -> input file
#$2 -> signature path
#$3 -> key
#Hash the input
openssl dgst -sha256 $1 > file.hash
#Sign the file
openssl rsautl -sign -inkey $3 -in file.hash > $2
rm file.hash