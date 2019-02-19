#Create Private Key
openssl genrsa -des3 -out private.pem 2048
#Create Public Key
openssl rsa -in private.pem -outform PEM -pubout -out public.pem
#Check the primes out!
#openssl rsa -noout -text -in private.pem