#$1 -> file to verify
#$2 -> signatute
#$3 -> public key

#example openssl rsautl -verify -inkey public.pem -pubin -in signature
a="$(openssl rsautl -verify -inkey $3 -pubin -in $2)"
#example openssl dgst -sha256 file.txt
b="$(openssl dgst -sha256 $1)"
if  [ "$a" == "$b" ]
then
    echo "Veryfied!"
else
    echo "Nop verified!"
fi