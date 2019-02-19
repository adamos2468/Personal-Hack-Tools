#openssl dgst <hashing algorithm> <file>
#From File
openssl dgst -sha256 input.txt
#From Keyboard
echo -n "input" | openssl dgst -sha256