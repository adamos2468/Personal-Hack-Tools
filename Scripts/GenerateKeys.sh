#$1 -> private key
#$2 -> public key
#Create Private Key
openssl genrsa -des3 -out $1 2048
#Create Public Key
openssl rsa -in $1 -outform PEM -pubout -out $2
#Check the primes out!
#openssl rsa -noout -text -in private.pem